#ifndef HASH_H
#define HASH_H

#include "List.h"

template <class T>
class Hash
{
	T* Niz;
	int n;
	bool* zauzeto;
	int brojac;
	int IzracunajHash(T k)
	{
		return k % n;
	}
public:
	Hash(int n = 10)
	{
		this->n = n;
		Niz = new T[n];
		zauzeto = new bool[n];
		for (int i = 0; i<n; i++)
		{
			zauzeto[i] = false;
		}
		brojac = 0;
	}
	bool jelPun() { return brojac == n; }
	bool jelPrazan() { return brojac == 0; }
	void Dodaj(T k)
	{
		if (jelPun())
			throw std::exception("Hashset je pun.");
		int i = IzracunajHash(k);

		while (zauzeto[i])
		{
			i++;
			if (i == n)
				i = 0;
		}
		Niz[i] = k;
		zauzeto[i] = true;
		brojac++;
	}

	bool Ukloni(T k)
	{
		if (jelPrazan())
			return false;

		int i = IzracunajHash(k);
		int b = 0;
		while (b != n)
		{
			if (zauzeto[i])
			{
				if (Niz[i] == k)
				{
					zauzeto[i] = false;
					brojac--;
					return true;
				}
			}
			i++;
			b++; // uzeto b da ne bi doslo do neogranicene petlje 
			if (i == n)
				i = 0;
		}
		return false;
	}
	void Print()
	{
		for (int i = 0; i<n; i++)
		{
			if (zauzeto[i])
				std::cout << i << ": " << Niz[i] << std::endl;
			else
				std::cout << i << ": (x) " << std::endl;
		}
	}
};
#endif