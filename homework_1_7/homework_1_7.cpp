// homework_1_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    int a = 0, b = 1, n = 0;
    cout << "введите число  и степень" << endl;
    cin >> a >> n;
    for (int i = 0; i < n; i++)
    {
        b *= a;
    }
    cout << a << " в степени " << n << " =  " << b << endl;
    return EXIT_SUCCESS;
}
