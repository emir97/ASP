#include<iostream>
using namespace std;

#include "MatricaSusjedstva.h"
#include "DFS.h"
void main(){
	MatricaSusjedstva s(5);
	int vrh = 2;
	s.UcitajMatricuFromFile("..."); // Lokacija fajla Matrica.txt
	s.ispisMatrice();
	cout << endl;
	DfsAlgoritamRekurzija::start(&s)->Print();
	getchar();
}