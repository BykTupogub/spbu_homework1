#include<iostream>
#include <ctime>

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

void quickSort(int* a, int p, int r)
{
    int q;
    if (p < r) {
        q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

void countingSort(int* a, int n, const int k) {
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

void merger(int* c, int* a, int *b, int n, int m)
{
    int q = 0;
    int g = 0;
    for (int i = 0; i < n + m; ++i)
    {
        if (q < n && a[q] <= b[g])
        {
            c[i] = a[q];
            ++q;
        }
        else if(g < m)
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
    countingSort(a, len, 10);
    printArray(a, len);
    cout << endl << endl;

    int* b = new int[len];
    initArray(b, len);
    printArray(b, len);
    cout << endl;
    quickSort(b, 0, len - 1);
    printArray(b, len);
    cout << endl << endl;

    int* c = new int[2*len];
    merger(c, a, b, len, len);
    printArray(c, 2*len);

    delete[] a;
    delete[] b;
	return 0;
}