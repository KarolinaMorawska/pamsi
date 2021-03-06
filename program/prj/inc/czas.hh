#ifndef CZAS_HH
#define CZAS_HH

#include <ctime>
#include "stos.hh"
#include "stos2.hh"
#include "stoslista.hh"
#include "kolejka.hh"

using namespace std;

/*! \brief  Sablon klasy Czasstos.
*  Klasa Czasstos mierzy czas dzialania algorytmu wykorzystuje    *parametry takie jak : liczba powtorzen i zmienna-czyli rozmiar  problemu .
*/
template <class klasasto > class Czasstos
{
public:
   /*! Funckja liczaca czas dzialania algorytmu stosu */
	double czas(unsigned int lpowtorzen,unsigned int zmienna);
};
template <class klasakol> class Czaskol
{
public:
   /*! Funckja liczaca czas dzialania algorytmu kolejki */
	double czas(unsigned int lpowtorzen,unsigned int zmienna);
};

template<class klasasto>
 double Czasstos<klasasto>::czas(unsigned int lpowtorzen, unsigned int zmienna) {
	clock_t tmp = clock();
		    for(unsigned int i=0;i<lpowtorzen;i++){
			    klasasto stos;
			   for(unsigned int j=0;j<zmienna;j++){
				   stos.push(0);
			   }
		    }

		    tmp=clock()-tmp;
		 	return ((double)tmp)/CLOCKS_PER_SEC;

}

template<class klasakol>
double Czaskol<klasakol>::czas(unsigned int lpowtorzen, unsigned int zmienna) {
	clock_t tmp = clock();
			    for(unsigned int i=0;i<lpowtorzen;i++){
				    klasakol kolejka;
				   for(unsigned int j=0;j<zmienna;j++){
					   kolejka.enqueue(0);
				   }
			    }

			    tmp=clock()-tmp;
			 	return ((double)tmp)/CLOCKS_PER_SEC;

}


#endif
