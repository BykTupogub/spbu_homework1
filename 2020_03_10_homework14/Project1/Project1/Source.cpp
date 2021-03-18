#include<iostream>
#include <ctime>

using namespace std;

void swap(int& a, int& b);

void initArray(int* a, int len);

void printArray(int* a, int len);

void bubbleSort(int* a, int len);

void insertionSort(int* a, int len);

int main()
{
	srand(time(0));
	int len = 20;
	int* a = new int[len];

	initArray(a, len);
	printArray(a, len);
	cout << endl;
	bubbleSort(a, len);
	printArray(a, len);
	cout << endl;

	delete[] a;
	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void initArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = 1 + rand() % 100;
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
}

void bubbleSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void insertionSort(int* a, int len)
{
	int temp = 0;
	int item = 0;

	for (int i = 1; i < len; ++i)
	{
		temp = a[i];
		item = i - 1;
		while(item >= 0)
	}

}
