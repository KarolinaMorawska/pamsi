#ifndef STOS2_HH
#define STOS2_HH

#include <stack>

#include "tablica.hh"
/*! \brief Szablon klasy Stos2
*    Stos ktory w przypadku przepelnienia zmienia swoj rozmiar.
* Metody analogiczne do klasy Stos.
*/
template <typename Typ>class Stos2  {

public:
/*! Metoda odczytujaca wierzcholek stosu
*/
	const Typ& top() const {return tab[dltab-1] ; }
/*! Metoda odkladajaca na stosie elementy
 */
	void push (Typ element);
/*! Metoda sciaga ze stosu element.
 */
  void  pop ();
/*! Metoda sprawdza czy stos jest pusty.
 */
  bool isempty  () const
	{ if(dltab()>=0) return false;
	else return true;}
/*! Metoda zwraca rozmiar stosu.
 */
	unsigned int size ()const {return dltab; }
/*! Konstruktor
*/
	Stos2(): dltab(0) {}
private :
// wierzcholek stosu

    Tablica<Typ> tab;
    unsigned int dltab;
	};

template <typename Typ>
void Stos2<Typ>::push (Typ element) {
	dltab++;
	if(dltab>tab.rozmiar())
	{
		if (tab.rozmiar()==0) tab.zmianarozmiaru(1);
		else tab.zmianarozmiaru(tab.rozmiar()*2);
	}
     tab[dltab-1]=element;}

template <typename Typ>
void Stos2<Typ>::pop(){
	dltab--;
	if(dltab*4<tab.rozmiar()){
		tab.zmianarozmiaru(dltab);
	}

}


#endif
