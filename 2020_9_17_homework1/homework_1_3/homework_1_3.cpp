// homework_1_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//номер3

#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    int s = 0, a = 0, b = 0, c = 0, aa = 0, bb = 0, cc = 0;
    cout << "введите s:";
    cin >> s;
    if (s < 10)
        a = s;
    else
        a = 9;
    for (a; a >= 0; a--)
    {
        if (s-a < 10)
            b = s-a;
        else
            b = 9;
        for (b; b >= 0; b--)
        {
            c = s - a - b;
            if (c > 9) break;
            ///////////
            if (s < 10)
                aa = s;
            else
                aa = 9;
            for (aa; aa >= 0; aa--)
            {
                if (s - aa < 10)
                    bb = s - aa;
                else
                    bb = 9;
                for (bb; bb >= 0; bb--)
                {
                    cc = s - aa - bb;
                    if (cc > 9) break;
                    cout << a << b << c << " " << aa << bb << cc << endl;
                }
            }
            ///////////  
        }
    }

    return EXIT_SUCCESS;
}


