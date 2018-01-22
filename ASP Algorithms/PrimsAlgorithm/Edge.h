#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <string>

using namespace std;

struct Edge
{

	int vrhA;
	int vrhB;
	int tezina;
public:
	Edge()
	{

	}
	Edge(int vrhA, int vrhB, int tezina)
	{
		this->vrhA = vrhA;
		this->vrhB = vrhB;
		this->tezina = tezina;
	}
	friend ostream& operator<<(ostream& o, Edge* i)
	{
		return operator<<(o, *i);
	}
	friend ostream& operator<<(ostream& o, Edge& i)
	{
		o << "t(" << i.vrhA << "," << i.vrhB << ") = " << i.tezina;
		return o;
	}

	friend bool operator>(Edge& left, Edge& right)
	{
		return left.tezina < right.tezina;
	}
};

#endif