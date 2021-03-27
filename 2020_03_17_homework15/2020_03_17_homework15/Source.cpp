#include<iostream>
#include <ctime>
#include<fstream>

using namespace std;

void printArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << a[i] << ' ';
    }
}

void initArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        a[i] = 1 + rand() % 10;
    }
}

int partition(int* a, int p, int r)
{
    double x = *(a + r);
    int i = p - 1;
    int j;
    double tmp;
    for (j = p; j < r; ++j)
    {
        if (*(a + j) <= x)
        {
            i++;
            tmp = *(a + i);
            *(a + i) = *(a + j);
            *(a + j) = tmp;
        }
    }
    tmp = *(a + r);
    *(a + r) = *(a + i + 1);
    *(a + i + 1) = tmp;
    return i + 1;
}

void QuickSort(int* a, int p, int r)
{
    int q;
    if (p < r) {
        q = partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

void CountingSort(int* a, int n, const int k) {
    const int K = k + 1;
    int* c = new int[k + 1];
    for (int i = 0; i < k + 1; ++i)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++c[a[i]];
    }

    int b = 0;
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            a[b++] = i;
        }
    }
    delete[] c;
}

void Merge(int* c, int* a, int *b, int n, int m)
{
    int q = 0;
    int g = 0;
    for (int i = 0; i < n + m; ++i)
    {
        if ((g == m || a[q] <= b[g]) && q < n)
        {
            c[i] = a[q];
            ++q;
        }
        else
        {
            c[i] = b[g];
            g++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int len = 20;
    int* a = new int[len];
    initArray(a, len);
    printArray(a, len);
    cout << endl;
    CountingSort(a, len, 10);
    printArray(a, len);
    cout << endl << endl;

    int* b = new int[len];
    initArray(b, len);
    printArray(b, len);
    cout << endl;
    QuickSort(b, 0, len - 1);
    printArray(b, len);
    cout << endl << endl;

    int* c = new int[2*len];
    Merge(c, a, b, len, len);
    printArray(c, 2*len);
    cout << endl << endl;

    char str[16] = { "Блин чёрт, блин" };
    char x = '0';
    fstream fbin;

    fbin.open("in.bin", ios::binary | ios::out);
    if (!fbin)
    {
        cout << "Не удалось открыть файл" << endl;
    }
    fbin.write((char*)str, sizeof(str));
    fbin.close();

    fbin.open("in.bin", ios::binary | ios::out | ios::in);
    if (!fbin)
    {
        cout << "Не удалось открыть файл" << endl;
    }
    while (!fbin.eof())
    {
        fbin.read((char*)&x, sizeof(char));
        cout << x;
        if (x == 'а' || x == 'у' || x == 'о' || x == 'ы' || x == 'и' || x == 'э' || x == 'я' || x == 'ю' || x == 'ё' || x == 'е')
        {
            fbin.seekg(-(int)sizeof(char), ios::cur);
            x = '#';
            fbin.write((char*)&x, sizeof(char));
            fbin.seekg(fbin.tellg(), ios::beg);
        }
        
    }
    cout << endl;
    fbin.close();

    fbin.open("in.bin", ios::in);
    while (!fbin.eof())
    {
        fbin.read((char*)&x, sizeof(char));
        cout << x;
    }
    cout << endl;

    fbin.close();


    delete[] a;
    delete[] b;
	return 0;
}