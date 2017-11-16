#include <iostream>
using namespace std;

#include "Queue.h"

int main(){
	
	Queue<int> queue;
	queue.Enqueue(13);
	queue.Enqueue(17);
	queue.Enqueue(100);
	queue.Enqueue(13);
	queue.Enqueue(1);

	cout << queue.Dequeue() << endl;
	cout << queue.Dequeue() << endl;

	queue.DispalyAll();

	getchar();
	return 0;
}