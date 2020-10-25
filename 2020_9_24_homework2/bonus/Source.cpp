
#include <iostream>

using namespace std;

void cinArr(int*& a, int& cap, int& count)
{
	while (true)
	{
		int x = 0;
		cin >> x;
		if (x == 0)
			break;
		if (count == cap)
		{
			cap *= 2;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
				temp[i] = a[i];
			delete[] a;
			a = temp;
		}

		a[count] = x;
		count++;
	}
}

void printArr(int* a, int const count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

int factorial(int const x)
{
	int y = 1;
	for (int i = 1; i <= x; ++i)
	{
		y *= i;
	}
	return y;
}

double meanFactorial(int* a, int const count) 
{
	double x = 0;
	for(int i = 0; i < count; i++)
	{
		x += factorial(a[i]);
	}
	x /= count;
	return x;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	int cap = 10;
	int* a = new int[cap];
	int count = 0;
	cinArr(a, cap, count);
	printArr(a, count);

	double x = meanFactorial(a, count);

	cout << "среднее арифметическое факториалов равно " << x << endl;

	delete[] a;
	return EXIT_SUCCESS;
}
