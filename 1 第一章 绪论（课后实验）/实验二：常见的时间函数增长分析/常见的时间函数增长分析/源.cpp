#include <iostream>
#include <math.h>

using namespace std;

double log2(double x)	//Çólog2(x)
{
	return log10(x) / log10(2);
}
long exponent(int n)	//Çó2^n
{
	return pow(2,n);
}
long factorial(int n)	//Çón!
{
	long s = 1;
	for (int i = 1;i <= n;i++)
		s *= i;
	return s;
}
void fun(int n)
{
	printf("log2(n) sqrt(n)  n       nlog2(n)   n^2	    n^3	     2^n		n!\n");
	for (int i = 1;i <= n;i++)
	{
		printf("%5.2f\t", log2(double(i)));
		printf("%5.2f\t", sqrt(i));
		printf("%2d\t", i);
		printf("%7.2f\t", i * log2(double(i)));
		printf("%5d\t", i * i);
		printf("%7d\t", i * i * i);
		printf("%8d\t", exponent(i));
		printf("%10d\n", factorial(i));
	}
}
int main()
{
	int n = 10;
	fun(n);
	return 1;
}