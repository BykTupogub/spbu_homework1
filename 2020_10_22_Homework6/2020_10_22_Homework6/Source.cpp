#include<iostream>
#include "ArrayList.h"
using namespace std;


void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из меню" << endl;
	cout << "1 - Добавить элемент, введенный с клавиатуры" << endl;
	cout << "2 - Вывести массив" << endl;
	cout << "3 - Проверить, является ли массив симметричным" << endl;
	cout << "4 - Циклический сдвинуть массив на n элементов" << endl;
	cout << "5 - Проверить, может ли массив стать симметричным, если из него удалить один элемент" << endl << endl;

}



bool reverse(ArrayList& a, int const n = 0)
{
	if (n > a.length() - 1)
	{
		return false;
	}
	for (int i = 0; i < n / 2; ++i)
	{
		a.swap(i, n - 1 - i);
	}
	for (int i = n; i < ((a.length() + n) / 2); ++i)
	{
		a.swap(i, a.length() + n - 1 - i);
	}
	return true;
}

void case1(ArrayList& a)
{
	int x = 0;
	cout << "введите элемент:" << endl;
	cin >> x;
	while(x != 0)
	{
		a.add(x);
		cin >> x;
	}
	
}

bool case3(ArrayList a)
{
	for (int i = 0; i < a.length() / 2; ++i)
	{
		if (a.get(i) != a.get(a.length() - 1 - i))
		{
			return false;
		}
	}
	return true;
}

void case4(ArrayList& a, int n)
{
	n *= -1;
	if (n < 0)
	{
		n = n + a.length();
	}
	reverse(a, n);
	reverse(a);

}

bool case5(ArrayList a)
{
	
	for (int i = 0; i < a.length() / 2; ++i)
	{
		if (a.get(i) != a.get(a.length() - 1 - i))
		{
			for (i; i < a.length() / 2; ++i)
			{
				if (a.get(i + 1) != a.get(a.length() - 1 - i) && a.get(i) != a.get(a.length() - 2 - i))
				{
					return false;
				}
			}
		}
	}
	return true;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		case1(a);
	}
	break;
	case 2:
	{
		cout << a.toString() << endl;
	}
	break;
	case 3:
	{
		if (case3(a))
		{
			cout << "массив симметриный" << endl;
		}
		else
		{
			cout << "массив не симметриный" << endl;
		}
		
	}
	break;
	case 4:
	{
		int n = 0;
		cout << "ведите n:" << endl;
		cin >> n;
		case4(a, n);
	}
	break;
	case 5:
	{
		if (case5(a))
		{
			cout << "массив может стать симметриным" << endl;
		}
		else
		{
			cout << "массив не может стать симметриным" << endl;
		}
	}
	break;

	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	ArrayList a;

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}