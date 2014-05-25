/*
 * main.cpp
 *
 *  Created on: 27 kwi 2014
 *      Autor: karolina
 */
/*! \mainpage Dokumentacja zadania lab8
 *
 *  \date : 20 maj 2014
 *  \author: Karolina Morawska
 *  \version: 0.1
 */
/*!
* \file
* \brief Glowny plik programu
*/
#include "Graf.h"
#include <ctime>
/*! \brief Główna funkcja programu
 *  W funkcji main:
 *  -tworzona jest zmienna typu Graf
 *  -dodana do niej zostaja para wierzcholkow
 *  -dodanie krawedzi
 *  -sprawdzenie poprawnosci dzialania funkcji sasiad
 (wypisanie sasiadujacych wierzchoklow z wybranym)
 *  -sprawdzenie poprawnosci dzialania funkcji usun krawedz
 *  -sprawdzenie zawartosci tablicy
 * -zmierzenie czasu dzialania funkcji DFS,BFS i astar
 */

int main() {

	Graf graf1, graf2;
	/*zmienna.Dodajw(2);
	 zmienna.Dodajw(4);
	 zmienna.Dodajk(12,2,4);
	 zmienna.Dodajw(6);
	 zmienna.Dodajk(10 ,2,6);
	 zmienna.Sasiad(2);
	 zmienna.Usunk(2,6);
	 zmienna.Sasiad(2);
	 zmienna.DFS();*/

	double roznica;
	clock_t start, koniec;
	start = clock();
	/*PIERWSZY GRAF*/
	graf1.Dodajw(1);
	graf1.Dodajw(2);
	graf1.Dodajw(3);
	graf1.Dodajw(4);
	graf1.Dodajw(5);
	graf1.Dodajw(6);
	graf1.Dodajw(7);


	graf1.Dodajk(1, 2, 3);
	graf1.Dodajk(2, 3, 3);
	graf1.Dodajk(3, 4, 5);
	graf1.Dodajk(2, 5, 3);
	graf1.Dodajk(5, 6, 4);
	graf1.Dodajk(6, 7, 6);
	graf1.Dodajk(1, 5, 5);
	graf1.Dodajk(5, 3, 5);
	graf1.Dodajk(7, 1, 1);
	graf1.Dodajk(6, 4, 1);
	graf1.Dodajk(7, 4, 0);
	/*DRUGI GRAF*/
	graf2.Dodajw(1);
	graf2.Dodajw(2);
	graf2.Dodajw(3);
	graf2.Dodajw(4);
	graf2.Dodajw(5);


	graf2.Dodajk(1, 2, 10);
	graf2.Dodajk(2, 3, 1);
	graf2.Dodajk(3, 4, 4);
	graf2.Dodajk(4, 3, 6);
	graf2.Dodajk(5, 4, 2);
	graf2.Dodajk(2, 5, 3);
	graf2.Dodajk(5, 3, 9);
	graf2.Dodajk(4, 1, 7);
	graf2.Dodajk(1, 5, 5);
	graf1.Dodajk(1, 2, 7);

	koniec = clock();
	roznica = (koniec - start) / (double) CLOCKS_PER_SEC;

	//return ( ((double)t)/CLOCKS_PER_SEC );
	cout << "czas dzialania programu" << roznica << endl;

}

