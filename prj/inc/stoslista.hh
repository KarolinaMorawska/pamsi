#ifndef STOSLISTA_HH
#define STOSLISTA_HH



#include <list>
/*! \brief Szablon klasy Stol.
*
*  Klasa Stol posiada pola oraz funkcje potrzebne do wykonywania dzialan  na liscie.
*/
template <typename Typ> class Stol
{
	std::list<Typ> lista;

public:
/*! Metoda zwraca rozmiar listy
*/
	unsigned int size() const {return lista.size(); }
/*! Metoda dodaje element */
    void push (Typ element)
    {
     lista.push_back(element);
    }
/*! Metoda sciaga element z listy */
    void pop(){
    	lista.pop_back();
    }
/*! Metoda sprawdza zawartosc listy
*/
    bool isempty  () const
  	{ return lista.empty();}
/*! Metoda sprawdza wierzchlek stosu.
*/
    const Typ& top() const {return lista.back(); }
};




#endif
