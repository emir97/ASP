#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <exception>
template<class T>
class Queue{
	Node<T> *nodes;
public:
	Queue(){
		nodes = nullptr;
	}
	Queue(Node<T> *node){
		nodes = node;
	}
	void Enqueue(T value){
		Node<T> *temp = new Node<T>(value, nodes);
		if (nodes == nullptr){
			nodes = temp;
			nodes->GetNextNode() = nullptr;
			return;
		}
		Node<T> * t = nodes;
		Node<T> * p = nullptr;

		while (t != nullptr)
		{
			if (temp->GetValue() > t->GetValue())
				break;
			p = t;
			t = t->GetNextNode();
		}

		temp->GetNextNode() = t;
		if (p == NULL)
			nodes = temp;
		else
			p->GetNextNode() = temp;
	}
	T Dequeue(){
		if (isEmpty()) throw exception("Red je prazan.");
		Node<T>* temp = nodes;
		nodes = nodes->GetNextNode();
		T tempValue = temp->GetValue();
		delete temp;

		return tempValue;
	}
	void DispalyAll(){
		Node<T> *temp = nodes;
		while (temp != nullptr)
		{
			cout << temp->GetValue() << " ";
			temp = temp->GetNextNode();
		}
	}
	bool isEmpty(){
		return nodes == nullptr;
	}
};

#endif