#include<iostream>
#include<string>
#include<clocale>
#include<ctime>

using namespace std;

void resolveError(int errorCode)
{
	string errorCout[2][7];
	errorCout[0][0] = "������ � ������ �����, ��������";
	errorCout[1][0] = "������ ����� ������� �����������, ��������";
	errorCout[0][1] = "����������� ������ �����, ��������";
	errorCout[1][1] = "�� �� ����� ������ �����, ��������";
	errorCout[0][2] = "�� ������ �� �����, ��������";
	errorCout[1][2] = "������� ���-������, ��������";
	errorCout[0][3] = "������ � ����� ����� ������� �����, ��������, ��������";
	errorCout[1][3] = "����� ���� ������� ����� ������� �����������, ��������";
	errorCout[0][4] = "������ � ������� ����� ������� �����, ��������";
	errorCout[1][4] = "������� ����� ������� ����� ������� �����������, ��������";
	errorCout[0][5] = "������ ����� ������ �������, ��������";
	errorCout[1][5] = "�������� ���������� ������ ������� �����, ��������";
	errorCout[0][6] = "������ ����� ������� �������, ��������";
	errorCout[1][6] = "�������� ���������� ������ ������� �����, ��������";

	cout << errorCout[rand() % (2)][errorCode - 1] << endl << endl;

}

void trim(string& str)
{
	int startIndex = 0;
	while (str[startIndex] == ' ')
	{
		startIndex++;
	}
	str = str.substr(startIndex);
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}
int readDouble(double& number, string& str)
{
	number = 0;
	int sign = 1;
	if (str[0] == '-')
	{
		str = str.substr(1);
		sign = -1;
	}
	while (isDigit(str[0]))
	{
		number = 10 * number + str[0] - '0';
		str = str.substr(1);
	}
	if (str[0] != '.' && !empty(str))
	{
		number = 0;
		return 4;
	}
	if (str[0] == '.')
	{
		str = str.substr(1);
		double a = 0;
		while (isDigit(str[0]))
		{
			a = 10 * a + str[0] - '0';
			str = str.substr(1);
		}
		if (!empty(str))
		{
			number = 0;
			return 5;
		}
		while (a > 1)
		{
			a /= 10;
		}
		number += a;
	}
	number *= sign;
	return 0;
}

int readInt(long long& number, string& str)
{
	number = 0;
	int sign = 1;
	if (str[0] == '-')
	{
		str = str.substr(1);
		sign = -1;
	}

	while (isDigit(str[0]))
	{
		number = 10 * number + str[0] - '0';
		str = str.substr(1);
	} 
	number *= sign;
	if (empty(str))
	{
		number = 0;
		return 2;
	}
	if (str[0] == ' ')
	{
		return 0;
	}
	number = 0;
	return 1;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	
	string str;
	long long number1;
	double number2;
	int error = -1;
	while(error != 0)
	{ 
		cout << "������� ��� ����� ����� ������" << endl;
		cout << "������ ����� �����, � ������ ���������� �����, ����� ����� �� ������� ������ �������� ������" << endl;
		getline(cin, str);
		if (str.find(" ") > 18)
		{
			if (empty(str))
			{
				resolveError(3);
				continue;
			}
			if (str.find(" ") == 4294967295)
			{
				resolveError(2);
				continue;
			}
			resolveError(6);
			continue;
		}

		if (size(str) - str.find(" ") > 12)
		{
			resolveError(7);
			continue;
		}
		error = readInt(number1, str);
		if (error != 0)
		{
			resolveError(error);
			continue;
		}
		cout << "number1 = "<< number1 << endl;
		
		str = str.substr(1);

		error = readDouble(number2, str);
		if (error != 0)
		{
			resolveError(error);
			continue;
		}
		cout << "number2 " << number2 << endl;

		double sum = number1 + number2;
		cout << "number1 + number2 = " << sum << endl;
	}
		



	return 0;
}