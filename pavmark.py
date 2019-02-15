import os
import sys
import subprocess
from subprocess import Popen, PIPE
import time
from pyparsing import *
from functools import reduce
from threading import Timer


# Time limit, in seconds
time_limit = 30

suppress_stderr = True

directories = ["micro"]

class Tag:
    def __init__(self, name):
        self.tag = name
    def match(self, tags):
        return self.tag in tags
class And:
    def __init__(self, left, right):
        self.left = left
        self.right = right
    def match(self, tags):
        return self.left.match(tags) and self.right.match(tags)
class Or:
    def __init__(self, left, right):
        self.left = left
        self.right = right
    def match(self, tags):
        return self.left.match(tags) or self.right.match(tags)
class Not:
    def __init__(self, expr):
        self.expr = expr
    def match(self, tags):
        return not self.expr.match(tags)
class Wildcard:
    def __init__(self):
        pass
    def match(self, tags):
        return True

def mk_not(toks):
    return Not(toks[0][1])
def mk_and(toks):
    return [reduce(And, toks[0][0::2])]
def mk_or(toks):
    return [reduce(Or, toks[0][0::2])]
def mk_tag(toks):
    return Tag(str(toks[0]))

tag = Regex("[a-zA-Z][a-zA-Z0-9-]*")
tag.setParseAction(mk_tag)
wildcard = Keyword("*")
wildcard.setParseAction(lambda toks : Wildcard())
tagpat = infixNotation(tag | wildcard,
                       [("not", 1, opAssoc.RIGHT, mk_not),
                        ("and", 2, opAssoc.LEFT, mk_and),
                        ("or", 2, opAssoc.LEFT, mk_or)])


# Retrieve the list of tags for a file
def get_tags(filename):
    lines = open(filename).readlines()
    for line in lines:
        if line.startswith("// tags:"):
            return line[9:-1].replace(" ","").split(",")

    # No tags line
    print("Warning: no tags for `%s'" % filename)
    return []

def file_matches(filename, tag):
    tags = get_tags(filename)
    return tag in tags

def match_tags(pat):
    return [ ("%s/%s" % (directory, fn))
             for directory in directories
             for fn in os.listdir(directory)
             if fn.endswith(".c") and pat.match(get_tags(directory+"/"+fn)) ]

def print_usage():
    print("""Usage: python natbench.py list <tag-pattern>
                          run <tool> <tag-pattern>""")

class Timeout(Exception):
    pass

def raise_timeout(signum, frame):
    raise Timeout("")

if __name__ == "__main__":
    if (len(sys.argv) == 3 and sys.argv[1] == "list"):
        pat = tagpat.parseString(sys.argv[2],parseAll=True)[0]
        for fn in match_tags(pat):
            print(fn)
    elif (len(sys.argv) == 4 and sys.argv[1] == "run"):
        pat = tagpat.parseString(sys.argv[3],parseAll=True)[0]
        for fn in match_tags(pat):
            sys.stdout.write(fn.ljust(40))

            cmd = "timeout %d ./run_%s.sh %s" % (time_limit, sys.argv[2], fn)

            start = time.time()
            proc = Popen(cmd, stdout=PIPE, stderr=PIPE, shell=True)
            stdout, stderr = proc.communicate()
            elapsed = time.time() - start

            if proc.returncode == 124:
                # proc was killed by timeout
                elapsed = time_limit
                result = "timeout"
            else:
                result = stdout.decode("ascii")[:-1]

            print("%s %f" % (result.ljust(10), elapsed))
            if not (suppress_stderr) and len(stderr) > 0:
                print("Error on %s" % fn)
                print(stderr)
                print(stderr.decode("ascii")[:-1])
                
    else:
        print_usage ()

