#include <iostream>
using namespace std;
void Swap(int N[], const int i, const int j)
{
	if (i != j)
	{
		int temp = N[i];
		N[i] = N[j];
		N[j] = temp;
	}
}

void QuickSort(int N[], const int low, const int high)
{
	if (low < high)
	{
		int pivotloc = low;
		int pivotkey = N[low];
		for (int i = low + 1; i <= high; i++)
		{
			if (N[i] < pivotkey)
			{
				pivotloc++;
				Swap(N, pivotloc, i);
			}
		}

		Swap(N, low, pivotloc);

		QuickSort(N, low, pivotloc - 1);
		QuickSort(N, pivotloc + 1, high);
	}
}

void ispis(int A[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << A[i] << endl;
	}
}

int main()
{
	int A[] = { 24, 13, 6, 75, 9, 63, 19, 20 };
	int brE = 8;

	cout << "NESORTIRANI NIZ:" << endl;
	ispis(A, brE);

	QuickSort(A, 0, brE - 1);

	cout << endl << "SORTIRANI NIZ" << endl;
	ispis(A, brE);



	getchar();
	return 0;
}