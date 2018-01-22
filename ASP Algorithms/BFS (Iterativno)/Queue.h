#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <class T>
class Queue
{
private:
	Node<T>* pocetak;
	Node<T>* kraj;
public:
	Queue()
	{
		pocetak = nullptr;
		kraj = nullptr;
	}
	void dodaj(T v)
	{
		Node<T>* t = new Node<T>(v, nullptr);
		if (!isPrazan())
		{
			kraj->GetNextNode() = t;
			kraj = t;
		}
		else
		{
			kraj = t;
			pocetak = t;
		}

	}

	T ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog reda.");

		Node<T>* t = pocetak;
		pocetak = pocetak->GetNextNode();

		T x = t->GetValue();
		delete t;


		if (pocetak == nullptr)
			kraj = nullptr;

		return x;

	}

	bool isPrazan()
	{
		return pocetak == nullptr;
	}
	void print(string pre = "", string post = ", ")
	{
		Node<T>* t = pocetak;
		while (t != nullptr)
		{
			cout << pre << t->GetValue() << post;
			t = t->GetNextNode();
		}
	}

	bool sadrzi(T v)
	{
		Node<T>* t = pocetak;
		while (t != nullptr)
		{
			if (t->GetValue() == v)
				return true;
			t = t->GetNextNode();
		}
		return false;
	}
};


#endif