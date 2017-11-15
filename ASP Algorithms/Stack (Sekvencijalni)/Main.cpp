#include <iostream>
using namespace std;

#include "Stack.h"

int main(){
	Stack<int> stek;
	stek.Push(2);
	stek.Push(3);
	stek.Push(4);
	stek.Push(5);
	stek.Push(62);
	stek.Push(72);

	cout << stek.Pop() << " ";
	cout << stek.Pop() << " ";
	cout << stek.Pop() << " ";
	

	getchar();
	return 0;
}