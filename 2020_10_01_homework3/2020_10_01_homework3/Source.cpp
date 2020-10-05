#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������ ��������� ��������� � ����������" << endl;
	cout << "2 - �������� � ������ n ��������� ����� � ���������� �� a �� b(n, a, b �������� � ����������)" << endl;
	cout << "3 - ������� ������ �� �����" << endl;
	cout << "4 - ����� ������� ��������" << endl;
	cout << "5 - ���������� ������ � �������" << endl;
	cout << "6 - ����������� ��������" << endl;
	cout << "7 - ������� �������� � ������" << endl;
	cout << "8 - �������� ���������� ������ ������ ��������� �������" << endl;
	cout << "9 - ����� ���������������������" << endl;
}

int* initArray(int capacity = 10)
{
	int* result = new int[capacity + 2]{ 0 };
	*(result + 1) = 10;
	result += 2;
	return result;
}

void clearArray(int*& arr)
{
	for (int i = 0; i < *(arr - 2); i++)
	{
		*(arr + i) = 0;
	}
	*(arr - 2) = 0;
}


void deleteArray(int* arr)
{
	arr -= 2;
	delete[] arr;
}

void expandArray(int*& arr)
{
	int* temp = initArray(*(arr - 1) * 2);
	for (int i = 0; i < arr[-1]; i++)
	{
		*(temp + i) = *(arr + i);
	}

	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

void addElement(int*& arr, int element)
{
	if (*(arr - 1) == *(arr - 2))
	{
		expandArray(arr);
	}
	*(arr + *(arr - 2)) = element;
	++* (arr - 2);
}

void addRandomElements(int*& arr, int n, int min, int max)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(arr, rand() % (max - min + 1) + min);
	}
}

void printArray(int* arr)
{
	cout << "[" << arr[-2] << "/" << arr[-1] << "] {";
	for (int i = 0; i < *(arr - 2); ++i)
	{
		cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
	}
}

int search(int* arr, int element, int start = 0)
{
	int result = -1;
	for (int i = start; i < *(arr - 2); i++)
	{
		if (element == *(arr + i))
		{
			result = i;
			break;
		}
	}
	return result;
}

void add(int*& arr, int* addedArr)
{
	for (int i = 0; i < *(addedArr - 2); i++)
	{
		addElement(arr, *(addedArr + i));
	}
}

int* unify(int* a, int* b)
{
	int* result = new int[*(a - 2) + *(b - 2) + 2]{ 0 };
	result += 2;
	result[-1] = *(a - 2) + *(a - 2);
	result[-2] = 0;
	for (int i = 0; i < *(result - 1); i++)
	{
		if ((i % 2 == 0) & (i / 2 < *(a - 2)))
		{
			addElement(result, *(a + i / 2));
		}
		else if (i / 2 < *(b - 2))
		{
			addElement(result, *(b + i / 2));
		}
	}

	return result;
}

int extract(int* a, int index)
{

	int returns = -1;

	if ((index < a[-2]) & (index > -1))
	{
		returns = a[index];
		for (int i = index; i < *(a - 2) - 1; i++)
		{
			a[i] = *(a + i + 1);
		}
		*(a + *(a - 2) - 1) = 0;
		--* (a - 2);
	}
	return returns;
}

int insert(int*& a, int index, int element)
{
	int* temp = new int[*(a - 2) + 3];
	temp += 2;
	int returns = 1;
	if ((index <= *(a - 2)) & (index > -1))
	{
		returns = 0;
		*(temp - 2) = *(a - 2) + 1;
		for (int i = -1; i < a[-2] + 1; i++)
		{
			if (i < index)
			{
				*(temp + i) = *(a + i);
			}
			else if (i > index)
			{
				*(temp + i) = *(a + i - 1);
			}
			else if (i == index)
			{
				*(temp + i) = element;
			}
		}
		deleteArray(a);
		a = temp;
	}

	return returns;
}


int deleteGroup(int* a, int startIndex, int count)
{
	int returns = 1;
	if ((startIndex > -1) & ((startIndex + count) < *(a - 2)))
	{
		returns = 0;
		for (int i = 0; i < count; i++)
		{
			extract(a, startIndex);
		}
	}

	return returns;
}

/// <summary>
/// ����� ��������������������� � �������
/// </summary>
/// <param name="a">������, � ������� ���� ���������������������</param>
/// <param name="b">������� ���������������������</param>
/// <returns>������ ������ ��������������������� ��� -1, ���� ������� ���</returns>
int subSequence(int* a, int* b)
{
	int returns = -1;
	int i = 0;
	while (search(a, *b, i) <= (*(a-2) - *(b-2)))
	{
		returns = search(a, *b, i);
		for (int j = 0; j < *(b - 2); j++)
		{
			if (*(a + search(a, *b, i) + j) != *(b + j))
			{
				returns = -1;
			}
		}
		if (returns != -1)
		{
			return returns;
		}
		++i;
	}


	return returns;
}


void processChoice(int*& arr1, int*& arr2, int choice)
{
	switch (choice)
	{
	case 1:
	{
		int x = 0;
		cout << "������� ��������:" << endl;
		cin >> x;
		while (x != 0)
		{
			addElement(arr1, x);
			cin >> x;
		}
		printArray(arr1);
		break;
	}

	case 2:
	{
		int n = 0;
		int max = 0;
		int min = 0;
		cout << "������� n, a, b:" << endl;
		cin >> n >> min >> max;
		addRandomElements(arr1, n, min, max);
		printArray(arr1);
		break;
	}
	case 3:
	{
		printArray(arr1);
		break;
	}
	case 4:
	{
		int x = 0;
		int xi = -1;
		cout << "������� �������:" << endl;
		cin >> x;
		xi = search(arr1, x);
		cout << "������� " << x << " ����� ������ " << xi << endl;
		break;
	}
	case 5:
	{

		cout << "������� ������ ������:" << endl;
		int x = 0;
		cin >> x;
		while (x != 0)
		{
			addElement(arr2, x);
			cin >> x;
		}
		printArray(arr2);

		add(arr1, arr2);
		printArray(arr1);
		clearArray(arr2);
		break;

	}
	case 6:
	{
		cout << "������� ������ ������:" << endl;
		int x = 0;
		cin >> x;
		while (x != 0)
		{
			addElement(arr2, x);
			cin >> x;
		}
		printArray(arr2);

		arr1 = unify(arr1, arr2);
		printArray(arr1);
		clearArray(arr2);

		break;

	}
	case 7:
	{
		int index = 0;
		int element = 0;
		cout << "������� ������ � �������:" << endl;
		cin >> index >> element;
		insert(arr1, index, element);
		break;
	}
	case 8:
	{
		int startIndex = 0;
		int count = 0;
		cout << "������� ������ ������� �������� � ���������� ���������" << endl;
		cin >> startIndex >> count;
		int x = 1;
		x = deleteGroup(arr1, startIndex, count);
		if (x == 1)
		{
			cout << "������" << endl;
		}
		
	}
	case 9:
	{
		cout << "������� ������ ����������������:" << endl;
		int x = 0;
		cin >> x;
		while (x != 0)
		{
			addElement(arr2, x);
			cin >> x;
		}
		printArray(arr2);

		int y = subSequence(arr1, arr2);
		if (y != -1)
		{
			cout << "������ ������ ��������������������� ���� " << y << endl;
		}
		else
		{
			cout << "��������������������� �� �������" << endl;
		}
		clearArray(arr2);

		break;
	}
	}
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10);
	int* b = initArray(10);

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, b, choice);
		system("pause");
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}