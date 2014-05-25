/*
 * plecak.cpp
 *
 *  Created on: 23 maj 2014
 *      Author: karolina
 */

#include "plecak.h"
/*!
 * \file
 * \brief Funkcje do klasy plecak.
 */
plecak::plecak() {
	// TODO Auto-generated constructor stub

}

plecak::~plecak() {
	// TODO Auto-generated destructor stub
}

void plecak::oblicz(vector<pair<int,int> > Bag,int maxpoj){
	T=Bag;
	maxvalue.clear();
	lastitem.clear();
	maxvalue.resize(maxpoj+1);
	lastitem.resize(maxpoj+1);
	for(int i=0 ;i<T.size();i++){
		for(int j=maxpoj-T[i].first;j>=0;j--){
			if(maxvalue[j+T[i].first]<maxvalue[j]+T[i].second){
				maxvalue[j+T[i].first]=maxvalue[j]+T[i].second;
				lastitem[j+T[i].first]=i;
			}
		}
	}

}
int plecak::wartosc(int poj){
	int naj=0;
	for(int i=0;i<=poj;i++){
		if(naj<maxvalue[i]){
			naj=maxvalue[i];
		}
	}
	return naj;
}
vector<pair<int,int> > plecak::przedmioty(int poj){
	int naj=0;
	int najpoj=0;
	vector<pair<int,int> > wynik;
	for(int i=0;i<=poj;i++){
		if(naj<maxvalue[i]){
			naj=maxvalue[i];
			najpoj=i;
		}
	}
	while (najpoj>0){
		wynik.push_back(T[lastitem[najpoj]]);
		najpoj-=T[lastitem[najpoj]].first;
}
	return wynik;
}
