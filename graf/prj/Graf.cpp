/*
 * Graf.cpp
 *
 *  Created on: 27 kwi 2014
 *      Author: karolina
 */

#include "Graf.h"
/*!
 * \file
 * \brief Funkcje do klasy Graf
 */
int Graf::zwrocdlawierz(int w1, int w2) {
	for (list<para>::iterator it = wektor[w1].begin(); it != wektor[w1].end();
			++it) {
		if (it->numer == w2) {
			return it->F;
		}
	}
	return 1000000;
}

int Graf::zwrocmin() {
	int tmp = 100000;
	list<int>::iterator it = OL.begin();
	list<int>::iterator it2 = OL.begin();
	it2++;
	for (; it2 != OL.end(); ++it, ++it) {
		if (zwrocdlawierz(*it, *it2) < tmp) {
			tmp = zwrocdlawierz(*it, *it2);
		}
	}
	return tmp;
}
void Graf::Dodajw(unsigned int wierzcholek) {
	list<para> listawierzcholka;  //pomocnicza zmienna typu lista
	listawierzcholka.clear();   //wyczyszczenie przed bledami
	if (wektor.size() <= wierzcholek)
		wektor.resize(wierzcholek + 1); //zmiana rozmiaru
	wektor[wierzcholek] = listawierzcholka;

}
void Graf::Dodajk(int waga, int w1, int w2) {
	if (!Polaczenie(w1, w2)) { // tylko jezeli polaczenie
		para element(waga, w2);
		wektor[w1].push_back(element);
	}
}
void Graf::Usunk(int w1, int w2) {
	if (Polaczenie(w1, w2)) {
		for (list<para>::iterator it = wektor[w1].begin();
				it != wektor[w1].end(); ++it) {
			if (it->numer == w2) {
				wektor[w1].erase(it);
				break;
			}
		}
	}
}
void Graf::Usunw(int wierzcholek) {
	wektor.erase(wektor.begin() + wierzcholek);
}
bool Graf::Polaczenie(int w1, int w2) {
	for (list<para>::iterator it = wektor[w1].begin(); it != wektor[w1].end();
			++it) {
		if (it->numer == w2) {
			return true;
		}
	}
	return false;
}
void Graf::Sasiad(int w1) {
	cout << "Sasiedztwo wierzcholka numer " << w1 << ": " << '	';
	for (list<para>::iterator it = wektor[w1].begin(); it != wektor[w1].end();
			++it) {
		cout << it->numer << ' ' << it->waga << ' ';
	}
}

void Graf::BFS(int wierzcholeks) {
	colour.resize(wektor.size());
	list<int> kolejka;
	for (unsigned int i = 0; i < wektor.size(); i++) {
		colour[i] = 0; //kolor 0=bialy 1=szary 2=czarny

	}
	colour[wierzcholeks] = 1;
	kolejka.push_back(wierzcholeks);
	int u;
	while (!kolejka.empty()) {

		u = kolejka.front();
		kolejka.pop_front();
		for (list<para>::iterator it = wektor[u].begin(); it != wektor[u].end();
				++it) {
			if (colour[it->numer] == 0) {
				colour[it->numer] = 1;
				kolejka.push_back(it->numer);
			}
		}
		colour[u] = 2;
	}

}
void Graf::VisitNode(int wierzcholek) {
	colour[wierzcholek] = 1;
	for (list<para>::iterator it = wektor[wierzcholek].begin();
			it != wektor[wierzcholek].end(); ++it) {
		if (colour[it->numer] == 0) {
			VisitNode(it->numer);
		}
	}
	colour[wierzcholek] = 2;
}
void Graf::DFS() {
	colour.resize(wektor.size());
	for (unsigned int i = 0; i < wektor.size(); i++) {
		colour[i] = 0; //kolor 0=bialy 1=szary 2=czarny

	}
	for (unsigned int i = 0; i < wektor.size(); i++) {
		if (colour[i] == 0) {
			VisitNode(i);
		}

	}
}
int Graf::odleglosc(int a, int b) {
	for (list<para>::iterator it = wektor[a].begin(); it != wektor[a].end();
			++it) {
		if (it->numer == b) {
			return it->waga;
		}
	}
	return 1000000;
}
double Graf::zwroch() {

	return 0.0;
}
double Graf::zwrocg() {
	double suma = 0;
	list<int>::iterator it = CL.begin();
	list<int>::iterator it2 = CL.begin();
	it2++;
	for (; it2 != CL.end(); ++it, ++it2) {

		suma += odleglosc(*it, *it2);
	}
	return suma;
}
double Graf::zwrocf() {
	return zwroch() + zwrocg();
}
bool Graf::obecny(list<int>& lista, int ktory) {
	for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
		if (*it == ktory)
			return true;
	}
	return false;

}
bool Graf::Astar(int start, int stop) {
	int minsciezka = 100000;
	OL.push_back(start);
	while (!OL.empty()) {
		int Q = zwrocmin();
		CL.push_back(Q);
		if (Q == stop)
			return true;
		for (list<para>::iterator it = wektor[Q].begin(); it != wektor[Q].end();
				++it) {
			if (obecny(CL, it->numer)) {

			} else if (!obecny(OL, it->numer)) {
				OL.push_back(it->numer);
				it->F = zwrocf();
				it->G = zwrocg();
				it->H = zwroch();
			} else {
			}
			if (it->G < minsciezka) {
				minsciezka = it->G;
			}

		}
	}
	return false; //nie ma sciezki miedzy 2 polami
}
