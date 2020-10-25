// homework_1_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    int a = 0, b = 1;
    cout << "введите число" << endl;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        b *= i;
    }
    cout << "факториал числа a = " << b << endl;
    return EXIT_SUCCESS;
}
