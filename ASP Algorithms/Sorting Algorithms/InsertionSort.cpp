#include <iostream>
using namespace std;

template<class T>
void InsertionSort(T numbers[], int size){
	int j;
	T temp;
	for (size_t i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && numbers[j - 1] > numbers[j])
		{
			temp = numbers[j - 1];
			numbers[j - 1] = numbers[j];
			numbers[j] = temp;
			j--;
		}
	}
}


int main(){

	int niz[10] = { 1, 54, 2, 6, 7, 7, 34, 2, 6, 8 };
	InsertionSort(niz, 10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << niz[i] << " ";
	}
	getchar();
	return 0;
}