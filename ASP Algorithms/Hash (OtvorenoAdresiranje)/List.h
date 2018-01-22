#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <exception>
/*
	Lista samo sadrzi core funkcionalnosti potrebne za Hashing
*/
template<class T>
class LinkedList{
	Node<T> *head;
public:
	LinkedList(){
		head = nullptr;
	}
	LinkedList(Node<T> *h){
		head = h;
	}
	bool isEmpty(){ return head == nullptr; }

	void AddValue(T value){
		Node<T> *temp = new Node<T>(value, head);
		head = temp;
	}
	bool RemoveValue(T value){
		if (isEmpty()) throw exception("Lista je prazna");

		bool success = true;
		Node<T> *info = head;
		Node<T> *beforeInfo = nullptr;
		while (info->GetNextNode() && info->GetValue() != value)
		{
			beforeInfo = info;
			info = info->GetNextNode();
		}
		if (info->GetValue() != value) throw exception("Nema elementa u listi.");
		if (beforeInfo != nullptr){
			beforeInfo->GetNextNode() = info->GetNextNode();
		}
		else {
			head = head->GetNextNode();
		}
		delete info;
		return true;
	}
	void Print(){
		Node<T> *temp = head;
		while (temp != nullptr)
		{
			cout << temp->GetValue() << " ";
			temp = temp->GetNextNode();
		}
	}
};

#endif