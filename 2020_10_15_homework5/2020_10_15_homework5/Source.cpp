#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ��������" << endl;
	cout << "1 - �������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������" << endl;
	cout << "2 - �������� � ������ 10 ��������� ������������� ���������� ����� � ������� ������" << endl;
	cout << "3 - �������� ������� ������ ����������� � ��������� ������������ ������� � ������� ������" << endl;
	cout << "4 - ���������� ��� �������� ������� � ������� ������" << endl;
	cout << "5 - �������� ������ ������������� ������� ������� �� 0" << endl;

}

void case1(ArrayList& a)
{
	for (int i = 0; i < 10; ++i)
	{
		a.add(rand() % (99 - 10 + 1) + 10);
	}
}

void case2(ArrayList& a)
{
	for (int i = 0; i < 10; ++i)
	{
		a.add(-(rand() % (99 - 10 + 1) + 10));
	}
}

void case3(ArrayList& a)
{
	int min = 0;
	int max = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a.get(i) < a.get(min))
		{
			min = i;
		}
		if (a.get(i) > a.get(max))
		{
			max = i;
		}
	}
	a.swap(max, min);
}

void case4(ArrayList& a)
{
	for (int i = 0; i < a.length(); ++i)
	{
		a.swap(i, rand() % a.length());
	}
}

void case5(ArrayList& a)
{
	for (int i = 0; i < a.length(); ++i)
	{
		if (a.get(i) < 0)
		{
			a.set(i, 0);
		}
	}
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
		case 1:
		{
			case1(a);
			cout << a.toString() << endl;
		}
		break;
		case 2:
		{
			case2(a);
			cout << a.toString() << endl;
		}
		break;
		case 3:
		{
			case3(a);
			cout << a.toString() << endl;
		}
		break;
		case 4:
		{
			case4(a);
			cout << a.toString() << endl;
		}
		break;
		case 5:
		{
			case5(a);
			cout << a.toString() << endl;
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
		
	return 0;
}