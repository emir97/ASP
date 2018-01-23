#ifndef POST_ORDER_H
#define POST_ORDER_H

#include "BinaryTree.h"
#include "List.h"
#include "Stack.h"
template <class T>
class PostOrder
{
	PostOrder()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}

public:

	static LinkedList<T>* PostOrder_I(BinaryTree<T> &stablo)
	{
		
		LinkedList<T>* lista = new LinkedList<T>;
		Stack<T>* rezultat = new Stack<T>;

		Stack<BTNode<T>*> stek;
		stek.dodaj(stablo.korijen);

		while (!stek.isPrazan())
		{
			BTNode<T>* cvor = stek.ukloni();
			if (cvor != nullptr)
			{
				rezultat->dodaj(cvor->value);
				stek.dodaj(cvor->lijevoDijete);
				stek.dodaj(cvor->desnoDijete);
			}
		}

		while (!rezultat->isPrazan())
		{
			lista->AddValue(rezultat->ukloni());
		}

		return lista;
	}
};
#endif