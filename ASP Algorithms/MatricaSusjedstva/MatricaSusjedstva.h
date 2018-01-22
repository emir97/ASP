#ifndef MATRICASUSJEDSTVA_H
#define MATRICASUSJEDSTVA_H

#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Edge.h"
using namespace std;


class MatricaSusjedstva
{
	int** data;
	const int velicina;
public:
	// konstruktor postavlja sve na default vrijednosti
	MatricaSusjedstva(int v) : velicina(v)
	{
		data = new int*[v];
		for (int i = 0; i < v; i++)
		{
			data[i] = new int[v];
			for (int j = 0; j < v; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	int tezina(int from, int to) { return data[from][to]; }

	bool isSusjed(int from, int to) { return data[from][to] != 0; }
	// ucitava matricu iz fajla
	void UcitajMatricuFromFile(string filename)
	{
		ifstream f(filename);

		for (int i = 0; i < velicina; i++)
		{
			for (int j = 0; j < velicina; j++)
			{
				int u;
				f >> u;
				data[i][j] = u;
			}
		}

		f.close();
	}
	// ispis metrice susjedstva
	void ispisMatrice()
	{
		for (int i = 0; i < velicina; i++)
		{
			for (int j = 0; j < velicina; j++)
			{
				cout << data[i][j] << "\t";
			}
			cout << endl;
		}
	}
	// provjera da li je cvor povezan sam sa sobom
	bool provjera()
	{
		for (int i = 0; i < velicina; i++)
		{
			if (data[i][i] != 0)
				return false;
		}
		return true;
	}
	// racuna izlazni stepen za odredjeni cvor
	/*
	1	 1 2 3 4 5 6 7 8					
	2	|0|0|1|0|1|1|0|0|
	3	|0|0|1|0|1|1|0|0|
	4	|0|0|1|0|1|1|0|0| <- izlazni stepen za vrh 4 je 3
	5	|0|0|1|0|0|1|0|0|
	6	|0|0|1|0|1|0|0|0|
	7	|0|0|1|0|1|1|0|0|
	8	|0|0|1|0|1|1|0|0|

	Izlaz stepen je broj ivica koji izlaze iz cvora (za neusmjereni graf ulazni i izlazni stepen su jednaki).
	*/
	int izlazniStepen(int i)
	{
		int suma = 0;
		for (int j = 0; j < velicina; j++)
			suma += data[i][j];
		return suma;
	}
	// racuna ulazni stepen za odredjeni cvor
	/*
			   | <-   za vrh 4 ulazni stepen je 0
	1	 1 2 3 4 5 6 7 8
	2	|0|0|1|0|1|1|0|0|
	3	|0|0|1|0|1|1|0|0|
	4	|0|0|1|0|1|1|0|0|
	5	|0|0|1|0|0|1|0|0|
	6	|0|0|1|0|1|0|0|0|
	7	|0|0|1|0|1|1|0|0|
	8	|0|0|1|0|1|1|0|0|

	Ulazni stepen je broj ivica koji ulaze iz cvora (za neusmjereni graf ulazni i izlazni stepen su jednaki).
	*/
	int ulazniStepen(int i)
	{
		int suma = 0;
		for (int j = 0; j < velicina; j++)
			suma += data[j][i];
		return suma;
	}

	// vraca susjede za odredjeni vrh
	LinkedList<int>* SusjediTo(int i)
	{
		LinkedList<int>* x = new LinkedList<int>;
		for (int j = 0; j < velicina; j++)
		{
			if (data[i][j] != 0)
				x->AddValue(j);
		}
		return x;
	}
	// vraca susjede za odredjeni vrh 
	LinkedList<int>* SusjediFrom(int i)
	{
		LinkedList<int>* x = new LinkedList<int>;

		for (int j = 0; j < velicina; j++)
		{
			if (data[j][i] != 0)
				x->AddValue(i);
		}

		return x;
	}


	LinkedList<int>* izlazniStepenMax() 
	{
		
		int* stepeni = new int[velicina];
		for (int i = 0; i < velicina; i++)
		{
			stepeni[i] = izlazniStepen(i);
		}

		
		int maxVr = INT_MIN;
		for (int i = 0; i < velicina; i++)
		{
			if (stepeni[i] > maxVr)
				maxVr = stepeni[i];
		}
		
		LinkedList<int>* x = new LinkedList<int>;

		for (int i = 0; i < velicina; i++)
		{
			if (stepeni[i] == maxVr)
				x->AddValue(i);
		}
		return x;
	}

	int najbliziSusjed(int f)
	{
		LinkedList<int>* susjedi_to = SusjediTo(f);

		int minSusjed = -1;
		int minTezina = INT_MAX;

		for (int i = 0; i < susjedi_to->Size(); i++)
		{
			int s = susjedi_to->Get(i);
			int t = tezina(f, s);
			if (t < minTezina)
			{
				minTezina = t;
				minSusjed = s;
			}
		}

		return minSusjed;
	}
	void AddEdge(int vrhA, int vrhB, int tezina)
	{
		data[vrhA][vrhB] = tezina;
	}
	void AddEdge(Edge * ivica)
	{
		data[ivica->vrhA][ivica->vrhB] = ivica->tezina;
	}


};

#endif