/*! \mainpage Dokumentacja zadania PAMSI LAB 1
 * 
 *
 *  \date: 1 mar 2014
 *  \author: karolina
 *  \version 0.2
 */

/*! 
* \file
* \brief Glowny plik programu.
*/
#include <iostream>
#include <dzialania.hh>
#include <cstdlib>

using namespace std;
/*! \brief Funkcja main wykonuje algorytm i sprawdza czas dzialania algorytmu.
W funkcji main wykonywane sa operacje :
-Wczytywanie pliku z danymi wejsciowym
-Dane sa mnozone razy 2 (w tej chwili wlaczany jest stoper)
-Wczytywanie pliku z danymi sprawdzajacymi
-Sprawdzanie zgodnosci 
-Stoper zostaje wylaczony i na wyjsciu programu podany zostaje czas dzialania algorytmu
*/
int main (int argc ,char **argv) {
	if (argc<4){
		cout<< "Zbyt mała liczba argumentow" ;
		return 0; }

Dzialania czasdzialania;
if(!czasdzialania.wczytajplik(argv[1]))return 0;
double czas=czasdzialania.liczczas(atoi(argv[3]));
if(!czasdzialania.porownaj(argv[2])) return 0;

cout << czasdzialania.rozmiartab() << "," << atoi(argv[3]) <<","<< czas <<"s" << endl;


}




