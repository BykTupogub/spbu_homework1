#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
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
		cout << "������� �������" << endl;
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
		cout << "������� ������ � ������" << endl;
		cin >> index >> x;
		a.add(index, x);
	}
	break;
	case 4:
	{
		cout << "������� ������" << endl;
		int index = 0;
		cin >> index;
		bool case4 = a.remove(index);
		if (case4 == false)
		{
			cout << "������";
		}
		 
	}
	break;
	case 5:
	{
		cout << "������� �������" << endl;
		int element = 0;
		cin >> element;
		int case5 = a.indexOf(element);
		if (case5 != -1)
		{
			cout << "������� " << element << "���������� ��� ������� " << case5 << endl;
		}
		else
		{
			cout << "������� �� ������" << endl;
		}
	}
	break;
	case 6:
	{
		ArrayList list;
		int x = 1;
		cout << "������� ��������" << endl;
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
		cout << "������� ������" << endl;
		cin >> index;
		cout << "������� ��������" << endl;
		cin >> x;
		while (x != 0)
		{
			list.add(x);
			cin >> x;
		}
		bool case7 = a.addAll(index, list);
		if (case7 == false)
		{
			cout << "������" << endl;
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