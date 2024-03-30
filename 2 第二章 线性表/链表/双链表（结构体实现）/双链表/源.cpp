#include <iostream>
#include <stdlib.h>

using namespace std;

//双链表
typedef struct DNode
{
    int data;
    struct DNode* prior;
    struct DNode* next;
}DNode;

void CreateDListB(DNode** L, int a[], int n); //尾插法创建双链表
void DispDList(DNode* L); //输出双链表
void InsertDList(DNode** L, int i, int e);//位置i插入元素e
void DelDList(DNode** L, int i);//删除第i位置元素
void DestoryDList(DNode** L);//销毁链表


int main()
{
    DNode* L;
    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
    CreateDListB(&L, a, 10);
    InsertDList(&L, 1, 2);
    DelDList(&L, 1);
    DispDList(L);

    DestoryDList(&L);
    DispDList(L);

    return 0;
}

void CreateDListB(DNode** L, int a[], int n) //尾插法创建双链表
{
    DNode* r, * s;
    *L = (DNode*)malloc(sizeof(DNode));
    r = *L;
    for (int i = 0;i < n;i++) {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = a[i];s->prior = r;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void DispDList(DNode* L) //输出双链表
{
    DNode* p = L;//p指向头节点
    while (p != NULL)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

void InsertDList(DNode** L, int i, int e)//位置i插入元素e
{
    DNode* p, * s, * q;
    p = *L;

    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    s = (DNode*)malloc(sizeof(DNode));
    s->data = e;

    q = p->next;
    s->next = q;q->prior = s;
    p->next = s;s->prior = p;
}

void DelDList(DNode** L, int i)//删除第i位置元素
{
    DNode* p = *L;//p指向头结点
    int j = 0;
    while (p != NULL && j < i - 1)//p定位第i-1节点
    {
        p = p->next;
        j++;
    }
    p->next = p->next->next;
}

void DestoryDList(DNode** L)//销毁链表
{
    DNode* p = *L, * p2 = (*L)->next;//p指向头结点,p2指向首节点
    while (p != NULL)
    {
        free(p);
        p = p2;
        p2 = p2->next;
    }
}