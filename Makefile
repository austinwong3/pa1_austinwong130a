CXX=g++

CXXFLAGS= -std=c++11 -Wall -g

BINARIES=prog1a prog1b

all: ${BINARIES}

prog1a: prog1a.o htable.o
	${CXX} $^ -o $@

prog1b: prog1b.o htableb.o
	${CXX} $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o
