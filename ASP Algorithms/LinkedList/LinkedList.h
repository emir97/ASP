#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <exception>

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
	
	void AddFirst(T value){
		Node<T> *temp = new Node<T>(value, head);
		head = temp;
	}
	T RemoveFirst(){
		if (isEmpty()) throw exception("Lista je prazna");
		Node<T> *temp = head;
		head = head->GetNextNode();
		T tempValue = temp->GetValue();
		delete temp;
		return tempValue;
	}
	void AddLast(T value){
		Node<T> *temp = head;
		if (isEmpty()){
			head = new Node<T>(value, nullptr);
			return;
		}
		while (temp->GetNextNode() != nullptr)
		{
			temp = temp->GetNextNode();
		}
		temp->GetNextNode() = new Node<T>(value, nullptr);
	}
	T RemoveLast(){
		if (isEmpty()) throw exception("Lista je prazna");
		Node<T> *last = head;
		Node<T> *beforeLast = nullptr;
		while (last->GetNextNode() != nullptr)
		{
			beforeLast = last;
			last = last->GetNextNode();
		} 
		T lastValue = last->GetValue();
		beforeLast->GetNextNode() = nullptr;
		delete last;
		return lastValue;
	}
	T RemoveValue(T value){
		if (isEmpty()) throw exception("Lista je prazna");

		bool success = true;
		Node<T> *info = head;
		Node<T> *beforeInfo = nullptr;
		while (info->GetNextNode() &&  info->GetValue() != value)
		{
			beforeInfo = info;
			info = info->GetNextNode();
		}
		if (info->GetValue() != value) return 2;
		if (beforeInfo != nullptr){
			beforeInfo->GetNextNode() = info->GetNextNode();
		}
		else {
			head = head->GetNextNode();
		}
		T v = info->GetValue();
		delete info;
		return v;
	}
	void DisplayAll(){
		Node<T> *temp = head;
		while (temp != nullptr)
		{
			cout << temp->GetValue() << " ";
			temp = temp->GetNextNode();
		}
	}
};

#endif
