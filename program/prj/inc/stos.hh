#ifndef STOS_HH
#define STOS_HH

#include <stack>

#include "tablica.hh"
/*! \brief Szablon klasy stos.
*  Klasa stos wykonuja dzialania :
        -odklada elementy na stos 
        -sciaga element ze stosu
        -zwraca rozmiar
        -sprawdza czy stos jesyt pusty
        
*/
template <typename Typ>class Stos  {

public:
/*! Metoda zwraca szczyt stosu
*/
	const Typ& top() const {return tab[tab.rozmiar()-1] ; }
/*! Metoda odkladajaca na stosie elementy
 */
	void push (Typ element);
/*! Metoda sciaga ze stosu element.
 */
  void  pop ();
/*! Metoda sprawdza czy stos jest pusty.
 */
  bool isempty  () const
	{ if(tab.rozmiar()>=0) return false;
	else return true;}
/*! Metoda zwraca rozmiar stosu.
 */
	int size ()const {return tab.rozmiar(); }
private :
//! Pole przechowujace tablic 
    Tablica<Typ> tab;
	};

template <typename Typ>
void Stos<Typ>::push (Typ element) {
	tab.zmianarozmiaru(tab.rozmiar()+1);
	tab[tab.rozmiar()-1]=element;
}
template <typename Typ>
void Stos<Typ>::pop(){
	tab.zmianarozmiaru(tab.rozmiar()-1);

}



#endif
