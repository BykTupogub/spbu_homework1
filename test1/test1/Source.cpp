#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double myFunction(double x, int n)
{
	double sum = 0;
	double ti = 1;
	int i = 1;
	while (abs(sum - exp(x)) > pow(10, -(n+1)))
	{
		sum += ti;
		ti = (ti*x)/i;
		++i;
	}
	return sum;
}

int main()
{
	
	double x = 0;
	int n = 0;
	cin >> x >> n;
	cout << setprecision(15);
	cout << exp(x) << endl;
	cout << myFunction(x, n) << endl;


	return 0;
}