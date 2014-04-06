#ifndef KOLEJKA_HH
#define KOLEJKA_HH

#include <list>

/*! \brief Szablon klasy Kolejka
* Klasa zaimplementowana na liscie

*/
template <typename Typ> class Kolejka
{
	std::list<Typ> lista;

public:
/*! Metoda zwraca rozmiar listy
*/
	unsigned int size() const {return lista.size(); }
/*! Metoda sprawdza zawartosc listy 
*/
    bool isempty  () const
  	{ return lista.empty();}
/*! Metoda sprawdzajaca wierzcholek
*/
    const Typ& top() const {return lista.back(); }

/*! Metoda ktora dodaje do kolejki elementy
 */
void enqueue (const Typ element){
	lista.push_back(element);
}
/*! Metoda ktora sciaga element ze stosu
*/
void  dequeue ()
   {
	lista.pop_front();
  }


};




#endif

