#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <exception>
template<class T>
class Stack{
	Node<T> *last;
public:
	Stack(){
		last = nullptr;
	}
	bool isEmpty(){ return last == nullptr; }
	void Push(T e){
		Node<T> *temp = new Node<T>(e, last);
		last = temp;
	}
	T Pop(){
		if (isEmpty()) throw exception("Stek je prazan");
		Node<T> *temp = last;
		last = last->GetNextNode();
		T tempValue = temp->GetValue();
		delete temp;
		return tempValue;
	}
	void DisplayAll(){
		Node<T> *temp = last;
		while (last != nullptr)
		{
			cout << last->GetValue() << " ";
			last = last->GetNextNode();
		}
	}
};

#endif