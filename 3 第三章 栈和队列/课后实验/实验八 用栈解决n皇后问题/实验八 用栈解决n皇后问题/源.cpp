#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 100
typedef struct
{
    int data[MaxSize];	//data[i]存放第i个皇后的列号
    int top;			//栈顶指针
} StType;				//定义顺序栈类型
int count = 0;
int place(StType st, int i, int j)  //测试(i,j)是否与1～i-1皇后有冲突
{
    int a = 0;         //a为函数的返回值
    int k = 1;
    if (i == 1)
    {
        a = 1;
        return a;	//放第一个皇后时没有冲突
    }
    while (k <= i - 1)			//j=1到k-1是已放置了皇后的列
    {
        if ((st.data[k] == j) || (fabs(j - st.data[k]) == fabs(i - k)))
        {
            a = 0;
            return a;
        }
        else
            k++;
    }
    a = 1;
    return a;
}
void queen(int n)					//求解n皇后问题
{
    int i, j, k;
    int find = 0;
    StType st;						//定义栈st
    st.top = 0;						//初始化栈顶指针
    st.top++;						//将(1,1)进栈
    st.data[st.top] = 1;
    while (st.top > 0)				//栈不空时循环
    {
        i = st.top;					//当前皇后为第i个皇后
        if (st.top == n)				//所有皇后均放好,输出一个解
        {
            printf("第%d个解：", ++count);
            for (k = 1; k <= st.top; k++)
                printf("(%d,%d) ", k, st.data[k]);
            printf("\n");
        }
        find = 0;
        for (j = 1; j <= n; j++)
            if (place(st, i + 1, j))	//在i+1行找到一个放皇后的位置(i+1,j)
            {
                st.top++;
                st.data[st.top] = j;
                find = 1;
                break;
            }
        if (find == 0)			//在i+1行找不到放皇后的位置,回溯
        {
            while (st.top > 0)
            {
                if (st.data[st.top] == n)	//本行没有可放位置,退栈
                    st.top--;
                for (j = st.data[st.top] + 1; j <= n; j++)	//在本行找下一个位置
                    if (place(st, st.top, j))
                    {
                        st.data[st.top] = j;
                        break;
                    }
                if (j > n)				//当前皇后在本行没有可放的位置
                    st.top--;			//退栈
                else					//本行找到一个位置后退出回溯
                    break;
            }
        }
    }
}

int main()
{
    int n;
    printf(" 皇后问题(n<20) n=");
    scanf_s("%d", &n);
    printf(" %d皇后问题求解如下：\n", n);
    queen(n);
    printf("\n");
    return 0;
}