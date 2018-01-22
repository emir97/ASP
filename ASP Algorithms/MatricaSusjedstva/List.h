#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <exception>
#include <string>
/*
	Lista samo sadrzi core funkcionalnosti potrebne za Grafove
*/
template<class T>
class LinkedList{
private:
	T* N;
	int brojac;
	int max;
	void prosiriListu()
	{
		int newMax = max * 2;
		T* novi = new T[newMax];
		for (int i = 0; i < max; i++)
		{
			novi[i] = N[i];
		}
		delete[] N;
		N = novi;
		max = newMax;
		cout << " LISTA: rekonstrukcija - nova velicina je " << newMax << endl;
	}
public:
	LinkedList(int max = 10)
	{
		this->max = max;
		N = new T[max];
		brojac = 0;
	}
	
	bool isPrazan(){ return (brojac == 0); }
	int Size() { return brojac; }

	void AddValue(T v)
	{
		if (max == brojac)
			prosiriListu();
		N[brojac] = v;
		brojac++;
	}
	void Print(string pre = "", string post = ", ")
	{
		int i = 0;
		while (i < brojac)
		{
			cout << pre << N[i++] << post;
		}
		cout << endl;
	}

	T& Get(int i)
	{
		if (i  > brojac)
			throw exception("indeks je veći od brojaca");
		return N[i];
	}
};

#endif