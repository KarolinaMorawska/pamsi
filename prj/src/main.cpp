/*! \mainpage Dokumentacja zadania PAMSI LAB
 *   
 *  \author Karolina Morawska
 *  \date 23.03.2014
 *  \version 0.4
 */


#include <iostream>
#include "tablica.hh"
#include <cstdlib>
#include <string>
#include "czas.hh"

using namespace std;
/*! \brief Funkcja main wykonuje algorytm i sprawdza czas dzialania algorytmu.
W funkcji main wykonywane sa operacje :
-sprawdzenie ilosci wywolanych argumentow
-sprawdzenie poprawnosci wpisywanej nazwy przez uzytkownika i wyslanie odpowiedniego komunikatu
-wypisanie na terminalu czas dzialania algorytmu
-sortowania
*/
int main (int argc ,char **argv) {
	if (argc<5){
		cout<< "Zbyt mała liczba argumentow" ;
		return 0; }
unsigned int lpowtorzen , zmienna , sort;
lpowtorzen=atoi(argv[3]);
zmienna=atoi(argv[2]);
sort=atoi(argv[4]);
double b;
if(string(argv[1])=="stos")
{

	Czasstos<Stos<int> >obiekt;
	b=obiekt.czas(lpowtorzen , zmienna);

}
else if(string(argv[1])=="stos2"){

	Czasstos<Stos2<int> >obiekt;
	b=obiekt.czas(lpowtorzen , zmienna);
}
else if(string(argv[1])=="kolejka"){

	Czaskol<Kolejka<int> >obiekt;
	b=obiekt.czas(lpowtorzen , zmienna);
}

else if (string(argv[1])=="stoslista") {

		Czasstos<Stol<int> >obiekt;
		b=obiekt.czas(lpowtorzen , zmienna);
}

else { cerr <<"nie ma takiej nazwy " <<endl;
  return 0;
}


cout << zmienna << "," << lpowtorzen <<"," << b <<"s" << sort <<endl;


}


