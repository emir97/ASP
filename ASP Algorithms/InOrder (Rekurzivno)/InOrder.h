#ifndef INORDER_H
#define INRODER_H

#include "BinaryTree.h"
#include "List.h"


template <class T>
class InOrder
{
	InOrder()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}
	static void rekurzija_InOrder(BTNode<T>* &cvor, LinkedList<T>* lista)
	{
		if (cvor != nullptr)
		{
			rekurzija_InOrder(cvor->lijevoDijete, lista);
			lista->AddValue(cvor->value);
			rekurzija_InOrder(cvor->desnoDijete, lista);
		}
	}
	
public:

	static LinkedList<T>*  InOrder_R(BinaryTree<T> &stablo)
	{
		LinkedList<T>* lista = new LinkedList<T>;
		rekurzija_InOrder(stablo.korijen, lista);
		return lista;
	}



};
#endif