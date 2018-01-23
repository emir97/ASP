#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "BTNode.h"
using namespace std;

template <class T>
class BinaryTree
{
	void rekurzija_ReciklirajStablo(BTNode<T>*&  cvor)
	{
		if (cvor != nullptr)
		{
			rekurzija_ReciklirajStablo(cvor->desnoDijete);
			rekurzija_ReciklirajStablo(cvor->lijevoDijete);
			delete cvor;
			cvor = nullptr;
		}
	}
	BTNode<T>* rekurzija_Trazi(BTNode<T>* cvor, T value)
	{
		if (cvor == nullptr)
			return nullptr;

		if (IsJednako(cvor->value, value))
			return cvor;
		if (IsVece(cvor->value, value))//ili IsManje(value, cvor->value)
			return rekurzija_Trazi(cvor->lijevoDijete, value);
		else
			return rekurzija_Trazi(cvor->desnoDijete, value);
	}

	bool rekurzija_Dodaj(BTNode<T>* &cvor, T value)
	{
		if (cvor == nullptr)
		{
			cvor = new BTNode<T>(value);
			return true;
		}
		if (cvor->value == value)
			return false; 

		if (cvor->value > value)
		{
			return rekurzija_Dodaj(cvor->lijevoDijete, value);
		}
		else
		{
			return rekurzija_Dodaj(cvor->desnoDijete, value);
		}
	}

public:
	BinaryTree()
	{
		korijen = nullptr;
	}

	BTNode<T>*	korijen;

	bool dodaj(T value)
	{
		if (korijen == nullptr)
		{
			korijen = new BTNode<T>(value);
		}
		return rekurzija_Dodaj(korijen, value);
	}

	void reciklirajStablo()
	{
		rekurzija_ReciklirajStablo(korijen);
	}

	BTNode<T>* trazi(T value)
	{
		return rekurzija_Trazi(korijen, value);
	}

	bool sadrzi(T value)
	{

		return trazi(value) != nullptr;
	}

};
#endif