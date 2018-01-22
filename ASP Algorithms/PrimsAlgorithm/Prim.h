#ifndef PRIM_H
#define PRIM_H

#include <iostream>

#include "List.h"
#include "Hash.h"
#include "Edge.h"
using namespace std;



class Prim
{
private:
	int startVrh;
	MatricaSusjedstva* M;
	LinkedList<int>* stabloVrhovi;
	LinkedList<Edge*>* stabloIvice;

	Prim(MatricaSusjedstva* M, int startVrh)
	{
		this->M = M;
		this->startVrh = startVrh;
		this->stabloIvice = new LinkedList<Edge*>;
		this->stabloVrhovi = new LinkedList<int>;
	}


	Edge* pripremiIvicu()
	{
		Edge* ivica = new Edge;
		ivica->tezina = INT_MAX;


		for (int fIndex = 0; fIndex < stabloVrhovi->Size(); fIndex++)
		{
			int fVrh = stabloVrhovi->Get(fIndex);

			LinkedList<int>* susjediLista = M->SusjediTo(fVrh);

			int minSTezina = INT_MAX;
			int minSVrh = -1;

			for (int sIndex = 0; sIndex < susjediLista->Size(); sIndex++)
			{
				int sVrh = susjediLista->Get(sIndex);
				if (stabloVrhovi->Sadrzi(sVrh))
					continue;

				int tezina = M->tezina(fVrh, sVrh);

				if (tezina < minSTezina)
				{
					minSTezina = tezina;
					minSVrh = sVrh;
				}
			}
			if (minSTezina < ivica->tezina)
			{
				ivica->tezina = minSTezina;
				ivica->vrhA = fVrh;
				ivica->vrhB = minSVrh;
			}

		}

		return ivica;
	}

	LinkedList<Edge*>* _start()
	{
		//PRIM počinje od proizvoljnog vrha, npr. prvi vrh
		stabloVrhovi->AddValue(startVrh);

		int s = 0;
		for (int brojac = 0; brojac < M->GetVelicina() - 1; brojac++)
		{
			Edge* i = pripremiIvicu();
			stabloIvice->AddValue(i);

			//s obzirom što se početak ivice uvjek nalazi u stablu-u onda je potrebno dodati samo kraj ivice.
			stabloVrhovi->AddValue(i->vrhB);
			s += i->tezina;
		}
		cout << "Prim Algoritam: MST suma je " << s << endl;
		return stabloIvice;
	}
public:
	static LinkedList<Edge*>* start(MatricaSusjedstva* M, int startVrh = 0)
	{
		return Prim(M, startVrh)._start();
	}
};

#endif