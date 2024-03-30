#include<stdio.h>	//输入输出头文件
#include<stdlib.h>	//标准头文件
#include<stdbool.h>	//布尔类型头文件
#define MaxSize 16

int map[6][6] =
{
	{1,1,1,1,1,1},{1,0,0,0,1,1},
	{1,0,1,0,0,1},{1,0,0,0,1,1},
	{1,1,0,0,0,1},{1,1,1,1,1,1},
};

typedef struct Box
{
	int i, j;	//当前方块的坐标
	int di;		//下一相邻方块的方位号1
}Elemtype;
typedef struct StType
{
	Box data[MaxSize];
	int top;	//栈顶下标
}SqStack;
struct
{
	Box data[MaxSize];
	int length;	//路径长度
}MinType;	//存放最短路径
//方位优先度：上：0，右：1，下：2，左3

bool InitStack(SqStack*& s);			//初始化栈
bool DestroyStack(SqStack*& s);			//销毁栈
bool StackEmpty(SqStack*& s);			//判断栈是否为空
bool Push(SqStack*& s, Elemtype e);		//进栈
bool Pop(SqStack*& s, Elemtype& e);		//出栈
bool GetTop(SqStack* s, Elemtype& e);	//取栈顶元素
bool mgpath(int xi, int yi, int xe, int ye);//求解路径为(xi,yi)->(xe,ye)

int main(int argc, const char* argv[])
{
	MinType.length = MaxSize;
	if (!mgpath(1, 1, 4, 4))
		printf("该迷宫问题没有解！\n");
	else {
		printf("最短路径为：\n");
		for (int i = 1; i <= MinType.length; i++) {
			printf("\t(% d, % d)", MinType.data[i].i, MinType.data[i].j);
			if (i % 5 == 0)
				printf("\n");
		}
		printf("\n该路径长度为%d\n", MinType.length);
	}
	return 0;
}
bool mgpath(int xi, int yi, int xe, int ye)
{
	Box path[MaxSize], e;
	int i, j, di, i1, j1, k, idx, count;
	bool find, flag;
	SqStack* st;
	InitStack(st);	//初始化栈
	e.i = xi; e.j = yi; e.di = -1;	//设置e为入口
	Push(st, e);	//将入口进栈
	map[xi][yi] = -1;	//将入栈的位置的值置为-1，避免重复走同一方块
	idx = 1;	//记录迷宫解的条数
	flag = false;	//默认迷宫没有解
	while (!StackEmpty(st)) {	//栈不为空时循环
		GetTop(st, e);	//取栈顶元素
		i = e.i; j = e.j; di = e.di;
		find = false;
		if (i == xe && j == ye) {	//找到出口时
			printf("第%d条迷宫路径如下：\n", idx++);
			k = 0;
			while (!StackEmpty(st)) {
				Pop(st, e);
				path[k++] = e;	//将迷宫路径添加到数组中，确保迷宫路径正向输出
			}
			if (k < MinType.length) {	//当前路径更优时，记录当前路径
				MinType.length = k;
				find = true;
			}
			count = 1;
			for (count = 1; k >= 1; count++) {
				printf("\t(%d,%d)", path[--k].i, path[k].j);
				if (find)
					MinType.data[count] = path[k];	//记录最短路径
				Push(st, path[k]);	//将该路径入栈
				if (count % 5 == 0)	//每输出五个换一行
					printf("\n");
			}
			printf("\n");
			Pop(st, e);	//回溯一格，继续寻找其他路径
			map[e.i][e.j] = 0;
			flag = true;
		}
		find = false;
		while (di < 4 && !find) {	//寻找下一相邻可走方块
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
		if (find) {	//找到相邻可走方块
			st->data[st->top].di = di;	//修改原栈顶元素di值
			e.i = i1; e.j = j1; e.di = -1;
			Push(st, e);
			map[i1][j1] = -1;	//将入栈的位置的值置为-1，避免重复走同一方块
		}
		else {	//相邻方块均不可走时，出栈一个元素
			Pop(st, e);	//将栈顶元素退栈
			map[e.i][e.j] = 0;	//将栈顶元素的值复原，变为可走的方块
		}
	}
	DestroyStack(st);	//销毁栈
	return flag;
}
bool InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	if (s == NULL)	//如果申请失败，返回“假”
		return false;
	s->top = -1;	//此时栈内无元素
	return true;
}
bool DestroyStack(SqStack*& s)
{
	free(s);
	return true;
}
bool StackEmpty(SqStack*& s)
{
	return (s->top == -1);	//当栈为空时返回“真”，否则返回“假”
}
bool Push(SqStack*& s, Elemtype e)
{
	if (s->top == MaxSize - 1)	//当栈满时返回假
		return false;
	s->top++;					//栈顶上移，并在该位置放入新的栈顶元素
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, Elemtype& e)
{
	if (s->top == -1)	//当栈为空时无法出栈，返回“假”
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, Elemtype& e)
{
	if (s->top == -1)	//当栈为空时栈内没有元素，返回“假”
		return false;
	e = s->data[s->top];
	return true;
}
