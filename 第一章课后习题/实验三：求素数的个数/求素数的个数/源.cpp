#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;

clock_t start1, stop1, start2, stop2;
double duration1, duration2;

int fun1(int n) {//遍历
	int cnt=0;
	for (int i = 2;i <= n;i++) {//1既不是质数也不是合数
		int j = 2;
		while (j < i) {
			if (i % j == 0)break;
			j++;
		}
		if (j == i)cnt++;
	}
	return cnt;
}

int fun2(int n) {
	int cnt = 0;
	for (int i = 2;i <= n;i++) {//1既不是质数也不是合数
		bool flag = 1;
		for (int j = 2;j <= (int)sqrt(i);j++)//根号
			if (i % j == 0) { 
				flag = 0;
				break;
			}
		if (flag)cnt++;
	}
	return cnt;
}
int main() {
	//算法一
	start1 = clock();
	int cnt=fun1(1e5);
	stop1 = clock();
	duration1 = ((double)(stop1 - start1)) / CLK_TCK;
	cout <<1e5<<"内有"<<cnt <<"个素数" << endl;
	cout << "算法一的运行时长" << duration1 << endl;

	//算法二
	start2 = clock();
	cnt=fun2(1e5);
	stop2 = clock();
	duration2 = ((double)(stop2 - start2)) / CLK_TCK;
	cout << 1e5 << "内有" << cnt << "个素数" << endl;
	cout << "算法二的运行时长" << duration2 << endl;

	return 0;
}