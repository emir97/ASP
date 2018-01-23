#ifndef KRUSKAL_H
#define KRUSKAL_H


#include <iostream>

#include "List.h"
#include "Queue.h"
#include "Edge.h"
#include "MatricaSusjedstva.h"
#include "BFS.h"
using namespace std;

class KruskalAlgoritam
{
private:
	KruskalAlgoritam(MatricaSusjedstva* M)
	{
		//ulazna matrica susjedstva
		grafMatrica = M;

		//PR koji èuva sortirane ivice koje su formirane na osnovu ulazne matrice susjedstva 
		grafIvice = new Queue<Edge*>;

		//ovo je rezultat algoritma (stablo minimalnog raspona, MST)
		stabloIvice = new LinkedList<Edge*>;

		//pomoæa matrica susjedstva za stablo (MST) koja se koristi radi Dfs i Bfs algoritma kod provjere ciklusa	
		stabloMatrica = new MatricaSusjedstva(M->GetVelicina());
	}

	MatricaSusjedstva* grafMatrica;
	Queue<Edge*>* grafIvice;

	MatricaSusjedstva* stabloMatrica;
	LinkedList<Edge*>* stabloIvice;

	void pripremiIvice()
	{
		for (int fromVrh = 0; fromVrh < grafMatrica->GetVelicina(); fromVrh++)
		{
			LinkedList<int>* susjedi = grafMatrica->SusjediTo(fromVrh);
			for (int toIndex = 0; toIndex < susjedi->Size(); toIndex++)
			{
				int toVrh = susjedi->Get(toIndex);
				int tezina = grafMatrica->tezina(fromVrh, toVrh);
				Edge* ivica = new Edge(fromVrh, toVrh, tezina);
				grafIvice->dodaj(ivica);
			}
		}
	}

	bool isCiklus(Edge* i)
	{
		LinkedList<int>* lista = BfsAlgoritamIterativno::start(stabloMatrica, i->vrhB);
		return lista->Sadrzi(i->vrhA);
	}

	LinkedList<Edge*>* _start()
	{
		pripremiIvice();

		int brojac = 0;
		int s = 0;

		while (brojac < (stabloMatrica->GetVelicina()) - 1)
		{
			Edge* i = grafIvice->ukloni();

			if (!isCiklus(i))
			{
				stabloIvice->AddValue(i);
				stabloMatrica->AddEdge(i);
				s += i->tezina;
				brojac++;
			}
		}
		cout << "Kruskal Algoritam: MST suma je " << s << endl;

		return stabloIvice;
	}

public:

	static LinkedList<Edge*>* start(MatricaSusjedstva* M)
	{
		return KruskalAlgoritam(M)._start();
	}
};

#endif