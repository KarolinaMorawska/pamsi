#ifndef DZIALANIA_HH
#define DZIALANIA_HH



#include "tablica.hh"
/*! \brief Deklaracja klasy Dzialania.

* Klasa Dzialania posiada pola oraz funkcje potrzebne do wykonywania dzialan na tablicach .

*/

class Dzialania
{
private:
//! Pole przechowujace tablice numer 1.
Tablica tab1;
//! Pole przechowujace tablice numer 2.
Tablica tab2;
//! Funkcja wykonujaca dzialanie mnozenia danych z pliku x2.
void oblicz();

public:
      /*! Funkcja wczytujaca plik i sprawdzajaca porawnosc wykonania funkcji.
*/
      bool wczytajplik(char *nazwapl);
/*! Funkcja porownuje dwa pliki :
*  plik wejsciowy i sprawdzajacy , informuje o porawnosci wykonywanego *  dzialania.
*/
      bool porownaj(char *nazwapl);
/*! Funkcja mierzy czas dzialania algorytmu.
*/
      double liczczas(int iloscpowtorzen);
/*! Funkcja pomocnicza zwraca rozmiar tablicy .
*/
      int rozmiartab () { return tab1.rozmiar() ; }

};

#endif
