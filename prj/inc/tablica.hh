#ifndef TABLICA_HH
#define TABLICA_HH


#include <cstdlib>
/*! \brief Deklaracja klasy Tablica.
*
*  Klasa Tablica posiada pola oraz funkcje potrzebne do wykonywania dzialan  na tablicach.
*/
class Tablica
{
//! Pole przechowujeca wskaznik do tablicy.
	int *T;
//! Pole przechowujace dlugosc tablicy.
	unsigned int dlugosctab;
	
public :
  /*! Funkcja sluzaca do zamiany elementow.
*/
	void zamienelementy(int i , int j);
/*! Funkcja dodaje element na tablice.Wykorzystuje funkcje pomocnicza *    zmiana rozmiaru.
*/
	void dodajelement(int element);
/*! Funkcja odwraca kolejnosc w tablicy. 
*/
	void odwrockolejnosc() ;
/*! Funkcja laczy ze soba dwie tablice.
*/
	void dodajelementy(const Tablica &T1);
/*! Konstruktor klasy Tablica.
*/
	Tablica(): T(0) , dlugosctab(0) {} ;
/*! Destruktor klasy Tablica.
*/
	~Tablica () { free(T); };
/*! Funkcja pomocnicza zwraca dlugosc tablicy.
*/
	unsigned int rozmiar() const {return dlugosctab;} 
/*! Funkcja pomocnicza sluzaca do zmiany rozmiaru .
*/
	void zmianarozmiaru (unsigned int nowyrozmiar);
/*! Przeciazenie operatora indeksujacego.
*/
	int& operator[](const unsigned int b) { return T[b]; }
	const int& operator[](const unsigned int b) const {return T[b]; }
/*! Przeciazenie operatora dodawania.
*/
	Tablica& operator +(const Tablica &argument) const;
/*! Przeciazenie operatora przypisywania.
*/
	Tablica& operator = (const Tablica &argument);
/*! Przeciazenie operatora porownania.
*/
	bool operator == (const Tablica &argument) const;
	
}; 

#endif 
