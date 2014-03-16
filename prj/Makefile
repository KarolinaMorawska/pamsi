CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

benchmark: obj/main.o
	g++ ${LDFLAGS} -g -o benchmark obj/main.o  

obj/main.o: src/main.cpp 
	g++ -c ${CPPFLAGS} -g -o obj/main.o  src/main.cpp
	


clean:
	rm -f benchmark obj/*
