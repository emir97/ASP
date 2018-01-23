#ifndef POST_ORDER_H
#define POST_ORDER_H

#include "BinaryTree.h"
#include "List.h"
template <class T>
class PostOrder
{
	PostOrder()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}
	static void rekurzija_PostOrder(BTNode<T>* &cvor, LinkedList<T>* lista)
	{
		if (cvor != nullptr)
		{
			rekurzija_PostOrder(cvor->lijevoDijete, lista);
			rekurzija_PostOrder(cvor->desnoDijete, lista);
			lista->AddValue(cvor->value);
		}
	}
public:

	static LinkedList<T>* PostOrder_R(BinaryTree<T> &stablo)
	{
		LinkedList<T>* lista = new LinkedList<T>;
		rekurzija_PostOrder(stablo.korijen, lista);
		return lista;
	}
};
#endif