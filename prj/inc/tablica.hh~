#ifndef TABLICA_HH
#define TABLICA_HH


#include <cstdlib>

class Tablica
{
	int *T;
	unsigned int dlugosctab;
	
public :
	void zamienelementy(int i , int j);
	void dodajelement(int element);
	void odwrockolejnosc() ;
	void dodajelementy(const Tablica &T1);
	
	Tablica(): T(0) , dlugosctab(0) {} ;
	~Tablica () { free(T); };
	unsigned int rozmiar() const {return dlugosctab;} /*zwraca rozmiar */
	void zmianarozmiaru (unsigned int nowyrozmiar);
	int& operator[](const unsigned int b) { return T[b]; }
	const int& operator[](const unsigned int b) const {return T[b]; }
	
	Tablica& operator +(const Tablica &argument) const;
	Tablica& operator = (const Tablica &argument);
	bool operator == (const Tablica &argument) const;
	
}; 

#endif 
