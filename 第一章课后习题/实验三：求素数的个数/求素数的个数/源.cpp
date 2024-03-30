#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;

clock_t start1, stop1, start2, stop2;
double duration1, duration2;

int fun1(int n) {//����
	int cnt=0;
	for (int i = 2;i <= n;i++) {//1�Ȳ�������Ҳ���Ǻ���
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
	for (int i = 2;i <= n;i++) {//1�Ȳ�������Ҳ���Ǻ���
		bool flag = 1;
		for (int j = 2;j <= (int)sqrt(i);j++)//����
			if (i % j == 0) { 
				flag = 0;
				break;
			}
		if (flag)cnt++;
	}
	return cnt;
}
int main() {
	//�㷨һ
	start1 = clock();
	int cnt=fun1(1e5);
	stop1 = clock();
	duration1 = ((double)(stop1 - start1)) / CLK_TCK;
	cout <<1e5<<"����"<<cnt <<"������" << endl;
	cout << "�㷨һ������ʱ��" << duration1 << endl;

	//�㷨��
	start2 = clock();
	cnt=fun2(1e5);
	stop2 = clock();
	duration2 = ((double)(stop2 - start2)) / CLK_TCK;
	cout << 1e5 << "����" << cnt << "������" << endl;
	cout << "�㷨��������ʱ��" << duration2 << endl;

	return 0;
}