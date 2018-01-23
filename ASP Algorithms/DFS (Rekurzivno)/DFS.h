#ifndef DFS_H
#define DFS_H

#include <iostream>

#include "List.h"
#include "MatricaSusjedstva.h"
using namespace std;

class DfsAlgoritamRekurzija
{
private:
	int starVrh;
	MatricaSusjedstva* M;
	LinkedList<int>* posjecen;

	DfsAlgoritamRekurzija(MatricaSusjedstva* M, int starVrh)
	{
		this->M = M;
		this->posjecen = new LinkedList<int>;
		this->starVrh = starVrh;

	}

	LinkedList<int>* _start()
	{
		Rekurzija(starVrh);
		return posjecen;
	}

	void Rekurzija(int v)
	{
		posjecen->AddValue(v);
		for (int i = 0; i < M->GetVelicina(); i++)
		{
			if (M->isSusjed(v, i) && !posjecen->Sadrzi(i))
				Rekurzija(i);
		}
	}

public:
	static LinkedList<int>* start(MatricaSusjedstva* M, int starVrh = 0)
	{
		return DfsAlgoritamRekurzija(M, starVrh)._start();
	}
};
#endif