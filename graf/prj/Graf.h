/*
 * Graf.h
 *
 *  Created on: 27 kwi 2014
 *      Author: karolina
 */

#ifndef GRAF_H_
#define GRAF_H_
#include "para.h"
/*!
 * \file
 * \brief Definicja klasy Graf
 *
 * Plik zawiera definicję klasy Graf
 * Jest to klasa glowna , ktora wykorzystuje klase para.
*/
#include<vector>
#include<list>
#include<iostream>
using namespace std;
/*!
* \brief Modeluje pojęcie Graf.
* Klasa modeluje pojęcie graf .
* Jej atrybutem jest pole zawierajace liste sasedztwa.
*/

class Graf {
public:
	int odleglosc(int a , int b);
/*!
 *  \brief Lista wezlow otwartych.
 */
	list<int> OL; //OTWARTA
/*!
 *  \brief Lista wezlow zamnknietych.
 */
	list<int> CL; //ZAMKNIETA
/*!
 *  \brief Wektor przechowujacy najkrotsza droge.
 */
	vector<int> shortdroga;
/*!
 *  \brief Metoda ktora zwraca minimalna odleglosc pomiedzy wierzcholkami.
 */
	int zwrocmin();
/*!
 *  Przewidywana przez heurystykę droga od x do wierzchołka docelowego.
 */
	double zwroch();
/*!
*  \brief Metoda ktora zwraca droge pomiedzy wierzcholkiem poczatkowym a x.
 */
	double zwrocg();
/*!
 *  \brief Metoda ktora zwraca sume funkcji zwroch i  funkcji zwrocg.
 */
	double zwrocf();
/*!
 *  \brief Metoda ktora sprawdza dostepnosc wierzcholka.
 */
	bool obecny(list<int>& lista, int ktory);
/*!
 *  \brief Metoda ktora zwraca dla wierzcholka funkcje f.
 */
	int zwrocdlawierz(int w1 , int w2);
/*!
 *   \brief Inicjalizuje zmienna typu wektor ktora wykorzystywana jest
 *    przy metodach przeszukiwan aby sprawdzic czy dany wierzcholek byl odwiedzany
 *    i kolorowany na odpowiedni kolor.
 */
	vector<int> colour;
/*!
 *  \brief Inicjalizuje zmienna typu lista wektorow .
 */
	vector<list<para> > wektor;
/*!
 *  \brief Metoda ktora dodaje wierzcholek do grafu.
 *  Jej atrybutem jest zmienna typu int o nazwie wierzcholek.
 */
	void Dodajw(unsigned int wierzcholek);
/*!
 *  \brief Metoda ktora dodaje krawedz do grafu.
 *  Jej atrybutem sa zmienne okreslajace wierzcholki przez ktore ma przejsc krawedz
 *  i zmienna ktora zawiera wage.
 */
	void Dodajk(int waga, int w1, int w2);
/*!
 *  \brief Metoda usuwa krawedz.
 *  Jej atrybutem sa dwie zmienne oznaczajace wierzcholki ktorych krawedz ma byc usunieta.
 */
	void Usunk(int w1, int w2);
/*!
 *  \brief Metoda usuwa wierzcholek.
 *  Jej atrybutem jest zmienna typu int o nazwie wierzcholek.
 */
	void Usunw(int wierzcholek);
/*!
 *  \brief Metoda sprawdza czy wystepuje polaczenie miedzy dwoma wierzcholkami.
 *  \return Zwraca true lub false.
 */
	bool Polaczenie(int w1, int w2);
/*!
 *  \brief Metoda sprawdza sasiadow wybranego wierzcholka i wypisuje ich.
 */
	void Sasiad(int w1);
	/*!
	 *  \brief Metoda przeszukiwania wstecz.Danymi wejściowymi dla algorytmu jest wierzchołek od którego rozpoczynane jest przeszukiwanie. Początkowo wszystkie wierzchołki kolorowane są na biało, co oznacza, że nie zostały jeszcze odwiedzone.Kolejka FIFO Q jest inicjalizowana węzłem startowym, którego kolor ustawiony został na szaro – oznacza to, że węzeł został już odwiedzony, lecz nie zostały odwiedzone węzły do niego sąsiednie. Następnie, pobierany jest pierwszy wierzchołek z kolejki i analizowana jest lista jego sąsiadów. Jeżeli sąsiad jest biały, oznacza to, że nie został jeszcze odwiedzony: aktualizowany jest więc jego kolor a następnie jest on dodawany do kolejki. Po przeglądnięciu wszystkich sąsiadów danego węzła kolor węzła bieżącego zmieniany jest na czarny (wszyscy jego sąsiedzi zostali odwiedzeni) i operacja powtarza się dla następnego węzła znajdującego się w kolejce, bądź też (jeżeli kolejka jest pusta) algorytm kończy swoje działanie
	 */
	void BFS(int wierzcholeks);
	/*!
	 *  \brief Pomocnicza metoda przy wyszkukiwaniu w glab, ktora sluzy do odwiedzania wezla.Na poczatku zamalowywuje wierzcholek na szaro, nastepnie dla kazdego wierzcholka v na liscie sasiedztwa u sprawdzane jest jezeli v jest bialy odwierz wierzcholek v.
	 */
	void VisitNode(int wierzcholek);
	/*!
	 *  \brief Metoda przeszukiwania w glab.Na poczatku dla kazdego wierzcholka u z grafu kolor wierzcholka ustawiany jest na bialy.W innym przypadku jezeli wierzcholek jest juz bialy wywolywana jest metoda VisitNode.
	 */
	void DFS();
/*!
 * \brief Wyszukuje najkrotsza sciezke miedzy dwoma wezlami jesli odnajdzie metoda zwraca true w innym przypadku zwracane jest false.
 */
	bool Astar(int start , int stop);
};

#endif /* GRAF_H_ */
