#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <exception>
template<class T>
class Queue{
	T *data;
	int counter;
	int max;
public:
	Queue(){
		max = 50;
		data = new T[max];
		counter = 0;
	}
	Queue(int max){
		this->max = max;
		data = new T[max];
		counter = 0;
	}
	void Enqueue(T e){
		if (isFull()) throw exception("Red je pun");
		data[counter++] = e;
	}
	T Dequeue(){
		if (isEmpty()) throw exception("Red je prazan.");
		int maxIndex = 0;
		T max = data[0];

		for (int i = 1; i < counter; i++)
		{
			if (data[i] > max)
			{
				max = data[i];
				maxIndex = i;
			}
		}
		data[maxIndex] = data[counter - 1];
		counter--;

		return max;
	}
	void DispalyAll(){
		for (size_t i =	0; i < counter; i++)
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