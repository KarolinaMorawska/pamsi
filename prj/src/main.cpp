/*! \mainpage Dokumentacja zadania PAMSI LAB 4
 *   
 *  \author Karolina Morawska
 *  \date 30.03.2014
 *  \version 0.2
 */


#include <iostream>
#include "tablica.hh"
#include <cstdlib>
#include <string>
#include "licz.hh"
#include "tablica.hh"

using namespace std;
/*! \brief Funkcja main wykonuje algorytm i sprawdza czas dzialania algorytmu.
W funkcji main wykonywane sa operacje :
-sprawdzenie ilosci wywolanych argumentow
-sprawdzenie poprawnosci wpisywanej nazwy przez uzytkownika i wyslanie odpowiedniego komunikatu
-wypisanie na terminalu czas dzialania algorytmu
*/
/*int main (int argc ,char **argv) {
	if (argc<4){
		cout<< "Zbyt mała liczba argumentow" ;
		return 0; }
unsigned int lpowtorzen , zmienna;
lpowtorzen=atoi(argv[3]);
zmienna=atoi(argv[2]);
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


cout << zmienna << "," << lpowtorzen <<"," << b <<"s" <<endl;


}


*/

int main(int argc, char **argv) {
  if (argc < 5 )
{ cerr << "Niewystarczajaca ilosc argumentow."<< endl;
 return 0;
}
Licz time;


string sortTyp=argv[1];
sortingType konw ;
if(sortTyp == "quick") konw = quick;
else if(sortTyp == "merge") konw = merge ;
else if(sortTyp == "intro") konw = intro ;
else { cerr << "Nie ma takiego sortowania " << endl;
return 0;}

if(!time.wczytajplik(argv[2])) return 0;
double czas= time.benchmark(atoi(argv[4]) , konw) ;


cout << time.size() << "," << atoi(argv[4]) << "," << czas <<endl;
}


