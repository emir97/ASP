#ifndef NIVO_PO_NIVO_H
#define NIVO_PO_NIVO_H

#include "BinaryTree.h"
#include "List.h"
#include "Queue.h"

template <class T>
class NivoPoNivo
{
	NivoPoNivo()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}
	
	
public:

	static LinkedList<T>* NivoPoNivo_I(BinaryTree<T> &stablo)
	{

		LinkedList<T>* lista = new LinkedList<T>;

		Queue<BTNode<T>*> red;
		red.dodaj(stablo.korijen);

		while (!red.isPrazan())
		{
			BTNode<T>* cvor = red.ukloni();

			lista->AddValue(cvor->value);

			if (cvor->lijevoDijete != nullptr)
				red.dodaj(cvor->lijevoDijete);

			if (cvor->desnoDijete != nullptr)
				red.dodaj(cvor->desnoDijete);
		}

		return lista;
	}

};
#endif