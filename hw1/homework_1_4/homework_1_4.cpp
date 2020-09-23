// homework_1_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	bool t = true;
	cout << "введите число:";
	cin >> a;
	cout << endl;
	for (int i = a; i > 0; i--)
	{
		for (int j = i - 1; j > 1; j--)
		{
			if (i % j == 0)
			{
				t = false;
			}
			
		}
		if (t == true)
		{
			cout << i << " ";
		}
		t = true;
	}
	cout << endl;
	return EXIT_SUCCESS;
}
