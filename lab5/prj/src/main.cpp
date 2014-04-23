/*! \mainpage Dokumentacja zadania lab6
 *
 *  \date : 5 kwi 2014
 *  \author: Karolina Morawska
 *  \version: 0.1
 */
#include <iostream>
#include "tablicaas.hh"

using namespace std;
template<typename K, typename W>

int Tablicaas<K,W>::zmienna=0;
/*! 
* \file
* \brief Główna funkcja programu
*/

/*!
 *\brief  W funkcji main:
    -tworzona jest tablica asocjacyjna
  -dodana do niej zostaje para (klucz, wartosc)
   -sprawdzenie poprawnosci dzialania funkcji pobierz
   -sprawdzenie poprawnosci dzialania funkcji usun
  -sprawdzenie zawartosci tablicy
 */
int main(){
 Tablicaas <string , int> tab;
 per <string,int> para("napis", 10); //sprawdzenie poprawnosci metod
 tab.dodaj(para);
cout << tab.pobierz ("napis") <<endl;
tab.usun("napis");
cout << "Tablica jest :" <<tab.czypusta() <<endl;
}
