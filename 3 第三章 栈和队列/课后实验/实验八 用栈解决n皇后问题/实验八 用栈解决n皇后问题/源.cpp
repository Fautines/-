#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 100
typedef struct
{
    int data[MaxSize];	//data[i]��ŵ�i���ʺ���к�
    int top;			//ջ��ָ��
} StType;				//����˳��ջ����
int count = 0;
int place(StType st, int i, int j)  //����(i,j)�Ƿ���1��i-1�ʺ��г�ͻ
{
    int a = 0;         //aΪ�����ķ���ֵ
    int k = 1;
    if (i == 1)
    {
        a = 1;
        return a;	//�ŵ�һ���ʺ�ʱû�г�ͻ
    }
    while (k <= i - 1)			//j=1��k-1���ѷ����˻ʺ����
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
void queen(int n)					//���n�ʺ�����
{
    int i, j, k;
    int find = 0;
    StType st;						//����ջst
    st.top = 0;						//��ʼ��ջ��ָ��
    st.top++;						//��(1,1)��ջ
    st.data[st.top] = 1;
    while (st.top > 0)				//ջ����ʱѭ��
    {
        i = st.top;					//��ǰ�ʺ�Ϊ��i���ʺ�
        if (st.top == n)				//���лʺ���ź�,���һ����
        {
            printf("��%d���⣺", ++count);
            for (k = 1; k <= st.top; k++)
                printf("(%d,%d) ", k, st.data[k]);
            printf("\n");
        }
        find = 0;
        for (j = 1; j <= n; j++)
            if (place(st, i + 1, j))	//��i+1���ҵ�һ���Żʺ��λ��(i+1,j)
            {
                st.top++;
                st.data[st.top] = j;
                find = 1;
                break;
            }
        if (find == 0)			//��i+1���Ҳ����Żʺ��λ��,����
        {
            while (st.top > 0)
            {
                if (st.data[st.top] == n)	//����û�пɷ�λ��,��ջ
                    st.top--;
                for (j = st.data[st.top] + 1; j <= n; j++)	//�ڱ�������һ��λ��
                    if (place(st, st.top, j))
                    {
                        st.data[st.top] = j;
                        break;
                    }
                if (j > n)				//��ǰ�ʺ��ڱ���û�пɷŵ�λ��
                    st.top--;			//��ջ
                else					//�����ҵ�һ��λ�ú��˳�����
                    break;
            }
        }
    }
}

int main()
{
    int n;
    printf(" �ʺ�����(n<20) n=");
    scanf_s("%d", &n);
    printf(" %d�ʺ�����������£�\n", n);
    queen(n);
    printf("\n");
    return 0;
}