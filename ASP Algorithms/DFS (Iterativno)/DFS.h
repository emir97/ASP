#ifndef DFS_H
#define DFS_H

#include <iostream>

#include "Stack.h"
#include "List.h"
#include "MatricaSusjedstva.h"

using namespace std;

class DfsAlgoritamIterativno
{
private:
	int starVrh;
	MatricaSusjedstva* M;

	DfsAlgoritamIterativno(MatricaSusjedstva* M, int starVrh)
	{
		this->M = M;
		this->starVrh = starVrh;
		//privatni konstruktor "zabranjuje" instanciranje ove klase izvan ove klase, tj. jedini naèin instaniranja ove klase je preko public static funkcije koja se nalazi u ovoj klasi
	}

	LinkedList<int>* _start()
	{
		this->M = M;
		LinkedList<int>* posjecen = new LinkedList<int>(M->GetVelicina());

		Stack<int> stek;

		stek.dodaj(starVrh);

		while (!stek.isPrazan())
		{
			int v = stek.ukloni();

			if (!posjecen->Sadrzi(v))
			{
				posjecen->AddValue(v);

				for (int i = M->GetVelicina() - 1; i >= 0; i--)
				{
					if (M->isSusjed(v, i))
					{
						if (!posjecen->Sadrzi(i))
							stek.dodaj(i);
					}
				}
			}
		}

		return posjecen;
	}

public:
	static LinkedList<int>* start(MatricaSusjedstva* M, int starVrh = 0)
	{
		return DfsAlgoritamIterativno(M, starVrh)._start();
	}
};
#endif