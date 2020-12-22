#include<iostream>
#include<iomanip>
using namespace std;

int** initMatrix(int dimention)
{
	int** matrix = new int* [dimention] { 0 };
	for (int i = 0; i < dimention; ++i)
	{
		matrix[i] = new int[dimention] { 0 };
	}
	return matrix;
}

void printMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
}

int** Matrix1( int dimention)
{

	int** result = initMatrix(dimention);
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			result[i][j] = i+j+1;
		}
	}
	return result;
}

int** Matrix2(int dimention)
{

	int** result = initMatrix(dimention);
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			result[i][j] = 2*dimention - i - j - 1;
		}
	}
	return result;
}

int** Matrix3(int dimention)
{

	int** result = initMatrix(dimention);
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; j < dimention; ++j)
		{
			result[i][j] = j + 1;
		}
	}
	return result;
}

int** Matrix4(int dimention)
{

	int** result = initMatrix(dimention);
	for (int i = 0; i < dimention; ++i)
	{
		for (int j = 0; i+j < dimention; ++j)
		{
			result[i+j][j] = j+1;
			result[j][i+j] = j + 1;
		}
	}
	return result;
}

int** Matrix5(int dimention)
{

	int** result = initMatrix(dimention);
	int a = 0;
	int b = 0;
	int n = dimention;
	int k = 1;
	while (n > 2)
	{
		for (int i = 0; i < n; ++i)
		{
			result[a][b] = k;
			++b;
			++k;
		}
		--b;
		++a;
		for (int i = 0; i < n - 1; ++i)
		{
			result[a][b] = k;
			++a;
			++k;
		}
		--a;
		--b;
		for (int i = 0; i < n - 1; ++i)
		{
			result[a][b] = k;
			--b;
			++k;
		}
		++b;
		--a;
		for (int i = 0; i < n - 2; ++i)
		{
			result[a][b] = k;
			--a;
			++k;
		}
		++a;
		++b;
		n -= 2;
	}
	if (n == 1)
	{
		result[a][b] = k;
	}
	if (n == 2)
	{
		result[a][b] = k;
		++k;
		++b;
		result[a][b] = k;
		++k;
		++a;
		result[a][b] = k;
		++k;
		--b;
		result[a][b] = k;
	}
	
	
	
	return result;
}

void freeMatrix(int** matrix, int dimention)
{
	for (int i = 0; i < dimention; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите размер матрицы" << endl;
	int N;
	cin >> N;
	int** matrix1 = Matrix1(N);
	printMatrix(matrix1, N);
	cout << endl;

	int** matrix2 = Matrix2(N);
	printMatrix(matrix2, N);
	cout << endl;

	int** matrix3 = Matrix3(N);
	printMatrix(matrix3, N);
	cout << endl;

	int** matrix4 = Matrix4(N);
	printMatrix(matrix4, N);
	cout << endl;

	int** matrix5 = Matrix5(N);
	printMatrix(matrix5, N);
	cout << endl;

	return 0;
}
