/*
 * tablicaas.hh
 *
 *  Created on: 5 kwi 2014
 *      Author: karolina
 */

#ifndef TABLICAAS_HH_
#define TABLICAAS_HH_
#define ROZMIAR 1000000
/*!
 * \file
 * \brief Definicja szablonu klasy Tablicaas(Tablica asocjacyjna)
 *
 * Plik zawiera definicję szablonu klasy Tablicaas.Jest to klasa główna , która
 * wykorzystuje klasę per.

*/
#include "per.hh"
#include <iostream>
#include <string>
/*!
* \brief Modeluje pojęcie Tablicaas.
* Klasa modeluje pojęcie Tablica asocjacyjna .
* Jej atrybutem są pola zawierające klucz i wartość.
*/
template <typename K, typename W>
class Tablicaas {
public:
/*!
 *  \brief Wykorzystuje pola z klasy per.
 */
	per<K,W> Tab[ROZMIAR];

/*!
 *  \brief Dodaje parę-wartość i klucz.
 *  Dodatkowo zmienna ilosc elementow zostaje zwiekszona.
 */
	 void dodaj(per<K,W> para);
/*!
 *  \brief Metoda która usuwa klucz.
 *  Dodatkowo zmienna ilosc elementow zostaje zmniejszona.
 */
	void usun ( K key);
/*!
 *  \brief Pobiera klucz.
 *  /return Zwraca zmienna o nazwie wartosc.
 */
     W pobierz (K key);
 /*!
  *  \brief Sprawdza zawartość tablicy.
  *   \return Metoda porownuje zmienna i zwraca true jeśli zmienna jest równa 0
  *   i false w przeciwnym wypadku.
  */
	bool czypusta(){
		return zmienna==0;
	}
/*!
 * \brief Podaje rozmiar.
 *  \return Zwraca zmienna statyczna.
 */
	int size(){
		return zmienna;
	}
/*!
 *  \brief Pomocnicza zmienna statyczna.
 */
	static int zmienna; //ilosc elementow
/*!
 * \brief Przeciążenie operatora indeksującego.
 * \return Zwraca wartosc.
 */
	W& operator[](K key);
/*!
 *  \brief Funkcja haszująca dla obiektów typu string.
 */
    int haszstring(string key)const {
    	unsigned int h=key[0];
    	for (unsigned int i=0; i< key.size();i++)
    		h= (h<< 4)+key[i];
    	return h % ROZMIAR;
    }
};
template<typename K , typename W>
void Tablicaas<K,W>::dodaj(per<K,W> para){
	int pozycja=haszstring(para.key);
	Tab[pozycja]=para;
	zmienna ++;
	}
template<typename K , typename W>
void Tablicaas<K,W>::usun(K key){
	int pozycja=haszstring(key);
	Tab[pozycja].wartosc=NULL;
	zmienna --;

}
template<typename K , typename W>
W Tablicaas<K,W>::pobierz(K key){
	int pozycja=haszstring(key);
	return *Tab[pozycja].wartosc;
}


template <typename K, typename W>
W& Tablicaas<K,W>::operator[]( K key){
int hash = haszstring(key);
if (Tab[hash].key == key)
return *Tab[hash].wartosc;
Tab[hash].key = key;
Tab[hash].wartosc = new W;
*Tab[hash].wartosc = 0;
return *Tab[hash].wartosc;
}
#endif /* TABLICAAS_HH_ */
