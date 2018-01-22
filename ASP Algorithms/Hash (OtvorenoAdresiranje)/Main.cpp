#include<iostream>
using namespace std;

#include "Hash.h"

void main(){
	Hash<int> hesireanje;
	hesireanje.Dodaj(10);
	hesireanje.Dodaj(9);
	hesireanje.Dodaj(5);
	hesireanje.Dodaj(9);
	
	hesireanje.Print();
	getchar();
}