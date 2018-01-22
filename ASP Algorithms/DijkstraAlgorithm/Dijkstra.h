#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>

#include "List.h"
#include "Edge.h"
#include "MatricaSusjedstva.h"
using namespace std;


class Dijkstra
{

private:
	MatricaSusjedstva* M;

	int* dist;
	int* pred;
	bool* posjecen;

	int startVrh;
	int endVrh;

	Dijkstra(MatricaSusjedstva* M, int startVrh, int endVrh)
	{
		this->M = M;

		this->dist = new int[M->GetVelicina()];
		this->pred = new int[M->GetVelicina()];
		this->posjecen = new bool[M->GetVelicina()];

		this->startVrh = startVrh;
		this->endVrh = endVrh;
		//privatni konstruktor "zabranjuje" instanciranje ove klase izvan ove klase, tj. jedini nacin instaniranja ove
		//klase je preko public static funkcije koja se nalazi u ovoj klasi
	}

	int minNeposjecenVrh()
	{
		int minDist = INT_MAX;
		int minVrh = -1;   // nije povezan
		for (int i = 0; i < M->GetVelicina(); i++)
		{
			if (!posjecen[i] && dist[i] < minDist)
			{
				minVrh = i;
				minDist = dist[i];
			}
		}
		return minVrh;
	}

	LinkedList<Edge*>* _start()
	{

		cout << "startVrh: " << startVrh << ", endVrh: " << endVrh << endl;

		LinkedList<Edge*>* rezultat = new LinkedList <Edge*>;

		for (int i = 0; i < M->GetVelicina(); i++)
		{
			dist[i] = INT_MAX;
			posjecen[i] = false;
		}
		dist[startVrh] = 0;
		//==========================

		for (int i = 0; i < M->GetVelicina(); i++)
		{
			int nVrh = minNeposjecenVrh();
			posjecen[nVrh] = true;

			int nDist = dist[nVrh];
			for (int sVrh = 0; sVrh < M->GetVelicina(); sVrh++)
			{
				if (M->isSusjed(nVrh, sVrh))
				{
					int nsTezina = M->tezina(nVrh, sVrh);

					int xDist = nDist + nsTezina;

					if (xDist < dist[sVrh])
					{
						dist[sVrh] = xDist;
						pred[sVrh] = nVrh;
					}

				}
			}
		}

		int putDistanca = 0;
		int w = endVrh;
		while (w != startVrh)
		{
			int p = pred[w];
			int tezina = M->tezina(p, w);
			rezultat->AddValue(new Edge(p, w, tezina));
			putDistanca += tezina;
			w = p;
		}
		cout << "Ukupna distanca je: " << putDistanca << endl;

		return rezultat;
	}

public:
	static LinkedList<Edge*>* start(MatricaSusjedstva* M, int startVrh, int endVrh)
	{
		return Dijkstra(M, startVrh, endVrh)._start();
	}

};

#endif