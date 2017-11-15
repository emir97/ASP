#include <iostream>
using namespace std;

#include "Queue.h"

int main(){
	
	Queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(1);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);
	queue.Enqueue(3);

	cout << queue.Dequeue() << " " << queue.Dequeue() << endl;
	queue.DispalyAll();
	getchar();
	return 0;
}