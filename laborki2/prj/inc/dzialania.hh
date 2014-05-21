#ifndef DZIALANIA_HH
#define DZIALANIA_HH

#include "tablica.hh"
/*! 
* \file
* \brief Definicja klasy Dzialania
*/

/*! 
\brief Deklaracja klasy Dzialania.

* Klasa Dzialania posiada pola oraz funkcje potrzebne do wykonywania dzialan na tablicach .

*/

class Dzialania
{
private:
/*! 
* \brief Pole przechowujace tablice numer 1.
*/
Tablica tab1;
/*!
* \brief Pole przechowujace tablice numer 2.
*/
Tablica tab2;
/*! 
* \brief Funkcja wykonujaca dzialanie mnozenia danych z pliku x2.
*/
void oblicz();
/*! 
* \brief Funkcja mierzy czas dzialania algorytmu.
*/
      double liczczas(int iloscpowtorzen);
public:
      /*!
*\brief Funkcja wczytujaca plik i sprawdzajaca porawnosc wykonania funkcji.
*/
      bool wczytajplik(char *nazwapl);
/*! 
* \brief Funkcja porownuje dwa pliki :
*  plik wejsciowy i sprawdzajacy , informuje o porawnosci wykonywanego *  dzialania.
*/
      bool porownaj(char *nazwapl);

/*! 
* \brief Funkcja pomocnicza zwraca rozmiar tablicy .
*/
      int rozmiartab () { return tab1.rozmiar() ; }

};

#endif
