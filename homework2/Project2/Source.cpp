
#include <iostream>
#include <ctime>
using namespace std;


void printMenu()
{
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b" << endl;
	cout << "2 - Развернуть массив" << endl;
	cout << "3 - Поменять элементы массива местами в парах" << endl;
	cout << "4 - Циклический сдвиг вправо на 1" << endl;
	cout << "5 - Развернуть две половинки массива. n - индекс элемента, разделяющего половинки" << endl;
}

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

void addNumber(int*& arr, int& cap, int& count, int const n, int const a, int const b)
{

	for (int i = 0; i < n; ++i)
	{
		if (count == cap)
		{
			++cap;
			int* temp = new int[cap];
			for (int i = 0; i < count; ++i)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}

		arr[count] = rand() % (b - a + 1) + a;
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

void reverse(int* a, int const count)
{
	int x = 0;
	for (int i = 0; i < count / 2; ++i)
	{
		x = a[i];
		a[i] = a[count - 1 - i];
		a[count - 1 - i] = x;
	}
}

void swap(int* a, int const count)
{
	int x = 0;
	for (int i = 0; i < count; i += 2)
	{
		if (i + 1 == count)
		{
			break;
		}
		x = a[i];
		a[i] = a[i + 1];
		a[i + 1] = x;
	}
}

void shift(int* a, int const count)
{
	int x = a[0];
	int y = 0;
	for (int i = 0; i < count - 1; ++i)
	{
		y = a[i + 1];
		a[i + 1] = x;
		x = y;
	}
	a[0] = x;
}

bool reverseN(int* a, int const count, int const n)
{
	if (n > count - 1)
	{
		return 0;
	}
	int x = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		x = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = x;
	}

	for (int i = n + 1; i < count / 2; ++i)
	{
		x = a[i];
		a[i] = a[count - 1 - i];
		a[count - 1 - i] = x;
	}
	return 1;
}







int main(int argc, char* argv[])
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int cap = 10;
	int* a = new int[cap];
	int count = 0;
	cinArr(a, cap, count);
	printArr(a, count);



	int choice = -1;
	while (choice != 0)
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			int n = 0;
			int aa = 0;
			int b = 0;
			cout << "введите n" << endl;
			cin >> n;
			cout << "введите a и b" << endl;
			cin >> aa >> b;
			addNumber(a, cap, count, n, aa, b);
			printArr(a, count);
			break;
		}
		case 2:
		{
			system("cls");
			reverse(a, count);
			printArr(a, count);
			break;
		}
		case 3:
		{
			system("cls");
			swap(a, count);
			printArr(a, count);
			break;
		}
		case 4:
		{
			system("cls");
			shift(a, count);
			printArr(a, count);
			break;
		}
		case 5:
		{
			system("cls");
			int n = 0;
			cout << "введите n" << endl;
			cin >> n;
			while (reverseN(a, count, n) != 1)
			{
				cout << "введите n < " << count << endl;
				cin >> n;
			}
			printArr(a, count);
			break;
		}
		}
	}

	delete[] a;
	return EXIT_SUCCESS;
}