#include <tablica.hh>
#include <iostream>

/*!
*  Argumenty i najwazniejsze pola funkcji 
  -i, j -zmienne oznaczajace elementy w tablicy 

*/
void Tablica::zamienelementy ( int i ,  int j){
	int place1; int place2;
	place1=T[i];
	place2=T[j];
	T[i]=place2;
	T[j]=place1;
	
}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -dlugosctab -zmmienna zawierajaca dlugosc tablicy na ktorej wykonywane jest dzialania

*/
void Tablica::odwrockolejnosc(){
  for ( unsigned int i=0 ;i<dlugosctab/2 ;i++)	{

	  zamienelementy(i,dlugosctab -1-i);
	  }

}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  \return nowyrozmiar -Rozmiar tablicy po zmianie.

*/
void Tablica::zmianarozmiaru (unsigned int nowyrozmiar){

	T=(int*)realloc(T,nowyrozmiar * sizeof(int));
		dlugosctab=nowyrozmiar;
	}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -element -zmienna ktora zostaje dodana do tablicy

*/
void Tablica::dodajelement(int element) {
 zmianarozmiaru(rozmiar()+1);
 T[dlugosctab-1]=element;
 }
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -T1 -tablica ktora powtaje po polaczeniu.

*/
void Tablica::dodajelementy(const Tablica &T1){
	unsigned int tmp=rozmiar();
	zmianarozmiaru(rozmiar()+T1.rozmiar());
	for(unsigned int i=0;i<T1.rozmiar();i++){
		T[tmp+1]=T[i];
	}
}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -agrument -przeciazenie operatora 

*/
Tablica& Tablica::operator = (const Tablica &argument){
	zmianarozmiaru(argument.rozmiar());
	for (unsigned int i=0;i<rozmiar(); i++ ){
		T[i]=argument[i];
	}
 return *this;
}
/*!
*  Argumenty i najwazniejsze pola funkcji 
  -argument -przecciazenie operatora

*/
Tablica& Tablica::operator + (const Tablica &argument) const{
   	Tablica *tmp = new Tablica;
   	tmp->dodajelementy(*this);
   	tmp->dodajelementy(argument);
   	return *tmp;
}

/*!
*  Argumenty i najwazniejsze pola funkcji 
  -argumenti -przeciazenie operatora

*/
bool Tablica::operator == (const Tablica &argument) const{
	if(rozmiar()!=argument.rozmiar()) return false;
	
	for (unsigned int i=0;i<rozmiar() ; i++){
		if(T[i]!=argument[i]) return false;
	}
	return true;
}

