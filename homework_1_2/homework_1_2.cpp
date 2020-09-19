// homework_1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//номер2

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    int a = 0, b = 0, k = 0;
    cout << "введите a и b" << endl;
    cin >> a >> b;
    for (a; a >= b; a -= b)
    {
        k++;
    }
    cout << "a/b=" << k << endl;

    return EXIT_SUCCESS;
}
