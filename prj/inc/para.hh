/*
 * para.hh
 *
 *  Created on: 12 kwi 2014
 *      Author: karolina
 */

#ifndef PARA_HH_
#define PARA_HH_
/*!
 * \file
 * \brief Definicja klasy Para
 *
 * Plik zawiera definicję klasy Para  ,która jest klasą podrzędną
 * i  jest ona specjalizacją klasy NODE.

*/
using namespace std;
/*!
* \brief Modeluje pojęcie Para.
* Klasa modeluje pojęcie para .
* Jej atrybutem są pola zawierające klucz i wartość.
*/
class Para {
public:
/*!
 *  \brief Inicjalizuje wartosc klucza.
 */
	int klucz;
/*!
 *  \brief Inicjalizuje wartosc wartosci.
 */
	int wartosc;
/*!
 *  \brief Konstruktor bezparametryczny.
 */
	Para(){};
/*
 *  \brief Deklaracja konstruktora z wykorzystaniem instrukci inicjujacych.
 */
	Para(int _klucz , int _wartosc)  :klucz(_klucz) ,wartosc(_wartosc){};

};



#endif /* PARA_HH_ */
