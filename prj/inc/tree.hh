/*
 * tree.hh
 *
 *  Created on: 12 kwi 2014
 *      Author: karolina
 */

#ifndef TREE_HH_
#define TREE_HH_
#include "node.hh"
/*!
 * \file
 * \brief Definicja klasy Tree
 *
 * Plik zawiera definicję klasy Tree
 * Jest to klasa glowna , ktora wykorzystuje klase NODE.
*/
#include <iostream>
#include <cstdlib>

using namespace std;
/*!
* \brief Modeluje pojęcie Para.
* Klasa modeluje pojęcie para .
* Jej atrybutem jest pole zawierajace root(korzen)
*/
class Tree{
public:
/*
 *  \brief Inicjalizuje wskaznik na korzen .
 */
	NODE *root;
/*
 *  \brief Funkcja dodaje obekt typu Para o nazwie element.
 */
	void dodaj(Para element);
/*
 *  \brief Funkcja wyszukuje element o podanym kluczu.
 */

	int wyszukaj(int key);
/*
 *   \brief Funckja usuwa element.
 */
	void usun(int key);
/*
 *  \brief Inicjalizuje konstruktor.
 */
	Tree(){
		root=NULL;

	}

};

void Tree::dodaj(Para element){

	if(root==NULL){  //sprawdza czy drzewo jest puste
		root=new NODE; //jesli tak tworzony jets nowy wezel i podstawiony jako korzen
		root->value=element;
		cout << "dodano element" <<root->value.wartosc<<endl;
		}
	else {
		NODE *tmp=root; // w przeciwnym wypadku przechodzimy po wezlach drzewa az natrafimy
		                   // na wolny wezel
		while(tmp!=NULL){
			if(tmp->value.klucz < element.klucz){
				if(tmp->left==NULL){
					tmp->left=new NODE;
					tmp->left->value=element;
					break;
				}
				tmp=tmp->left;

			}
			else {
				if(tmp->right==NULL){
				tmp->right=new NODE;
				tmp->right->value=element;
				break;
				}
				tmp=tmp->right;

			}
		}
		tmp=new NODE;
		tmp->value=element;
	}

}
int Tree::wyszukaj(int key){
	NODE *tmp=root;
	while (tmp!=NULL){ // dopoki korzen jest niepusty
		if (tmp->value.klucz==key) // jesli szukany klucz jet taki sam
			return tmp->value.wartosc;  //zwarcana wartosc tego klucza
		if(tmp->value.klucz < key){
						tmp=tmp->left; // jezeli mniejszy od klucza idziemy w lewo
					}
					else {
						tmp=tmp->right; //jezeli przechodzimy na prawo
					}
	}
	return 0;

}
void Tree::usun(int key){
	NODE *tmp=root;
	while (tmp!=NULL){ // dopoki korzen jest niepusty
			if (tmp->value.klucz==key){
				tmp->value.wartosc=-1;
			}
			if(tmp->value.klucz < key){
							tmp=tmp->left;
						}
						else {
							tmp=tmp->right;
						}
		}
}
#endif /* TREE_HH_ */
