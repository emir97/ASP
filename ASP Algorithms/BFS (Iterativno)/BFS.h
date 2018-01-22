#pragma once

#include <iostream>

#include "Queue.h"
#include "List.h"
#include "MatricaSusjedstva.h"
using namespace std;

class BfsAlgoritamIterativno
{
private:
	int starVrh;
	MatricaSusjedstva* M;

	BfsAlgoritamIterativno(MatricaSusjedstva* M, int starVrh)
	{
		this->M = M;
		this->starVrh = starVrh;
	}

	LinkedList<int>* _start()
	{
		this->M = M;
		LinkedList<int>* posjecen = new LinkedList<int>(M->GetVelicina());

		Queue<int> red;

		//dodaj početni vrh u stek
		red.dodaj(starVrh);

		while (!red.isPrazan())
		{
			int v = red.ukloni();

			if (!posjecen->Sadrzi(v))
			{
				posjecen->AddValue(v);

				for (int i = 0; i < M->GetVelicina(); i++)
				{
					//ako je vrh "i" susjed
					if (M->isSusjed(v, i))
					{
						//dodatno opcionalno poboljšanje: "!red.sadrzi(i)"
						if (!red.sadrzi(i) && !posjecen->Sadrzi(i))
							red.dodaj(i);
					}
				}
			}
		}

		return posjecen;
	}

public:
	static LinkedList<int>* start(MatricaSusjedstva* M, int startVrh = 0)
	{
		return BfsAlgoritamIterativno(M, startVrh)._start();
	}
};