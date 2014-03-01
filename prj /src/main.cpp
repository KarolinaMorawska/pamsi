/*
 * main.cpp
 *
 *  Created on: 1 mar 2014
 *      Author: karolina
 */


#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main (int argc ,char **argv) {
	if (argc<3){
		cout<< "Zbyt mała liczba argumentow" ;
		return 0; }

ifstream plik;
plik.open(argv[1]);

if( !plik.good() ){

cout << "Nie otworzono pliku "
        return 0;
}
int rozmiar;
plik>>rozmiar;

int *b=new int[rozmiar]; // tablica
for (int i=0; i<rozmiar ;i++){
	plik>>b[i];
}
clock_t tmp;
tmp=clock();

for (int i=0; i<rozmiar ;i++){
 b[i]=b[i]*2;
}

tmp=clock()-tmp;


ifstream pliks;
pliks.open(argv[2]);

if( !pliks.good() ) {

cout << "Nie otworzono pliku sprawdzajacego "
        return 0; }

int rozmiarek;
pliks>>rozmiarek;

if(rozmiar!=rozmiarek){
	cout << "Rozmiary plikow nie zgadzaja sie "
		return 0; }

	for(int i=0; i<rozmiarek;i++){
		int d;
	pliks>>d;
	if(d!=b[i]){
		cout <<"Porownywane wartosci nie zgadzaja sie !"
		return 0; }

	}
	cout << ((double)tmp)/CLOCKS_PER_SEC<<endl;


}
