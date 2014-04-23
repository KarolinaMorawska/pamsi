/*
 * per.hh
 *
 *  Created on: 5 kwi 2014
 *      Author: karolina
 */

#ifndef PER_HH_
#define PER_HH_


/*!
 * \file 
 * \brief Definicja szablonu klasy Per
 *
 * Plik zawiera definicję szablonu klasy Per ,która jest klasą podrzędną i  jest ona specjalizacją klasy Tablicaas.

*/
#include <string>
#include <iostream>

using namespace std;

/*! 
* \brief Modeluje pojęcie per.
* Klasa modeluje pojęcie per(para) .
* Jej atrybutem są pola zawierające klucz i wartość.
*/

template<typename K , typename W >
class per {
public:
/*!
 * \brief Inicjalizuje wartosc klucz.
*/ 
	K key;
/*! 
 * \brief Inicjalizuje wartosc zmiennej wartość.
*/
	W *wartosc;
	per (K _key , W _wartosc){
		key=_key;
		wartosc=new W;
		*wartosc=_wartosc;

}
	/*!
	 *  \brief Konstruktor klasy per.
	 */
	per(){
		wartosc=new W;
	}

};



#endif /* PER_HH_ */
