#include<iostream>
#include<string>
#include<clocale>
#include<ctime>

using namespace std;

void resolveError(int errorCode)
{
	string errorCout[2][7];
	errorCout[0][0] = "Ошибка в первом числе, извините";
	errorCout[1][0] = "Первое число введено неправильно, извините";
	errorCout[0][1] = "Отсутствует второе число, извините";
	errorCout[1][1] = "Вы не ввели второе число, извините";
	errorCout[0][2] = "Вы ничего не ввели, извините";
	errorCout[1][2] = "Введите что-нибудь, извините";
	errorCout[0][3] = "Ошибка в целой части второго числа, извините, извините";
	errorCout[1][3] = "Целая чать второго числа введена неправильно, извините";
	errorCout[0][4] = "Ошибка в дробной части второго числа, извините";
	errorCout[1][4] = "Дробная часть второго числа введена неправильно, извините";
	errorCout[0][5] = "Первое число слшком большое, извините";
	errorCout[1][5] = "Превышен допустимый размер первого числа, извините";
	errorCout[0][6] = "Второе число слишком большое, извините";
	errorCout[1][6] = "Превышен допустимый размер второго числа, извините";

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
		cout << "введите два числа через пробел" << endl;
		cout << "первое число целое, а второе десятичная дробь, целую часть от дробной следут отделять точкой" << endl;
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