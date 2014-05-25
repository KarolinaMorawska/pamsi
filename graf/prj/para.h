/*
 * para.h
 *
 *  Created on: 27 kwi 2014
 *      Author: karolina
 */

#ifndef PARA_H_
#define PARA_H_
/*!
 * \file
 * \brief Definicja klasy para
 *
 * Plik zawiera definicję klasy para
 * Jest to klasa pomocnicza wykorzystywana w klasie Graf.
 */
/*!
 * \brief Modeluje pojęcie para.
 * Klasa modeluje pojęcie para .
 * Jej atrybutem sa pola zawierajace numer wierzcholka i jego wage.
 */
class para {
public:
	/*!
	 * \brief Pomocnicza zmienna okreslajaca funkcje G.
	 */
	double G;
	/*!
	 * \brief Pomocnicza zmienna okreslajaca funkcje F(suma funkcji G i H).
	 */
	double F;
	/*!
	 * \brief Pomocnicza zmienna okreslajaca funkcje H.
	 */
	double H;
	/*!
	 *  \brief Definicja konstruktora.
	 */
	para();
	/*!
	 *  \brief Definicja konstruktora wirtualnego.
	 */
	virtual ~para();
	/*!
	 *  \brief Zmienna zawierajace wage wierzcholka.
	 */
	int waga;
	/*!
	 *  \brief Zmienna zawierajaca numer wierzcholka ktory jest sasiadem.
	 */
	int numer; //numer wierzcholka ktory jest sasiadem
	/*!
	 *  \brief Inicjalizuje konstruktor.
	 */
	para(int _waga, int _numer) {
		waga = _waga;
		numer = _numer;
	}
};

#endif /* PARA_H_ */
