#ifndef PREORDER_H
#define PREORDER_H

#include "BinaryTree.h"
#include "List.h"
#include "Stack.h"


template <class T>
class PreOrder
{
	PreOrder()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}

public:

	static LinkedList<T>* PreOrder_I(BinaryTree<T> &stablo)
	{

		LinkedList<T>* lista = new LinkedList<T>;

		Stack<BTNode<T>*> stek;
		stek.dodaj(stablo.korijen);

		while (!stek.isPrazan())
		{
			BTNode<T>* cvor = stek.ukloni();


			lista->AddValue(cvor->value);

			if (cvor->desnoDijete != nullptr)
				stek.dodaj(cvor->desnoDijete);

			if (cvor->lijevoDijete != nullptr)
				stek.dodaj(cvor->lijevoDijete);
		}

		return lista;
	}

};
#endif