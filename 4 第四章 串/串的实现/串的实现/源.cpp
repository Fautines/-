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
	printf("������һ���ַ���");
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
		printf("������Χ\n");
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
		printf("�������뷶Χ\n");
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
		printf("������Χ\n");
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
	printf("========ʵ�ִ���ADT========\n\n");

	SqString R, L, S;
	char a[1], b[1];

	CreateStr(R, a);
	CreateStr(L, b);
	printf("�´����Ĵ�Ϊ%s��%s\n", R, L);

	printf("�����ӵõ���%s\n\n", Concat(S, R, L));

	int i, j;
	printf("�������Ӵ�����ʼλ�ã�");
	scanf_s("%d", &i);
	printf("�������Ӵ��ĳ��ȣ�");
	scanf_s("%d", &j);
	printf("�Ӵ�Ϊ��%s\n\n", SubStr(S, i, j));

	SqString T;
	char c[1];
	int w;
	printf("������Ҫ���봮T��λ�ã�");
	scanf_s("%d", &w);
	CreateStr(T, c);
	printf("���봮T����ַ���Ϊ��%s\n\n", InsertStr(S, T, w));

	printf("������Ҫɾ�����Ӵ�λ�ã�");
	scanf_s("%d", &i);
	printf("������Ҫɾ�����Ӵ����ȣ�");
	scanf_s("%d", &j);
	printf("ɾ������ַ���Ϊ��%s\n", DeleteStr(S, i, j));

}
