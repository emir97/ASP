#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <exception>
template<class T>
class Queue{
	T *data;
	int first;
	int last;
	int counter;
	int max;
public:
	Queue(){
		max = 50;
		data = new T[max];
		first = 0;
		last = 0;
		counter = 0;
	}
	Queue(int max){
		this->max = max;
		data = new T[max];
		first = 0;
		last = 0;
		counter = 0;
	}
	void Enqueue(T e){
		if (isFull()) throw exception("Red je pun");
		data[last++] = e;
		if (last == max) last = 0;
		counter++;
	}
	T Dequeue(){
		if (isEmpty()) throw exception("Red je prazan.");
		T temp = data[first++];
		if (first == max) first = 0;
		counter--;
		return temp;
	}
	void DispalyAll(){
		for (size_t i =	first; i < last; i++)
			cout << data[i] << " ";
	}
	bool isEmpty(){
		return counter == 0;
	}
	bool isFull(){
		return counter == max;
	}
};

#endif