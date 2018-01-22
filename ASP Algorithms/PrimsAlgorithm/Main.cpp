#include<iostream>
using namespace std;

#include "MatricaSusjedstva.h"
#include "Prim.h"
void main(){
	MatricaSusjedstva s(5);
	int vrh = 2;
	s.UcitajMatricuFromFile("..."); // Lokacija fajla Matrica.txt
	s.ispisMatrice();
	cout << endl;
	Prim::start(&s, 0)->Print();
	getchar();
}