#ifndef PREORDER_H
#define PREORDER_H

#include "BinaryTree.h"
#include "List.h"

template <class T>
class PreOrder
{
	PreOrder()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}
	static void rekurzija_PreOrder(BTNode<T>* &cvor, LinkedList<T>* lista)
	{
		if (cvor != nullptr)
		{
			lista->AddValue(cvor->value);
			rekurzija_PreOrder(cvor->lijevoDijete, lista);
			rekurzija_PreOrder(cvor->desnoDijete, lista);
		}
	}
public:
	static LinkedList<T>* PreOrder_R(BinaryTree<T> &stablo)
	{
		LinkedList<T>* lista = new LinkedList<T>;
		rekurzija_PreOrder(stablo.korijen, lista);
		return lista;
	}

};
#endif