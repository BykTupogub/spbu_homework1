#include <iostream>
using namespace std;
void printMenu()
{
    cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� ����� � ������" << endl;
	cout << "2 - ������� ������ �� �����" << endl;
	cout << "3 - ����� ����� ������������� �������� �������" << endl;
	cout << "4 - ����� ����������� ������� �������" << endl;
	cout << "5 - ��������� ����� ��������� �������" << endl;
	cout << "6 - ������� ������ � �������� �������" << endl;
}

void expendArr(int*& a, int& cap, int& count)
{
	cap *= 2;
	int* temp = new int[cap];
	for (int i = 0; i < count; ++i)
		temp[i] = a[i];
	delete[] a;
	a = temp;
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
			expendArr(a, cap, count);
		}

		a[count] = x;
		count++;
	}
}



void addNumber(int* &a,  int &cap, int &count)
{
	
	int x = 0;
	cin >> x;
	if (count == cap)
	{
		cap++;
		int* temp = new int[cap];
		for (int i = 0; i < count; ++i)
			temp[i] = a[i];
		delete[] a;
		a = temp;
	}

	a[count] = x;
	count++;
}

void printArr(int* a, int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

int searchMaxI(int* a,int count)
{
	int max = 0;
	for (int i = 0; i < count; ++i)
	{
		if (a[i] > a[max])
			max = i;
	}

	return max;
}

int searchMin(int* a, int count)
{
	int min = a[0];
	for (int i = 0; i < count; ++i)
	{
		if (a[i] < min)
			min = a[i];
	}

	return min;
}

int sumArr(int* a, int count)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += a[i];
	}

	return sum;
}
void reversePrint(int* a, int count)
{
	for (int i = count-1; i >= 0; --i)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

void menu(int*& a, int& cap, int& count)
{
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
			addNumber(a, cap, count);
			break;
		}
		case 2:
		{
			system("cls");
			printArr(a, count);
			break;
		}
		case 3:
		{
			system("cls");
			cout << "����� ������������� ������� ����� " << searchMaxI(a, count) << endl << endl;
			break;
		}
		case 4:
		{
			system("cls");
			cout << "����������� ������ ����� " << searchMin(a, count) << endl << endl;
			break;
		}
		case 5:
		{
			system("cls");
			cout << "����� ��������� ������� ����� " << sumArr(a, count) << endl << endl;
			break;
		}
		case 6:
		{
			system("cls");
			reversePrint(a, count);
			break;
		}
		}
	}
}



int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    
	int cap = 10;
	int* a = new int[cap];
	int count = 0;
	cinArr(a, cap, count);

	menu(a, cap, count);

	delete[] a;
    return EXIT_SUCCESS;
}