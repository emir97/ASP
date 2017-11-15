#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
	LinkedList<int> lista;
	lista.AddFirst(10);
	lista.AddFirst(2);
	lista.AddFirst(4);
	lista.AddFirst(5);
	lista.AddFirst(6);
	lista.AddFirst(18);
	lista.AddFirst(43);
	lista.AddFirst(3);

	lista.RemoveFirst();
	lista.RemoveLast();
	lista.RemoveValue(18);

	lista.DisplayAll();

	getchar();
	return 0;
}