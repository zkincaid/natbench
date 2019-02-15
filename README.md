# pavmark

pavmark is a benchmark suite for Program Analysis and Verification.  The goal is of the suite is to collect a diverse range of *naturally-occurring* reasoning tasks.

# Tags

pavmark features a tagging system to enable easy subsetting of the suite (e.g., when benchmarking a new technique for generating integer invariants, we may select the set of benchmarks that are both safe and require only reasoning about integers).

- *integer*: requires only reasoning about integers (e.g., no memory)
- *linear*: requires only reasoning about linear arithmetic.
- *recursive*: contains recursive features
- *array*: requires reasoning about arrays
- *safe*: all assertions are expected to pass
- *unsafe*: at least one assertion is expected to fail

## Description tags

- *resource-bound*: the benchmark requires proving an upper or lower bound on the usage of some resource (e.g., space, time)
- *relational*: the benchmark requires proving relational program property (e.g., equivalence)

# Use

The `pavmark.py` script can be used to query the benchmark suite.

 - `python pavmark.py list <query>` prints a list of benchmarks whose tags match `<query>`.  Queries are boolean expressions over tags (e.g., `integer and safe and not recursive`, or `not linear and (resource-bound or relational)`).  The query `*` matches any benchmark.
 - `python pavmark.py run <tool> <query>` runs the tool `<tool>` on all benchmarks matching `<query>`

The included makefile can be used to download and build several software verification tools.  The targets of the makefile (and associated `<tool>` for the `pavmark.py` script) are:

 - `tools/seahorn`: [Seahorn](http://seahorn.github.io)
 - `tools/cbmc` [CBMC](https://www.cprover.org/cbmc/)
 - `tools/UltimateAutomizer-linux`: [UltAuto](https://monteverdi.informatik.uni-freiburg.de/tomcat/Website/?ui=tool&tool=automizer)
 - `tools/cra`: [CRA](https://github.com/zkincaid/duet)
 - `tools/irca`: [ICRA](https://github.com/icra-team/icra)
