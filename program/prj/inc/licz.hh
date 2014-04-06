
#ifndef LICZ_HH
#define LICZ_HH

#include "tablica.hh"

/** \brief Typ danych przechowujacy rodzaj sortowania
*
*/
enum sortingType { quick, merge, intro };

/** \brief Definicja klasy Licz
*
*/
class Licz
{
  
private:
Tablica<int> tab1;
Tablica<int> tab2;


unsigned int dlugosctab;
public:
/** \brief Funkcja wczytuje dane z  pliku.
*
*/

bool wczytajplik(char *nazwapl);
void zmianarozmiaru(unsigned int nowyrozmiar);
void oblicz(sortingType type);


/** \brief
* Funkcja mierzy czas wykonywania algorytmu sortowania.
*/
double benchmark(int powtorzenia, sortingType type);

/** \brief
* \return Zwraca dlugosc tablicy.
*/
int size() { return tab1.rozmiar(); }
void quicksort(int lewy, int prawy);
void merge(int lewy , int prawy , int srodek);
void mergesort(int lewy , int prawy);
void intro(int lewy , int prawy);
void bubble(int lewy , int prawy);
};

#endif
