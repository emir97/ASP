#ifndef HASH_H
#define HASH_H

#include "List.h"

template <class T>
class Hash
{
	LinkedList<T>* Niz;
	int n;
	int IzracunajHash(Tip k)
	{
		return k % n;
	}
public:
	Hash(int n = 10)
	{
		this->n = n;
		Niz = new LinkedList<T>[n];
	}
	void dodaj(Tip k)
	{
		int i = IzracunajHash(k);
		LinkedList<T>& lista = Niz[i];
		lista.AddValue(k);
	}
	bool ukloni(Tip k)
	{
		cout << "Uklonjeno: " << k << endl;
		int i = IzracunajHash(k);
		LinkedList<T>& lista = Niz[i];
		return lista.RemoveValue(k);
	}
	void print()
	{
		for (int i = 0; i<n; i++)
		{
			cout << "Lista " << i << ": ";
			Niz[i].Print();
			cout << endl;
		}
	}
};
#endif