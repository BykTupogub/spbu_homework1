// homework_1_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    int a = 0, n = 0;
    cout << "введите степень" << endl;
    cin >> n;
    a = 1 << n;
    cout << "2 в степени " << n << " =  " << a << endl;
    return EXIT_SUCCESS;
}
