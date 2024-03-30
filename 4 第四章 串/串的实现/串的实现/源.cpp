#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 30

typedef struct
{
	char data[MAXSIZE];
	int len;
}SqString;

void StrAssign(SqString& S, char a[])
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		S.data[i] = a[i];
	}
	S.len = i;
}

void CreateStr(SqString& S, char a[])
{
	printf("请输入一串字符：");
	scanf_s("%s", &a);
	StrAssign(S, a);
}

SqString Concat(SqString& S, SqString R, SqString L)	  
{													
	int i;
	S.len = R.len + L.len;
	for (i = 0; i < R.len; i++)
	{
		S.data[i] = R.data[i];
	}
	for (i = 0; i < L.len; i++)
	{
		S.data[i + R.len] = L.data[i];
	}
	return S;
}

SqString SubStr(SqString& S, int i, int j)
{
	int k;
	SqString str;
	str.len = 0;
	if (i <= 0 || i > S.len || j<0 || i + j - 1>S.len)
	{
		printf("超出范围\n");
		return str;
	}
	for (k = i - 1; k < i + j - 1; k++)
	{
		str.data[k - i + 1] = S.data[k];
	}
	str.len = j;
	return str;
}

SqString InsertStr(SqString& S, SqString T, int w)
{
	int k;
	SqString A = S, B;
	if (w <= 0 || w > S.len)
	{
		printf("超出插入范围\n");
		return B;
	}

	for (k = 0; k < T.len; k++)
	{
		S.data[k + w - 1] = T.data[k];
	}

	for (k = w - 1; k < S.len; k++)
	{
		S.data[T.len + k] = A.data[k];
	}
	S.len = S.len + T.len;
	return S;
}

SqString DeleteStr(SqString S, int i, int j)
{
	SqString str;
	str.len = 0;
	int k;
	if (i <= 0 || i > S.len || j<0 || i + j - 1>S.len)
	{
		printf("超出范围\n");
		return str;
	}
	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = S.data[k];
	}
	for (k = i - 1; k < S.len - j; k++)
	{
		str.data[k] = S.data[k + j];
	}
	str.len = S.len - j;
	return str;
}

int main()
{
	printf("========实现串的ADT========\n\n");

	SqString R, L, S;
	char a[1], b[1];

	CreateStr(R, a);
	CreateStr(L, b);
	printf("新创建的串为%s和%s\n", R, L);

	printf("串连接得到：%s\n\n", Concat(S, R, L));

	int i, j;
	printf("请输入子串的起始位置：");
	scanf_s("%d", &i);
	printf("请输入子串的长度：");
	scanf_s("%d", &j);
	printf("子串为：%s\n\n", SubStr(S, i, j));

	SqString T;
	char c[1];
	int w;
	printf("请输入要插入串T的位置：");
	scanf_s("%d", &w);
	CreateStr(T, c);
	printf("插入串T后的字符串为：%s\n\n", InsertStr(S, T, w));

	printf("请输入要删除的子串位置：");
	scanf_s("%d", &i);
	printf("请输入要删除的子串长度：");
	scanf_s("%d", &j);
	printf("删除后的字符串为：%s\n", DeleteStr(S, i, j));

}
