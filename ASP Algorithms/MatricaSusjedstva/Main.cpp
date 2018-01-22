#include<iostream>
using namespace std;

#include "MatricaSusjedstva.h"

void main(){
	MatricaSusjedstva s(5);
	int vrh = 2;
	s.UcitajMatricuFromFile("..."); // Lokacija fajla Matrica.txt
	s.ispisMatrice();
	cout <<"Izlazni stepen vrha -> "<< s.izlazniStepen(vrh)<<endl;
	cout << "Vrhovi koji su vrhu \"vrh\" susjedi -> ";
	s.SusjediFrom(vrh)->Print();
	cout << endl;
	cout << "Vrhovi kojima je vrh \"vrh\"  susjed -> ";
	s.SusjediTo(vrh)->Print();
	cout << endl;
	cout << "Najblizi susjed vrhu \"vrh\" -> " << s.najbliziSusjed(vrh)<<endl;
	getchar();
}