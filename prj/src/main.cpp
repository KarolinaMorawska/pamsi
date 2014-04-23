/*! \mainpage Dokumentacja zadania lab6
 *
 *  \date : 5 kwi 2014
 *  \author: Karolina Morawska
 *  \version: 0.1
 */
#include <iostream>
#include "tablicaas.hh"
#include "tree.hh"
#include "czas.hh"
using namespace std;
#include<time.h>
template<typename K, typename W>

int Tablicaas<K, W>::zmienna = 0;
/*! \brief Główna funkcja programu
 *  W funkcji main:
 *  -tworzona jest tablica asocjacyjna
 *  -dodana do niej zostaje para (klucz, wartosc)
 *  -sprawdzenie poprawnosci dzialania funkcji pobierz
 *  -sprawdzenie poprawnosci dzialania funkcji usun4
 *  -sprawdzenie zawartosci tablicy
 */

int main() {

	Zegar zeg_hasz, zeg_tree;
	/*zeg_tree.Start();			// Rozpoczęcie pracy zegara
	Tree tab;
	Para zmienna(1, 5), tmp(4, 8), t(0, 4), a(8, 8);
	for (int i=0; i<ROZMIAR;i++){
	 tab.dodaj(Para(zmienna));	// Wczytujemy pliki do DRZEWA
	 // ...
	 tab.wyszukaj(1);}
	 zeg_tree.Koniec();		// Koniec pracy zegara
	 zeg_tree.Wynik();		// Wynik pracy zegara
*/

	 Tablicaas <string , int> taa;
	 per <string,int> para("napis", 10);

	 zeg_hasz.Start();		// Rozpoczynamy pracę zegara
	 for (int i=0; i<ROZMIAR;i++){
	 taa.dodaj(para);
	 taa.pobierz("napis");}

	 zeg_hasz.Koniec();			// Koniec pracy zegara
	 zeg_hasz.Wynik();			// Wynik pracy zegara


	cin.get();

	return 0;
}

