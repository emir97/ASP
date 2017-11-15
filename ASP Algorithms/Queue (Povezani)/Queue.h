#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <exception>
template<class T>
class Queue{
	Node<T> *first;
	Node<T> *last;
public:
	Queue(){
		first = nullptr;
		last = nullptr;
	}
	void Enqueue(T e){
		Node<T> *temp = new Node<T>(e, nullptr);
		if (last != nullptr){
			last->GetNextNode() = temp;
		}
		else {
			first = temp;
		}
		last = temp;
	}
	T Dequeue(){
		if (isEmpty()) throw exception("Red je prazan.");
		Node<T> *temp = first;
		first = first->GetNextNode();
		if (first == nullptr) last = nullptr;
		T tempValue = temp->GetValue();
		delete temp;
		return tempValue;
	}
	void DispalyAll(){
		Node<T> *temp = first;
		while (temp != nullptr)
		{
			cout << temp->GetValue()<< " ";
			temp = temp->GetNextNode();
		}
	}
	bool isEmpty(){
		return first == nullptr;
	}
};

#endif