/*
 * main.cpp
 *
 *  Created on: 23 maj 2014
 *      Author: karolina
 */
/*! \mainpage Dokumentacja zadania lab9
 *
 *  \date : 25 maja 2014
 *  \author: Karolina Morawska
 *  \version: 0.1
 */
/*! \file
* \brief Glowny plik programu.
*/

#include "plecak.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*! \brief Główna funkcja programu.
 *  W funkcji main:
 *  -tworzona jest zmienna typu plecak
 *  -uzytkownik zostaje zapytany o jakiej pojemnosci ma byc plecak i ile przedmiotow chce tam wlozyc
 *  -sprawdzenie poprawnosci dzialania funkcji oblicz
 *  -sprawdzenie poprawnosci dzialania funkcji przedmioty
 *  -sprawdzenie poprawnosci dzialania funkcji wartosc
 *  -wypisanie na konsoli wyniku zapakowania plecaka oraz jakie elementy sie w nim znajduja
 */
int main(){
	int pojemnosc;
	int ileprzedmiotow;
	cout<<"Jaka pojemnosc? ";
	cin>>pojemnosc;

	cout<<"Ile przedmiotow? ";
	cin>>ileprzedmiotow;
	vector<pair<int,int> > przedmioty;
	int waga , wartosc;
	for(int i=0;i<ileprzedmiotow;i++){
		cout<<"Podaj wage i wartosc: ";
				cin>>waga;
				cin>>wartosc;
				przedmioty.push_back(make_pair(waga , wartosc));
	}
	plecak bag;
	bag.oblicz(przedmioty , pojemnosc);
	vector<pair<int,int> > wynik=bag.przedmioty(pojemnosc);
	cout<<"Wynik zapakowania plecaka: "<<bag.wartosc(pojemnosc)<<endl;
	cout<<"Przedmioty w plecaku: "<<endl;
	for(int i=0;i<wynik.size();i++){
		cout<<wynik[i].first<<" "<<wynik[i].second<<endl;
	}
}


