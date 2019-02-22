# Install dependencies:
# sudo apt-get install default-jre
tools/UltimateAutomizer-linux:
	cd tools \
	&& wget https://github.com/ultimate-pa/ultimate/releases/download/v0.1.24/UltimateAutomizer-linux.zip \
	&& unzip UltimateAutomizer-linux.zip

#	&& wget https://github.com/seahorn/seahorn/archive/seahorn-llvm-38.zip \
#	&& unzip seahorn-llvm-38.zip \
#	&& mv seahorn-seahorn-llvm-38 seahorn \

# Install dependencies:
# sudo apt-get install cmake
tools/seahorn:
	cd tools \
	&& git clone https://github.com/seahorn/seahorn \
	&& cd seahorn && mkdir build && cd build \
	&& cmake -DCMAKE_INSTALL_PREFIX=run ../ \
	&& cmake --build . \
	&& cmake --build . --target extra && cmake .. \
	&& cmake --build . --target crab && cmake .. \
	&& cmake --build . --target install

# Install dependencies:
# sudo apt-get install opam libgmp-dev libmpfr-dev libntl-dev default-jre
# opam remote add sv git://github.com/zkincaid/sv-opam.git
# opam install ocamlgraph batteries cil oasis ppx_deriving Z3.4.7.1 apron ounit menhir OCRS ntl
tools/cra:
	cd tools \
	&& git clone https://github.com/zkincaid/duet \
	&& cd duet && ./configure && make

tools/icra:
	cd tools \
	&& git clone https://github.com/icra-team/icra \
	&& cd icra && make

tools/cbmc:
	mkdir tools/cbmc \
	&& cd tools/cbmc \
	&& wget https://www.cprover.org/cbmc/download/cbmc-5-11-linux-64.tgz \
	&& tar xfz cbmc-5-11-linux-64.tgz

# install dependencies
# sudo apt-get install libmpfr-dev libgmp3-dev libboost-all-dev cmake cmake-gui curl flex bison
tools/pagai:
	cd tools \
	&& git clone https://gricad-gitlab.univ-grenoble-alpes.fr/pagai/pagai.git \
	&& cd pagai && ./default-build.sh
