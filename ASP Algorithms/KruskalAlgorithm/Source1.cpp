#include<iostream>
using namespace std;

#include "MatricaSusjedstva.h"
#include "Kruskal.h"
void main(){
	MatricaSusjedstva s(5);
	int vrh = 2;
	s.UcitajMatricuFromFile("..."); // Lokacija fajla Matrica.txt
	s.ispisMatrice();
	cout << endl;
	KruskalAlgoritam::start(&s)->Print();
	getchar();
}