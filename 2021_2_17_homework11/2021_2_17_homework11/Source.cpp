#include<iostream>

using namespace std;



void printBits(short s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned short bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
} 


void printBits(int a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = a;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		if (i % 8 == 0)
		{
			cout << " ";
		}
		cout << bit;	
	}
}
void printBits(long a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		void* ptr = &a;
		unsigned int bit = *(int*)(ptr);
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		if (i % 8 == 0)
		{
			cout << " ";
		}
		cout << bit;
	}

}

void printBits(long long a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		void* ptr = &a;
		unsigned long long int bit = *(long long int*)(ptr);
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		if (i % 8 == 0)
		{
			cout << " ";
		}
		cout << bit;
	}

}


void printBits(float a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{

		void* ptr = &a;
		unsigned int bit = *(int*)(ptr);
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		if (i % 8 == 0)
		{
			cout << " ";
		}
		cout << bit;
	}
}

void printBits(double a)
{
		
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{

		void* ptr = &a;
		unsigned long long int bit = *(long long int*)(ptr);
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		if (i % 8 == 0)
		{
			cout << " ";
		}
		cout << bit;
	}
}

void printBits(long double a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		void* ptr = &a;
		unsigned long long int bit = *(long long int*)(ptr);
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		if (i % 8 == 0)
		{
			cout << " ";
		}
		cout << bit;
	}
}

double average(int n, ...)
{
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		int* ptr = &n + 1 + i;
		result += *ptr;
	}

	return result/n;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int a = 1654656;
	cout << "int: ";
	printBits(a);
	cout << endl << endl;
	cout << "long: ";
	printBits((long)a);
	cout << endl << endl;
	cout << "long long: ";
	printBits((long long)a);
	cout << endl << endl;
	cout << "float: ";
	float b = 0.64;
	printBits(b);
	cout << endl << endl;
	double bb = 3.12;
	cout << "double: ";
	printBits(bb);
	cout << endl << endl;
	long double bbb = 65555546543.12;
	cout << "long double: ";
	printBits(bbb);


	cout << endl << endl << "среднее арифметиеское = ";
	cout << average(3, 4, 12, 14) << endl;

	return 0;
}