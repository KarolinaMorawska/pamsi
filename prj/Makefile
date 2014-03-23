CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

benchmark: obj/main.o obj/tablica.o
	g++ ${LDFLAGS} -g -o benchmark obj/main.o  obj/tablica.o

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -g -o obj/main.o  src/main.cpp
	
obj/tablica.o: src/tablica.cpp inc/tablica.hh
	g++ -c ${CPPFLAGS} -g -o obj/tablica.o  src/tablica.cpp 
clean:
	rm -f benchmark obj/*
