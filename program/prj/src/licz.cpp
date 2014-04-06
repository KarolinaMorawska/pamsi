#include <iostream>
#include <fstream>
#include <ctime>
#include "licz.hh"
#include "tablica.hh"

using namespace std;
void Licz::zmianarozmiaru(unsigned int nowyrozmiar) {
	tab1 = (int*) realloc(tab1, nowyrozmiar * sizeof(int));
	dlugosctab = nowyrozmiar;
}

bool Licz::wczytajplik(char *nazwapl) {
	std::ifstream plik;
	plik.open(nazwapl);

	if (!plik.good()) {
		std::cout << "Nie otworzono pliku ";
		return false;
	}

	unsigned int rozmiar;
	plik >> rozmiar;
	zmianarozmiaru(rozmiar);

	for (unsigned int i = 0; i < rozmiar; i++) {
		plik >> tab1[i];
	}
	return true;
}

void Licz::oblicz(sortingType type) {
	tab2 = tab1;
	switch (type) {
	case quick:
		quicksort (tab1);
		break;
	case merge:
		mergesort(tab1);
		break;
	case intro:
		intro(tab1);
		break;
	}

double Licz::benchmark(int powtorzenia, sortingType)
{

	clock_t t = clock();
	for (int i=0; i<powtorzenia; i++) {
		calculate(type);
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );
}

void Licz::quicksort(int lewy, int prawy) {
	int x = tab1[(prawy + lewy) / 2]; // obieramy x
	int i = lewy, j = prawy, w;// i, j - indeksy w tabeli
	do
	{
		while (tab1[j] > x) // dopoki elementy sa wieksze od x
		j--;
		while (tab1[i] < x)// dopoki elementy sa mniejsze od x
		i++;
		if (i <= j) {  // zamieniamy miejscami gdy i < j
			w = tab1[i];
			tab1[i] = tab1[j];
			tab1[j] = w;
			i++;
			j--;
		}
	}while(i<=j);
	if (lewy < j)
	quicksort(lewy, j);
	if (i < prawy)
	quicksort(i, prawy);
}

void Licz::mergesort(int lewy, int prawy) {
	int srodek;
	if (lewy != prawy) {
		srodek = (lewy + prawy) / 2;
		mergesort(lewy, srodek);
		mergesort(srodek + 1, prawy);
		merge(lewy, prawy, srodek);
	}

}

void Licz::merge(int lewy, int prawy, int srodek) {
	int i = lewy;
	int j = srodek+1;
	Typ *newTab = new Typ[prawy - lewy];
	int k = 0;
	while (i <= srodek && j <= prawy) {
		if (tab1[i] < tab1[j]) {
			newTab[k] = tab1[i];
			i++;
		} else {
			newTab[k] = tab1[j];
			j++;
		}
		k++;
	}
	if (i <= srodek) {
		while (i <= srodek) {
			newTab[k] = tab1[i];
			i++;
			k++;
		}

	} else {
		while (j <= prawy) {
			newTab[k] = tab1[j];
			j++;
			k++;
		}
	}
	for (int i = 0; i <= prawy - lewy; i++) {
		tab1[lewy + i] = newTab[i];
	}
	delete[] newTab;
}

void Licz::bubble(int lewy , int prawy) {
	for (int i = lewy; i <= prawy; i++) {
		for (int j = lewy; j <= prawy-1; j++) {
			if (tab1[j] > tab1[j + 1]) {
				int w = tab1[j];
				tab1[j] = tab1[j+1];
				tab1[j+1] = w;
			}
		}
	}
}

void Licz::intro(int lewy, int prawy) {
	int x = T[(prawy + lewy) / 2]; // obieramy x
	int i = lewy, j = prawy, w;// i, j - indeksy w tabeli
	do
	{
		while (T[j] > x) // dopoki elementy sa wieksze od x
		j--;
		while (T[i] < x)// dopoki elementy sa mniejsze od x
		i++;
		if (i <= j) {  // zamieniamy miejscami gdy i < j
			w = T[i];
			T[i] = T[j];
			T[j] = w;
			i++;
			j--;
		}

	}while(i<=j);

	if (lewy < j && (j - lewy) > 9)
	quicksort(lewy, j);
	else
	bubble(lewy,j);
	if (i < prawy && (prawy - i) > 9)
	quicksort(i, prawy);
	else
	bubble(i,prawy);
}
