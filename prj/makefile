CPPFLAGS=-pedantic -Wall -Iinc
LDFLAGS=-Wall

all: benchmark

benchmark: obj/main.o obj/tablicaas.o obj/per.o
	g++ ${LDFLAGS} -g -o benchmark obj/main.o  obj/tablicahasz.o

obj/per.o: inc/per.hh 
	g++ -c ${CPPFLAGS} -g -o obj/per.o
	
obj/tablicaas.o: inc/tablicaas.hh
	g++ -c ${CPPFLAGS} -g -o obj/tablicaas.o  
clean:
	rm -f benchmark obj/*