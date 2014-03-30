#include "tablica.hh"

template<typename Typ>
void Tablica<Typ>::zamienelementy(int i, int j) {
	Typ place1;
	Typ place2;
	place1 = T[i];
	place2 = T[j];
	T[i] = place2;
	T[j] = place1;
}

template<typename Typ>
void Tablica<Typ>::dodajelement(Typ element) {
	zmianarozmiaru(rozmiar() + 1);
	T[dlugosctab - 1] = element;
}

template<typename Typ>
void Tablica<Typ>::odwrockolejnosc() {
	for (unsigned int i = 0; i < dlugosctab / 2; i++) {
		zamienelementy(i, dlugosctab - 1 - i);
	}
}
template<typename Typ>
void Tablica<Typ>::dodajelementy(const Tablica<Typ>& T1) {

	unsigned int tmp = rozmiar();
	zmianarozmiaru(rozmiar() + T1.rozmiar());
	for (unsigned int i = 0; i < T1.rozmiar(); i++) {
		T[tmp + 1] = T[i];
	}
}

template<typename Typ>
void Tablica<Typ>::zmianarozmiaru(unsigned int nowyrozmiar) {
	T = (Typ*) realloc(T, nowyrozmiar * sizeof(Typ));
	dlugosctab = nowyrozmiar;
}

template<typename Typ>
Tablica<Typ>& Tablica<Typ>::operator +(const Tablica<Typ>& argument) const {
	Tablica<Typ> *tmp = new Tablica<Typ>;
	tmp->dodajelementy(*this);
	tmp->dodajelementy(argument);
	return *tmp;
}

template<typename Typ>
Tablica<Typ>& Tablica<Typ>::operator =(const Tablica<Typ>& argument) {
	zmianarozmiaru(argument.rozmiar());
	for (unsigned int i = 0; i < rozmiar(); i++) {
		T[i] = argument[i];
	}
	return *this;
}

template<typename Typ>
bool Tablica<Typ>::operator ==(const Tablica<Typ>& argument) const {
	if (rozmiar() != argument.rozmiar())
		return false;

	for (unsigned int i = 0; i < rozmiar(); i++) {
		if (T[i] != argument[i])
			return false;
	}
	return true;
}

template<typename Typ>
void Tablica<Typ>::quicksort(int lewy, int prawy) {
srand(time(NULL));
if(!T.rozmiar()) return ;
	int x = T[(prawy + lewy) / 2]; // obieramy x
      //  int x=T[rand()%( prawy-lewy ) + lewy]; // indeks losowy
	int i = lewy, j = prawy, w; // i, j - indeksy w tabeli
/*													// Wariant pesymistyczny
	for(int k = lewy; k < prawy; k++)
	{
		x = T[k];
		if(T[k+1] < x)	x = T[k+1];
	}
	*/
	/*													// Wariant optymistyczny ??
	int a ,b ,c;
	a = T[rand()%( prawy - lewy ) + lewy];
	b = T[rand()%( prawy - lewy ) + lewy];
	c = T[rand()%( prawy - lewy ) + lewy];
	
*/
	do
	{
		while (T[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (T[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i <= j) {  // zamieniamy miejscami gdy i < j
			w = T[i];
			T[i] = T[j];
			T[j] = w;
			i++;
			j--;
		}
	}while(i<=j);
	if (lewy < j)
		quicksort(lewy, j);
	if (i < prawy)
		quicksort(i, prawy);
}
template<typename Typ>
void Tablica<Typ>::mergesort(int lewy, int prawy) {
  int srodek;
	if (lewy != prawy) {
	  srodek = (lewy + prawy) / 2;
		mergesort(lewy, srodek);
		mergesort(srodek + 1, prawy);
		merge(lewy, prawy, srodek);
	}

}
template<typename Typ>
void Tablica<Typ>::merge(int lewy, int prawy, int srodek) {
	int i = lewy;
	int j = srodek+1;
	Typ *newTab = new Typ[prawy - lewy];
	int k = 0;
	while (i <= srodek && j <= prawy) {
		if (T[i] < T[j]) {
			newTab[k] = T[i];
			i++;
		} else {
			newTab[k] = T[j];
			j++;
		}
		k++;
	}
	if (i <= srodek) {
		while (i <= srodek) {
			newTab[k] = T[i];
			i++;
			k++;
		}

	} else {
		while (j <= prawy) {
			newTab[k] = T[j];
			j++;
			k++;
		}
	}
	for (int i = 0; i <= prawy - lewy; i++) {
		T[lewy + i] = newTab[i];
	}
	delete[] newTab;
}
template<typename Typ>
void Tablica<Typ>::bubble(int lewy , int prawy) {
	for (int i = lewy; i <= prawy; i++) {
		for (int j = lewy; j <= prawy-1 ; j++) {
			if (T[j] > T[j + 1]) {
			       int w = T[j];
			T[j] = T[j+1];
			T[j+1] = w;
			}
		}
	}
}
template<typename Typ>
void Tablica<Typ>::intro(int lewy, int prawy) {
	int x = T[(prawy + lewy) / 2]; // obieramy x
	int i = lewy, j = prawy, w; // i, j - indeksy w tabeli
	do
	{
		while (T[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (T[i] < x) // dopoki elementy sa mniejsze od x
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


template<typename Typ>
void Tablica<Typ>::wyswietl() {
	for (unsigned int i = 0; i < dlugosctab; ++i) {
		std::cout << T[i] << " ";
	}
}

