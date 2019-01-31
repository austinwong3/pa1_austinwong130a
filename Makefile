CXX=g++

CXXFLAGS= -std=c++11 -Wall -g

BINARIES=prog1a

all: ${BINARIES}

prog1a: prog1a.o htable.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
