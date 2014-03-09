#include <tablica.hh>
#include <iostream>

void Tablica::zamienelementy ( int i ,  int j){
	int place1; int place2;
	place1=T[i];
	place2=T[j];
	T[i]=place2;
	T[j]=place1;
	
}

void Tablica::odwrockolejnosc(){
  for ( unsigned int i=0 ;i<dlugosctab/2 ;i++)	{

	  zamienelementy(i,dlugosctab -1-i);
	  }

}
void Tablica::zmianarozmiaru (unsigned int nowyrozmiar){

	T=(int*)realloc(T,nowyrozmiar * sizeof(int));
		dlugosctab=nowyrozmiar;
	}
	
void Tablica::dodajelement(int element) {
 zmianarozmiaru(rozmiar()+1);
 T[dlugosctab-1]=element;
 }

void Tablica::dodajelementy(const Tablica &T1){
	unsigned int tmp=rozmiar();
	zmianarozmiaru(rozmiar()+T1.rozmiar());
	for(unsigned int i=0;i<T1.rozmiar();i++){
		T[tmp+1]=T[i];
	}
}

Tablica& Tablica::operator = (const Tablica &argument){
	zmianarozmiaru(argument.rozmiar());
	for (unsigned int i=0;i<rozmiar(); i++ ){
		T[i]=argument[i];
	}
 return *this;
}
Tablica& Tablica::operator + (const Tablica &argument) const{
   	Tablica *tmp = new Tablica;
   	tmp->dodajelementy(*this);
   	tmp->dodajelementy(argument);
   	return *tmp;
}

bool Tablica::operator == (const Tablica &argument) const{
	if(rozmiar()!=argument.rozmiar()) return false;
	
	for (unsigned int i=0;i<rozmiar() ; i++){
		if(T[i]!=argument[i]) return false;
	}
	return true;
}

