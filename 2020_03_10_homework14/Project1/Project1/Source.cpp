#include<iostream>
#include <ctime>

using namespace std;

struct SandP {
	float s;
	float p;
	void sum(SandP b)
	{
		p += b.p;
		s += b.s;
	}
};

void swap(int& a, int& b);

void rowArray(int* a, int len);

void initArray(int* a, int len);

void printArray(int* a, int len);

SandP bubbleSort(int* a, int len);

SandP insertionSort(int* a, int len);

SandP choicesSort(int* a, int len);

void average(int* a, int len);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int* a20 = new int[20];

	initArray(a20, 20);
	printArray(a20, 20);
	cout << endl;
	bubbleSort(a20, 20);
	printArray(a20, 20);
	cout << endl;

	initArray(a20, 20);
	printArray(a20, 20);
	cout << endl;
	insertionSort(a20, 20);
	printArray(a20, 20);
	cout << endl;

	initArray(a20, 20);
	printArray(a20, 20);
	cout << endl;
	choicesSort(a20, 20);
	printArray(a20, 20);
	cout << endl;

	int* a5 = new int[5];
	average(a5, 5);
	cout << endl;
	int* a10 = new int[10];
	average(a5, 10);
	cout << endl;
	int* a15 = new int[15];
	average(a15, 15);
	cout << endl;
	average(a20, 20);

	delete[] a5;
	delete[] a10;
	delete[] a15;
	delete[] a20;
	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void rowArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}
}

void backRowArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = len - i;
	}
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

SandP bubbleSort(int* a, int len)
{
	SandP bubble;
	bubble.s = 0;
	bubble.p = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{

			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				++bubble.p;
			}
			++bubble.s;
		}
	}
	return bubble;
}

SandP insertionSort(int* a, int len)
{
	SandP insert;
	insert.s = 0;
	insert.p = 0;
	int temp = 0;
	int j = 0;

	for (int i = 1; i < len; ++i)
	{
		
		j = i - 1;
		while (j >= 0 && a[j] > a[j+1])
		{
			swap(a[j + 1], a[j]);
			--j;
			++insert.p;
			++insert.s;
		}
	}
	return insert;
}

SandP choicesSort(int* a, int len)
{
	SandP choice;
	choice.s = 0;
	choice.p = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				++choice.p;
			}
			++choice.s;
		}
	}
	return choice;
}

void average(int* a, int len)
{
	cout << "проверка для длины " << len << endl;

	SandP bubble;
	bubble.s = 0;
	bubble.p = 0;

	SandP insert;
	insert.s = 0;
	insert.p = 0;

	SandP choice;
	choice.s = 0;
	choice.p = 0;

	for (int i = 0; i < 1000; ++i)
	{
		initArray(a, len);
		bubble.sum(bubbleSort(a, len));

		initArray(a, len);
		insert.sum(insertionSort(a, len));

		initArray(a, len);
		choice.sum(choicesSort(a, len));
	}

	bubble.s /= 1000;
	bubble.p /= 1000;
	cout << bubble.p << "  - Среднее количество перестановок для bubbleSort" << endl;
	cout << bubble.s << " - Среднее количество сравнений для bubbleSort" << endl;

	insert.s /= 1000;
	insert.p /= 1000;
	cout << insert.p << "  - Среднее количество перестановок для insertionSort" << endl;
	cout << insert.s << " - Среднее количество сравнений для insertionSort" << endl;

	choice.s /= 1000;
	choice.p /= 1000;
	cout << choice.p << "  - Среднее количество перестановок для choicesSort" << endl;
	cout << choice.s << " - Среднее количество сравнений для choicesSort" << endl;
}
