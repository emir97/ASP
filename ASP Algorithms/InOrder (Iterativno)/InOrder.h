#ifndef INORDER_H
#define INRODER_H

#include "BinaryTree.h"
#include "List.h"
#include "Stack.h"


template <class T>
class InOrder
{
	InOrder()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}

	
public:

	static LinkedList<T>* InOrder_I(BinaryTree<T> &stablo)
	{
		
		LinkedList<T>* lista = new LinkedList<T>;

		BTNode<T>* current = stablo.korijen;

		Stack<BTNode<T>*> stek;

		while (true)
		{
			if (current != nullptr)
			{
				stek.dodaj(current);
				current = current->lijevoDijete;
			}
			else
			{
				if (stek.isPrazan())
					break;

				current = stek.ukloni();
				lista->AddValue(current->value);
				current = current->desnoDijete;
			}
		}
		return lista;
	}



};
#endif