#ifndef NODE_H
#define NODE_H
template<class T>
class Node{
	T value;
	Node<T> *nextNode;
public:
	Node(T value, Node<T> *next){
		this->value = value;
		this->nextNode = next;
	}
	T GetValue(){ return value; }
	Node<T> *&GetNextNode(){ return nextNode; }
};

#endif