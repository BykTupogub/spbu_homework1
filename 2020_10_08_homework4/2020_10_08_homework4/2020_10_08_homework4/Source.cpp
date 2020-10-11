#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
	cout << "4 - Удалить элемент по индексу" << endl;
	cout << "5 - Найти элемент" << endl;
	cout << "6 - Добавить несколько элементов" << endl;
	cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		int x = 1;
		cout << "введите элемент" << endl;
		cin >> x;
		while (x != 0)
		{
			a.add(x);
			cin >> x;
		}
	}
	break;
	case 3:
	{
		int x = 0;
		int index = 0;
		cout << "введите индекс и эемент" << endl;
		cin >> index >> x;
		a.add(index, x);
	}
	break;
	case 4:
	{
		cout << "введите индекс" << endl;
		int index = 0;
		cin >> index;
		bool case4 = a.remove(index);
		if (case4 == false)
		{
			cout << "ошибка";
		}
		 
	}
	break;
	case 5:
	{
		cout << "введите элемент" << endl;
		int element = 0;
		cin >> element;
		int case5 = a.indexOf(element);
		if (case5 != -1)
		{
			cout << "элемент " << element << "находиться под идексом " << case5 << endl;
		}
		else
		{
			cout << "элемент не найден" << endl;
		}
	}
	break;
	case 6:
	{
		ArrayList list;
		int x = 1;
		cout << "введите элементы" << endl;
		cin >> x;
		while (x != 0)
		{
			list.add(x);
			cin >> x;
		}
		a.addAll(list);
	}
	break;
	case 7:
	{
		ArrayList list;
		int x = 1;
		int index = 0;
		cout << "введите индекс" << endl;
		cin >> index;
		cout << "введите элементы" << endl;
		cin >> x;
		while (x != 0)
		{
			list.add(x);
			cin >> x;
		}
		bool case7 = a.addAll(index, list);
		if (case7 == false)
		{
			cout << "ошибка" << endl;
		} 
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
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