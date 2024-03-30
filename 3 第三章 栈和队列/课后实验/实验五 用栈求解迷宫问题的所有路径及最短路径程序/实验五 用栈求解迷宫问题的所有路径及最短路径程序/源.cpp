#include<stdio.h>	//�������ͷ�ļ�
#include<stdlib.h>	//��׼ͷ�ļ�
#include<stdbool.h>	//��������ͷ�ļ�
#define MaxSize 16

int map[6][6] =
{
	{1,1,1,1,1,1},{1,0,0,0,1,1},
	{1,0,1,0,0,1},{1,0,0,0,1,1},
	{1,1,0,0,0,1},{1,1,1,1,1,1},
};

typedef struct Box
{
	int i, j;	//��ǰ���������
	int di;		//��һ���ڷ���ķ�λ��1
}Elemtype;
typedef struct StType
{
	Box data[MaxSize];
	int top;	//ջ���±�
}SqStack;
struct
{
	Box data[MaxSize];
	int length;	//·������
}MinType;	//������·��
//��λ���ȶȣ��ϣ�0���ң�1���£�2����3

bool InitStack(SqStack*& s);			//��ʼ��ջ
bool DestroyStack(SqStack*& s);			//����ջ
bool StackEmpty(SqStack*& s);			//�ж�ջ�Ƿ�Ϊ��
bool Push(SqStack*& s, Elemtype e);		//��ջ
bool Pop(SqStack*& s, Elemtype& e);		//��ջ
bool GetTop(SqStack* s, Elemtype& e);	//ȡջ��Ԫ��
bool mgpath(int xi, int yi, int xe, int ye);//���·��Ϊ(xi,yi)->(xe,ye)

int main(int argc, const char* argv[])
{
	MinType.length = MaxSize;
	if (!mgpath(1, 1, 4, 4))
		printf("���Թ�����û�н⣡\n");
	else {
		printf("���·��Ϊ��\n");
		for (int i = 1; i <= MinType.length; i++) {
			printf("\t(% d, % d)", MinType.data[i].i, MinType.data[i].j);
			if (i % 5 == 0)
				printf("\n");
		}
		printf("\n��·������Ϊ%d\n", MinType.length);
	}
	return 0;
}
bool mgpath(int xi, int yi, int xe, int ye)
{
	Box path[MaxSize], e;
	int i, j, di, i1, j1, k, idx, count;
	bool find, flag;
	SqStack* st;
	InitStack(st);	//��ʼ��ջ
	e.i = xi; e.j = yi; e.di = -1;	//����eΪ���
	Push(st, e);	//����ڽ�ջ
	map[xi][yi] = -1;	//����ջ��λ�õ�ֵ��Ϊ-1�������ظ���ͬһ����
	idx = 1;	//��¼�Թ��������
	flag = false;	//Ĭ���Թ�û�н�
	while (!StackEmpty(st)) {	//ջ��Ϊ��ʱѭ��
		GetTop(st, e);	//ȡջ��Ԫ��
		i = e.i; j = e.j; di = e.di;
		find = false;
		if (i == xe && j == ye) {	//�ҵ�����ʱ
			printf("��%d���Թ�·�����£�\n", idx++);
			k = 0;
			while (!StackEmpty(st)) {
				Pop(st, e);
				path[k++] = e;	//���Թ�·����ӵ������У�ȷ���Թ�·���������
			}
			if (k < MinType.length) {	//��ǰ·������ʱ����¼��ǰ·��
				MinType.length = k;
				find = true;
			}
			count = 1;
			for (count = 1; k >= 1; count++) {
				printf("\t(%d,%d)", path[--k].i, path[k].j);
				if (find)
					MinType.data[count] = path[k];	//��¼���·��
				Push(st, path[k]);	//����·����ջ
				if (count % 5 == 0)	//ÿ��������һ��
					printf("\n");
			}
			printf("\n");
			Pop(st, e);	//����һ�񣬼���Ѱ������·��
			map[e.i][e.j] = 0;
			flag = true;
		}
		find = false;
		while (di < 4 && !find) {	//Ѱ����һ���ڿ��߷���
			di++;
			switch (di) {
			case 0:i1 = i - 1; j1 = j; break;
			case 1:i1 = i; j1 = j + 1; break;
			case 2:i1 = i + 1; j1 = j; break;
			case 3:i1 = i; j1 = j - 1; break;
			}
			if (map[i1][j1] == 0)
				find = true;
		}
		if (find) {	//�ҵ����ڿ��߷���
			st->data[st->top].di = di;	//�޸�ԭջ��Ԫ��diֵ
			e.i = i1; e.j = j1; e.di = -1;
			Push(st, e);
			map[i1][j1] = -1;	//����ջ��λ�õ�ֵ��Ϊ-1�������ظ���ͬһ����
		}
		else {	//���ڷ����������ʱ����ջһ��Ԫ��
			Pop(st, e);	//��ջ��Ԫ����ջ
			map[e.i][e.j] = 0;	//��ջ��Ԫ�ص�ֵ��ԭ����Ϊ���ߵķ���
		}
	}
	DestroyStack(st);	//����ջ
	return flag;
}
bool InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	if (s == NULL)	//�������ʧ�ܣ����ء��١�
		return false;
	s->top = -1;	//��ʱջ����Ԫ��
	return true;
}
bool DestroyStack(SqStack*& s)
{
	free(s);
	return true;
}
bool StackEmpty(SqStack*& s)
{
	return (s->top == -1);	//��ջΪ��ʱ���ء��桱�����򷵻ء��١�
}
bool Push(SqStack*& s, Elemtype e)
{
	if (s->top == MaxSize - 1)	//��ջ��ʱ���ؼ�
		return false;
	s->top++;					//ջ�����ƣ����ڸ�λ�÷����µ�ջ��Ԫ��
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, Elemtype& e)
{
	if (s->top == -1)	//��ջΪ��ʱ�޷���ջ�����ء��١�
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, Elemtype& e)
{
	if (s->top == -1)	//��ջΪ��ʱջ��û��Ԫ�أ����ء��١�
		return false;
	e = s->data[s->top];
	return true;
}
