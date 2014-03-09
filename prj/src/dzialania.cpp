#include <iostream>
#include <fstream>
#include <dzialania.hh>
#include <ctime>

using namespace std;

/*!
*  Argumenty i najwazniejsze pola funkcji
   -tab1 -tablica na ktorej elementach beda wykonywane dzialania

*/
void Dzialania::oblicz()
{
    for (unsigned int i=0; i<tab1.rozmiar() ;i++){
	 tab2[i]=tab1[i]*2;
	}
}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -nazwapl zmienna typu char zawierajaca nazwe pliku

*/
bool Dzialania::wczytajplik(char *nazwapl)
{
	ifstream plik;
	plik.open(nazwapl);

	if( !plik.good() ){
		cout << "Nie otworzono pliku ";
	    return false;
	}

	unsigned int rozmiar;
	plik >> rozmiar;
	tab1.zmianarozmiaru(rozmiar);
	tab2.zmianarozmiaru(rozmiar);

	for (unsigned int i=0; i<rozmiar; i++) {
		plik >> tab1[i];
	}
	return true;
}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -nazwapl zmienna typu char zawierajaca nazwe pliku

*/
bool Dzialania::porownaj(char* nazwapl)
	{
		ifstream pliks;
		pliks.open(nazwapl);

		if( !pliks.good() ) {

		cout << "Nie otworzono pliku sprawdzajacego ";
		        return false;
		}

		 unsigned int rozmiarek;
		 pliks>>rozmiarek;

		 if(rozmiarek!=tab2.rozmiar()){
		 	cout << "Rozmiary plikow nie zgadzaja sie ";
		 return false; }

		 	for(unsigned int i=0; i<tab2.rozmiar();i++){
		 		int d;
		 	pliks>>d;
		 	if(d!=tab2[i]){
		 		cout <<"Porownywane wartosci nie zgadzaja sie !";
		 		return false; }
	}
		 	return true;
	}
/*!
*   Argumenty i najwazniejsze pola funkcji
    -iloscpowtorzen -zmienna zawierajaca ile powtorzen ma wykonywac program.
*/
	double Dzialania::liczczas(int iloscpowtorzen)
	{
	    clock_t tmp = clock();
	    for(int i=0;i<iloscpowtorzen;i++){
		    oblicz();
	    }

	    tmp=clock()-tmp;
	 	return ((double)tmp)/CLOCKS_PER_SEC;

	}
