CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

benchmark: obj/main.o obj/tablica.o obj/dzialania.o
	g++ ${LDFLAGS} -o benchmark obj/main.o obj/tablica.o obj/dzialania.o

obj/main.o: src/main.cpp inc/dzialania.hh
	g++ -c ${CPPFLAGS} -o obj/main.o  src/main.cpp
	
obj/dzialania.o: src/dzialania.cpp inc/dzialania.hh
	g++ -c ${CPPFLAGS} -o obj/dzialania.o  src/dzialania.cpp
	
obj/tablica.o: src/tablica.cpp inc/tablica.hh
	g++ -c ${CPPFLAGS} -o obj/tablica.o  src/tablica.cpp
    
clean:
	rm -f benchmark obj/*
