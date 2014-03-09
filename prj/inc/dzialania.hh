#ifndef DZIALANIA_HH
#define DZIALANIA_HH

#include "tablica.hh"


class Dzialania
{
private:
Tablica tab1;
Tablica tab2;
void oblicz();

public:

      bool wczytajplik(char *nazwapl);
      bool porownaj(char *nazwapl);
      double liczczas(int iloscpowtorzen);
      int rozmiartab () { return tab1.rozmiar() ; }

};

#endif
