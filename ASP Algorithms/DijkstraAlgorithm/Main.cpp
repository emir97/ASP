#include<iostream>
using namespace std;

#include "MatricaSusjedstva.h"
#include "Dijkstra.h"
void main(){
	MatricaSusjedstva s(5);
	int vrh = 2;
	s.UcitajMatricuFromFile("..."); // Lokacija fajla Matrica.txt
	s.ispisMatrice();
	cout << endl;
	Dijkstra::start(&s, 0, 3);
	getchar();
}