#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isDigit(char c);
bool isSign(char c);
bool isNatural(string str, int& index);
bool isOrder(string str, int& index);
bool isMantissa(string str, int& index);
bool isReal(string str, int& index);

int main(int argc, char* argv[])
{
	string str;
	int index = 0;
	
	ifstream fin("in.txt");
	if (fin.is_open())
	{
		while (getline(fin, str))
		{
			cout << str << endl;
			if (isReal(str, index))
			{
				cout << "=)" << endl;
			}
			else
			{
				cout << "=(" << endl;
			}
			index = 0;
		}
	}

	fin.close();
	return 0;
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isSign(char c)
{
	if (c == '-' || c == '+')
	{
		return true;
	}
	return false;
}

bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		return true;
	}
	return false;
}

bool isOrder(string str, int& index)
{
	int memIndex = index;
	if (str[index] == 'E' &&  (((isSign(str[++index]) && isNatural(str, ++index))) || (isNatural(str, ++index))))
	{
		return true;
	}
	index = memIndex;
	return false;
}

bool isMantissa(string str, int& index)
{
	int memIndex = index;
	if ((isNatural(str, index) && str[index] == '.' && isNatural(str, ++index)) || (str[index] == '.' && isNatural(str, ++index)))
	{
		return true;
	}
	index = memIndex;
	return false;
}

bool isReal(string str, int& index)
{
	if ((isSign(str[index]) && isMantissa(str, ++index) && isOrder(str, index)) || isMantissa(str, index) && isOrder(str, index))
	{
		return true;
	}
	return false;
}
