#include<iostream>

using namespace std;

bool operand1(char c[])
{
	char a[] = { '-','-','o','p','e','r','a','n','d','1' };
	for (int i = 0; c[i] != 0; ++i)
	{
		if (c[i] != a[i])
		{
			return false;
		}
	}
	return true;
}

bool operat(char c[])
{
	char a[] = { '-','-','o','p','e','r','a','t','o','r' };
	for (int i = 0; c[i] != 0; ++i)
	{
		if (c[i] != a[i])
		{
			return false;
		}
	}
	return true;
}

bool operand2(char c[])
{
	char a[] = { '-','-','o','p','e','r','a','n','d','2' };
	for (int i = 0; c[i] != 0; ++i)
	{
		if (c[i] != a[i])
		{
			return false;
		}
	}
	return true;
}

float tofloat(char* a, int &e)
{
	float x = 0;
	float xx = 0;
	int n = 1;
	int i = 0;
	if (a[i] == '-')
	{
		n = -1;
		++i;
	}
	while ((a[i] != 0) && (a[i] != '.'))
	{
			if (a[i] >= 48 && a[i] <= 58)
			{
				x = x * 10 + (a[i] - '0');
			}
			else
			{
				e = -1;
				return 0;
			}
			++i;
	}
	if (a[i] == '.')
	{
		++i;
		while (a[i] != 0)
		{

			if (a[i] >= 48 && a[i] <= 58)
			{
				xx = xx*10 + (a[i] - '0');
				cout << xx << endl;
			}
			else
			{	
				e = -1;
				return 0;
			}
			++i;
		}
	}
	while (xx >= 1)
	{
		xx /= 10;
	}

	return (x + xx)*n;
}

template <class T1, class T2>
 T1 sum(T1 a, T2 b)
{
	return a + b;
}

 template <class T1, class T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template <class T1, class T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template <class T1, class T2>
T1 divv(T1 a, T2 b)
{
	return a / b;
}






int operationIndex(char operation)
{

	switch (operation)
	{
	case '+': return 0;
		break;

	case '-': return 1;
		break;

	case '*': return 2;
		break;

	case '/': return 3;
		break;

	default:
		return -1;
		cout << "неправильное значение operator" << endl;
		break;
	}
}


template <class T1, class T2>
T1 calculate(T1 a, T2 b, char operation)
{
	T1(*ops[5])(T1, T2) = { sum, diff, mult, divv};
	if (operationIndex(operation) != -1)
	{
		return ops[operationIndex(operation)](a, b);
	}
	return 0;
}

int main(int argc, char* argv[] ){

	setlocale(LC_ALL, "Russian");

	float a = 0;
	float b = 0;
	
	for (int i = 0; i < argc; ++i)
	{
		cout << i << " " << argv[i] << endl;
	}

	if (argc == 7)
	{
		int e1 = -1;
		int e2 = -1;
		int e3 = -1;
		for (int i = 1; i < argc; ++i)
		{
			if (operand1(argv[i]))
			{
				e1 = i;
			}
			if (operand2(argv[i]))
			{
				e2 = i;
			}
			if (operat(argv[i]))
			{
				e3 = i;
			}
		}
		
		

		if (e1 == -1)
		{
			cout << "нет --operand1" << endl;
		}

		if (e2 == -1)
		{
			cout << "нет --operand2" << endl;
		}

		if (e3 == -1)
		{
			cout << "нет --operator" << endl;
		}

		if (e1 > 0)
		{
			a = tofloat(argv[e1 + 1], e1);
			if (e1 == -1)
			{
				cout << "неправильное значение operand1" << endl;
				return 0;
			}
		}
		if (e2 > 0)
		{
			b = tofloat(argv[e2 + 1], e2);
			if (e2 == -1)
			{
				cout << "неправильное значение operand2" << endl;
				return 0;
			}
		}
		char operation = 0;
		if (e3 > 0)
		{
			int i = 0;
			while (argv[e3 + 1][i] != 0)
			{
				++i;
			}
			if (i == 1)
			{
				operation = argv[e3 + 1][0];
			}
			else
			{
				e3 = -1;
				cout << "неправильное значение operator" << endl;
				return 0;
			}
		}
		
		cout << a << " " << operation << " " << b << " = " << calculate(a, b, operation) << endl;
		
	}
	else
	{
		cout << "неверное количество операторов" << endl;
	}

	return 0;
}
