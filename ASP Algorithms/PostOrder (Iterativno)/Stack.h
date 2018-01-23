#ifndef STACK_H
#define STACK_H

template <class T>
class Stack 
{
	int brojac;
	T* N;
	int max;
private:
	void prosiriStek()
	{
		int newMax = max * 2;
		T* novi = new T[newMax];
		for (int i = 0; i < max; i++)
		{
			novi[i] = N[i];
		}
		delete[] N;
		N = novi;
		max = newMax;
		cout << "\nSTEK: rekonstrukcija - nova velicina je " << newMax << endl;
	}
public:
	Stack(int max = 10)
	{
		this->max = max;
		this->brojac = 0;
		this->N = new T[max];

	}
	void dodaj(T v)
	{
		if (brojac == max)
		{
			prosiriStek();
		}
		N[brojac] = v;
		brojac++;
	}

	T ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog steka.");
		brojac--;
		T x = N[brojac];

		return x;
	}

	T vrh()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce uzeti elemenat iz praznog steka.");

		return N[brojac - 1];
	}

	bool isPrazan()
	{
		return brojac == 0;
	}

	void print(string pre = "", string post = ", ")
	{
		for (int i = 0; i < brojac; i++)
		{
			cout << pre << N[i] << post;
		}
	}

	bool sadrzi(T value)
	{
		for (int i = 0; i < brojac; i++)
		{
			if (IsJednako(N[i], value))
				return true;
		}
		return false;
	}
};




#endif