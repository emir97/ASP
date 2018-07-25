
#ifndef __PR_H__
#define __PR_H__

template <class Tip>
class PrioritetniRed 
{
public:
	virtual void dodaj(Tip v) = 0;
	virtual Tip ukloni() = 0;
	virtual bool IsPrazan() = 0;
	virtual void print() = 0;
};


#endif