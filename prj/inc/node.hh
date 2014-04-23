/*
 * node.hh
 *
 *  Created on: 12 kwi 2014
 *      Author: karolina
 */

#ifndef NODE_HH_
#define NODE_HH_
/*!
 * \file
 * \brief Definicja klasy NODE(wezel)
 *
 * Plik zawiera definicję klasy NODE  ,która jest klasą podrzędną
 * i  jest ona specjalizacją klasy Tree.

*/
#include "para.hh"
#include <cstdlib>
/*!
* \brief Modeluje pojęcie NODE ,czyli wezel.
* Klasa modeluje pojęcie node .
* Jej atrybutem są pola zawierające wskaźnik na lewy ,prawy węzeł i wartość.
*/

class NODE {
public :
/*
 *  \brief Inicjalizuje wskaznik na lewy wezel
 */
	NODE *left;
/*
 *  \brief Inicjalizuje wskaźnik na prawy wezel.
 */
	NODE *right;
/*
 *  \brief Inicjalizuje wartosc obiektu typu Para.
 */
	Para value;
/*
 * \brief Inicjalizuje konstruktor.
 */

	NODE(){
		left=NULL;
		right=NULL;
	}

};



#endif /* NODE_HH_ */
