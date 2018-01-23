#include<iostream>
using namespace std;

#include "BinaryTree.h"
#include "PreOrder.h"
void main(){
	BinaryTree<int> drvo;
	drvo.dodaj(1);
	drvo.dodaj(2);
	drvo.dodaj(3);
	drvo.dodaj(13);
	drvo.dodaj(12);
	drvo.dodaj(5);
	drvo.dodaj(11);
	
	PreOrder<int>::PreOrder_R(drvo)->Print();
	
	getchar();
}