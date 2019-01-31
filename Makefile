all: prog1a

prog1a: prog1a.cpp htable.o
	g++ -g -o prog1a prog1a.cpp htable.o

htable.o: htable.cpp htable.h
	g++ -c htable.cpp htable.h

