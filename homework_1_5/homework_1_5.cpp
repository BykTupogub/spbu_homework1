﻿// homework_1_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    int x = 0, k = 0;
    cout << "введите x" << endl;
    cin >> x;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0)
            k++;
    }
    cout << "количество делителей x = " << k << endl;
    return EXIT_SUCCESS;
}

