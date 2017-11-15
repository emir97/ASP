#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <exception>
template<class T>
class Stack{
	T *last;
	int counter;
public:
	Stack(){
		last = nullptr;
		counter = 0;
	}
	bool isEmpty(){ return counter == 0; }
	void Push(T e){
		T *temp = new T[counter + 1];
		for (size_t i = 0; i < counter; i++)
			temp[i] = last[i];
		delete[] last;
		temp[counter] = e;
		last = temp;
		counter++;
	}
	T Pop(){
		if (isEmpty()) throw exception("Stek je prazan");
		T temp = last[--counter];
		return temp;
	}
	void DisplayAll(){
		for (size_t i = 0; i < counter; i++)
			cout << last[i] << " ";
	}
};

#endif