#ifndef TABLICA_HH
#define TABLICA_HH

/*! 
* \file
* \brief Definicja klasy Tablica.
*/
#include <cstdlib>
/*! \brief Deklaracja klasy Tablica.
*
*  Klasa Tablica posiada pola oraz funkcje potrzebne do wykonywania dzialan  na tablicach.
*/
class Tablica
{
/*!
* \brief  Pole przechowujeca wskaznik do tablicy.
*/
int *T;
/*!
* \brief  Pole przechowujace dlugosc tablicy.
*/
	unsigned int dlugosctab;
	
public :
  /*! 
* \brief Funkcja sluzaca do zamiany elementow.
*/
	void zamienelementy(int i , int j);
/*! 
* \brief Funkcja dodaje element na tablice.Wykorzystuje funkcje pomocnicza *    zmiana rozmiaru.
*/
	void dodajelement(int element);
/*!
* \brief Funkcja odwraca kolejnosc w tablicy. 
*/
	void odwrockolejnosc() ;
/*! 
* \brief Funkcja laczy ze soba dwie tablice.
*/
	void dodajelementy(const Tablica &T1);
/*! 
* \brief Konstruktor klasy Tablica.
*/
	Tablica(): T(0) , dlugosctab(0) {} ;
/*! 
* \brief Destruktor klasy Tablica.
*/
	~Tablica () { free(T); };
/*! 
* \brief Funkcja pomocnicza zwraca dlugosc tablicy.
*/
	unsigned int rozmiar() const {return dlugosctab;} 
/*! 
* \brief Funkcja pomocnicza sluzaca do zmiany rozmiaru .
*/
	void zmianarozmiaru (unsigned int nowyrozmiar);
/*! 
*\ brief Przeciazenie operatora indeksujacego.
*/
	int& operator[](const unsigned int b) { return T[b]; }
	const int& operator[](const unsigned int b) const {return T[b]; }
/*!
* \brief  Przeciazenie operatora dodawania.
*/
	Tablica& operator +(const Tablica &argument) const;
/*! 
* \brief Przeciazenie operatora przypisywania.
*/
	Tablica& operator = (const Tablica &argument);
/*! 
* \brief Przeciazenie operatora porownania.
*/
	bool operator == (const Tablica &argument) const;
	
}; 

#endif 
