#include<iostream>

using namespace std;

long Sum(int n)
{
	long long sum = 0, res = 1;
	for (int i = 1;i <= n;i++)
	{
		res *= i;//�׳�
		sum += res;//�׳˺�
	}
	return sum;
}


int main()
{
	cout<<Sum(10);
	

	return 1;
}