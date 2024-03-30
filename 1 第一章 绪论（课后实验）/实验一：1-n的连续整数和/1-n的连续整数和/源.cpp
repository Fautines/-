#include<iostream>
#include<time.h>
using namespace std;

clock_t start1, stop1,start2,stop2;
double duration1,duration2;

int add1(int n) {
	return (1 + n) * n / 2;
}

int add2(int n) {
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		sum += i;
	}
	return sum;
}
int main() {
	//算法一
	start1 = clock();
	add1(1e20);
	stop1 = clock();
	duration1 = ((double)(stop1 - start1)) / CLK_TCK;
	cout << "算法一的运行时长" << duration1 << endl;
	
	//算法二
	start2 = clock();
	add2(1e20);
	stop2 = clock();
	duration2 = ((double)(stop2 - start2))/ CLK_TCK;
	cout << "算法二的运行时长" << duration2 << endl;

	return 0;
}