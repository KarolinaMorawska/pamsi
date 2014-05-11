/*
 * main.cpp
 *
 *  Created on: 27 kwi 2014
 *      Author: karolina
 */
/*! \mainpage Dokumentacja zadania lab7
 *
 *  \date : 30 kwi 2014
 *  \author: Karolina Morawska
 *  \version: 0.1
 */
/*!
\file
\brief Glowny plik programu.
*/
#include "Graf.h"

/*! 
\brief Główna funkcja programu
 *  W funkcji main:
 *  -tworzona jest zmienna typu Graf
 *  -dodana do niej zostaja para wierzcholkow
 *  -dodanie krawedzi
 *  -sprawdzenie poprawnosci dzialania funkcji sasiad
 (wypisanie sasiadujacych wierzchoklow z wybranym)
 *  -sprawdzenie poprawnosci dzialania funkcji usun krawedz
 *  -sprawdzenie zawartosci tablicy
 */


int main(){

	Graf zmienna;
	zmienna.Dodajw(2);
zmienna.Dodajw(4);
zmienna.Dodajk(12,2,4);
zmienna.Dodajw(6);
zmienna.Dodajk(10 ,2,6);
zmienna.Sasiad(2);
zmienna.Usunk(2,6);
zmienna.Sasiad(2);
}
