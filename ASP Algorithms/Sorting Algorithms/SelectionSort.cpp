#include <iostream>
using namespace std;

template<class T>
void SelectionSort(T numbers[], int size){
	int j, minIndex;
	T temp;
	for (size_t i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (size_t j = i + 1; j < size; j++)
			if (numbers[j] < numbers[minIndex])
				minIndex = j;
		if (minIndex != i){
			temp = numbers[i];
			numbers[i] = numbers[minIndex];
			numbers[minIndex] = temp;
		}
	}
}


int main(){

	int niz[10] = { 1, 54, 2, 6, 7, 7, 34, 2, 6, 8 };
	SelectionSort(niz, 10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << niz[i] << " ";
	}
	getchar();
	return 0;
}