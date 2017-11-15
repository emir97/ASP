#include <iostream>
using namespace std;

template<class T>
void BubbleSort(T numbers[], int size){
	bool promjena = true;
	T temp;
	int j = 0;
	while (promjena)
	{
		promjena = false;
		j++;
		for (size_t i = 0; i < size - j; i++)
		{
			if (numbers[i] > numbers[i + 1]){
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				promjena = true;
			}
		}
	}
}


int main(){

	int niz[10] = { 1, 54, 2, 6, 7, 7, 34, 2, 6, 8 };
	BubbleSort(niz, 10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << niz[i] << " ";
	}
	getchar();
	return 0;
}