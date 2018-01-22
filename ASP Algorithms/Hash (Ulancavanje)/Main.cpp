#include<iostream>
using namespace std;

#include "Hash.h"

void main(){
	Hash<int> hesireanje;
	hesireanje.dodaj(0);
	hesireanje.dodaj(10);
	hesireanje.dodaj(20);
	hesireanje.dodaj(14);
	hesireanje.dodaj(14);
	hesireanje.dodaj(166);
	try{
		hesireanje.ukloni(20);
	}
	catch(exception e){
		cout << e.what() << endl;
	}
	hesireanje.print();
	getchar();
}