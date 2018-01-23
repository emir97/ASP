#ifndef BTNODE_H
#define BTNODE_H

template <class T>
struct BTNode
{
	T value;
	BTNode* lijevoDijete;
	BTNode* desnoDijete;

	BTNode(T value)
	{
		this->value = value;
		this->lijevoDijete = nullptr;
		this->desnoDijete = nullptr;
	}
};
#endif