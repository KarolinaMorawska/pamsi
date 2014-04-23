#include "czas.hh"
/*! 
	* \file
	* \brief Definicja metody Start
	*
	*  Metoda, ktora wlacza zegar.

*/
void Zegar::Start()
{
    start = clock();
    }
    /*! 
	* \file
	* \brief Definicja metody Koniec
	*
	*  Metoda, ktora powoduje zatrzymanie zegara i liczy czas dzialania algorytmu.

*/
void Zegar::Koniec()
{
     koniec = clock();
     
     czas = (double)(koniec-start)/CLOCKS_PER_SEC;
     
     
     }
     /*! 
	* \file
	* \brief Definicja metody Wynik
	*
	*  Metoda, ktora wyswietla wynik.

*/
int Zegar::Wynik()
{
    cout << "Czas wykonywania programu: " << (double)czas << "s" << endl;

}

