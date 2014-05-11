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

void Graf::Dodajw(unsigned int wierzcholek){
  	list<para> listawierzcholka;  //pomocnicza zmienna typu lista
  	listawierzcholka.clear();   //wyczyszczenie przed bledami
  	if(wektor.size()<=wierzcholek)
  		wektor.resize(wierzcholek+1); //zmiana rozmiaru
  	wektor[wierzcholek]=listawierzcholka;

}
	void Graf::Dodajk(int waga, int w1, int w2){
		if(!Polaczenie(w1, w2)){ // tylko jezeli polaczenie
			para element(waga , w2);
			wektor[w1].push_back(element);
		}
	}
	void Graf::Usunk(int w1, int w2){
		if(Polaczenie(w1, w2)){
			for(list<para>::iterator it=wektor[w1].begin();it!=wektor[w1].end(); ++it){
				if(it->numer==w2){
					wektor[w1].erase(it);
					break;
				}
			}
		}
	}
	void Graf::Usunw(int wierzcholek){
		wektor.erase(wektor.begin()+wierzcholek);
	}
	bool Graf::Polaczenie(int w1, int w2){
		for(list<para>::iterator it=wektor[w1].begin();it!=wektor[w1].end(); ++it){
			if(it->numer==w2){
				return true;
			}
		}
		return false;
	}
	void Graf::Sasiad(int w1){
		cout<<"Sasiedztwo wierzcholka numer "<<w1<<": ";
		for(list<para>::iterator it=wektor[w1].begin();it!=wektor[w1].end(); ++it){
			cout<<it->numer<<' '<<it->waga<<' ';
		}
	}

	void Graf::BFS(int wierzcholeks){
		colour.resize(wektor.size());
		list<int> kolejka;
for(unsigned int i=0;i<wektor.size();i++){
	colour[i]=0; //kolor 0=bialy 1=szary 2=czarny

}
colour[wierzcholeks]=1;
kolejka.push_back(wierzcholeks);
int u;
while(!kolejka.empty()){

	u=kolejka.front();
	kolejka.pop_front();
	for(list<para>::iterator it=wektor[u].begin();it!=wektor[u].end(); ++it){
		if(colour[it->numer]==0){
			colour[it->numer]=1;
			kolejka.push_back(it->numer);
		}
	}
	colour[u]=2;
}

	}
	void Graf::VisitNode(int wierzcholek){
colour[wierzcholek]=1;
for(list<para>::iterator it=wektor[wierzcholek].begin();it!=wektor[wierzcholek].end(); ++it){
	if(colour[it->numer]==0){
		VisitNode(it->numer);
	}
}
colour[wierzcholek]=2;
	}
	void Graf::DFS(){
		colour.resize(wektor.size());
for(unsigned int i=0;i<wektor.size();i++){
	colour[i]=0; //kolor 0=bialy 1=szary 2=czarny

}
for(unsigned int i=0;i<wektor.size();i++){
	if(colour[i]==0){
		VisitNode(i);
	}

}
	}
