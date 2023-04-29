# DAMER 2.0

a concurrent program model checking tool based on PDNet.

This project is an automatic tool for building a PDNet model of a concurrent program, and alleviate the state-explosion by PDNet slicing.
The concurrent program using POSIX threads that must satisfy ANSI-C grammar.


## Environment
- Ubuntu or Deepin with Linux Kernel.

## Installation

Pre-installed software: g++,gcc, graphviz and tcmalloc. 
You should make sure they are installed in system.

### Install Graphviz.

If you have not installed Graphviz yet, use the following command-line to install Graphviz

$ sudo apt-get install graphviz

### Install tcmalloc. 

There are two ways to install tcmalloc:

#### 1. Use our script to install tcmalloc automatically.

You can use the following command-lines in this directory.

$ cd tcmalloc \
$ chmod +x install.sh \
$ sudo ./install.sh

It will take a few minutes if everything goes well.

#### 2. Use command-lines.

if you have not installed tcmalloc yet, use the following command-lines to install tcmalloc

First, you should install m4

$ wget http://mirrors.kernel.org/gnu/m4/m4-1.4.13.tar.gz \
$ tar -xzvf m4-1.4.13.tar.gz \
$ cd m4-1.4.13 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

if there is an error occurred, use the following commands:

$ sed -i 's/IO_ftrylockfile/IO_EOF_SEEN/' lib/*.c \
$ echo "#define _IO_IN_BACKUP 0x100" >> lib/stdio-impl.h \
$ sudo make install \
$ cd ..

Second, you should install autoconf

$ wget http://mirrors.kernel.org/gnu/autoconf/autoconf-2.65.tar.gz \
$ tar -xzvf autoconf-2.65.tar.gz \
$ cd autoconf-2.65 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Third, you should install automake

$ wget http://mirrors.kernel.org/gnu/automake/automake-1.11.1.tar.gz \
$ tar xzvf automake-1.11.1.tar.gz \
$ cd automake-1.11.1 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Forth, you should install libtool

$ wget http://mirrors.kernel.org/gnu/libtool/libtool-2.2.6b.tar.gz \
$ tar xzvf libtool-2.2.6b.tar.gz \
$ cd libtool-2.2.6b \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Fifth, you should install libunwind

$ wget http://download.savannah.gnu.org/releases/libunwind/libunwind-1.1.tar.gz \
$ tar -zxvf libunwind-1.1.tar.gz \
$ cd libunwind-1.1 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Finally, you can install google-perftools

get the newest google-perftools-2.x.tar.gz from https://github.com/gperftools/gperftools/releases , then do:

$ tar -zxvf gperftools-2.x.tar.gz \
$ cd gperftools-2.x \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ su \
$ echo "/usr/local/lib" > /etc/ld.so.conf

Note: If there are any problems for installing tcmalloc, you can use the Mac branch for testing. 
The relevant use of tcmalloc is removed from the Mac branch.

## Usage

- The 'benchmarks' folder is where we put the benchmarks of the manuscript. 
- The 'test' folder is where you put the test files.
- Those *.c files is the original program files.

First, you should switch to the 'build' directory:

$ cd build

To run DAMER, type the following command in 'build' directory:

$ chmod +x PDNet2_0

$ chmod +x ../exe/cia

$ ./PDNet2_0 [-showtree] [-showcpn] (-compare|-directbuild|-slice) ../test/(filename)

Tips: The contents in parentheses are required

For example:

$ ./PDNet2_0 -PDNetSlice ../test/*.c

$ ./PDNet2_0 -NoDependence -ProgramSlice -property ../test/*.xml ../test/*.c

More command can be seen with:

$ ./PDNet2_0 -help

## Script

You can set PYTHON script run_test.py in the debug directory (build) to batch the testing files.

We provide a scripts to run the experiments in the manuscript and reproduce the experimental results.

$ chmod +x run_test.py

$ sudo ./run_test.py

After execution, csv files are the original result files in the 'build' directory.

Note: 
formula-F.xml in the 'benchmark' directory is the safety property for reach benchmark.  
The XML files with the same name for each benchmark (i.e., *.xml) are the constraint properties.

