#ifndef TABLICA_HH
#define TABLICA_HH

#include <iostream>
#include <fstream>
#include <cstdlib>
/*! \brief Szablon klasy Tablica.
 *
 *  Klasa Tablica posiada pola oraz funkcje potrzebne do wykonywania dzialan  na tablicach.
 */
template<typename Typ> class Tablica {
public:
//! Pole przechowujace wskaznik do tablicy.
	Typ *T;
//! Pole przechowujace dlugosc tablicy.
	unsigned int dlugosctab;

	/*! Funkcja sluzaca do zamiany elementow.
	 */
	void zamienelementy(int i, int j);
	/*! Funkcja dodaje element na tablice.Wykorzystuje funkcje pomocnicza zmiana rozmiaru.
	 */
	void dodajelement(Typ element);
	/*! Funkcja odwraca kolejnosc w tablicy.
	 */
	void odwrockolejnosc();
	/*! Funkcja laczy ze soba dwie tablice.
	 */
	void dodajelementy(const Tablica<Typ> &T1);
	/*! Konstruktor klasy Tablica.
	 */
	Tablica() :
			T(0), dlugosctab(0) {
	}
	;
	/*! Destruktor klasy Tablica.
	 */
	~Tablica() {
		free(T);
	}
	;
	/*! Funkcja pomocnicza zwraca dlugosc tablicy.
	 */
	unsigned int rozmiar() const {
		return dlugosctab;
	}
	/*! Funkcja pomocnicza sluzaca do zmiany rozmiaru .
	 */
	void zmianarozmiaru(unsigned int nowyrozmiar);

	/*! Przeciazenie operatora indeksujacego
	 */
	Typ& operator[](const unsigned int b) {
		return T[b];
	}
	/* Przeciazenie operatora indeksujacego
	 */
	const Typ& operator[](const unsigned int b) const {
		return T[b];
	}
	/*! Przeciazenie operatora dodawania.
	 */
	Tablica<Typ>& operator +(const Tablica<Typ> &argument) const;
	/*! Przeciazenie operatora przypisywania.
	 */
	Tablica<Typ>& operator =(const Tablica<Typ> &argument);
	/*! Przeciazenie operatora porownania.
	 */
	bool operator ==(const Tablica<Typ> &argument) const;
	/*! Funkcja wykonujaca algorytm szybkiego sortowania .*/
	void quicksort(int lewy, int prawy);
	/*  Funkcja wczytuje dane z pliku*/
	bool wczytajplik(char *nazwapl);
	/* Funkcja ktora wyswietla tablice */
	void wyswietl();
	/* Funkcja scalanie , uzywana przy sortowaniu mergesort.*/
	void merge(int lewy, int prawy, int srodek);
	/* Funkcja soryujaca poprzez scalanie*/
	void mergesort(int lewy, int prawy);
	/* Funckja sortowania metoda introspektywna */
	void intro(int lewy, int prawy);
	/* Funkcja sortowania babelkowego , pomocnicza przy sortowaniu introspektywnym */
	void bubble(int lewy, int prawy);
};

#endif 
