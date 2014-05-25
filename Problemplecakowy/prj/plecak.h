/*
 * plecak.h
 *
 *  Created on: 23 maj 2014
 *      Author: karolina
 */

#ifndef PLECAK_H_
#define PLECAK_H_
/*!
 * \file
 * \brief Definicja klasy plecak
 *
 * Plik zawiera definicję klasy Graf
 * Jest to klasa glowna programu.
*/
#include <vector>
#include <algorithm>

using namespace std;
/*!
* \brief Modeluje pojęcie plecak.
* Jej atrybutem jest wektor ktory zawiera elementy dodawane do plecaka.
*/
class plecak {
public:
/*!
 *  \brief Zmienna wektor ktora przechowuje pare:
 *  waga i wartosc elementu.
 */
	vector<pair<int,int> > T;
/*!
 *  \brief Zmienna wektor ktora przechowuje maksymalna wartosc jaka mozna wlozyc do plecaka.
 */
	vector<int> maxvalue;
/*!
 *  \brief Zmienna wektor, przechowuje ostatni dodany element.
 */
	vector<int> lastitem;
/*!
 *  \brief Metoda glowna programu, oblicza jak najlepsze zapelnienie plecaka.
 *  Jej atrybutami są wektor T i max pojemnosc plecaka.
 */
	void oblicz(vector<pair<int,int> > T,int maxpoj);
/*!
 *  \brief Metoda sluzy do zwracania wartosci przedmiotu.
 */
	int wartosc(int poj);
/*!
 *  \brief Pomocniczy metoda zwracajaca elementy ktorymi zostal zapelniony plecak.
 */
	vector<pair<int,int> > przedmioty(int poj);
/*!
 *  \brief Inicjalizuje konstruktor.
 */
	plecak();
/*!
 *  \brief Inicjalizuje wirtualny konstruktor.
 */
	virtual ~plecak();
};

#endif /* PLECAK_H_ */
