#include <iostream>
#include <stdlib.h>

using namespace std;

//˫����
typedef struct DNode
{
    int data;
    struct DNode* prior;
    struct DNode* next;
}DNode;

void CreateDListB(DNode** L, int a[], int n); //β�巨����˫����
void DispDList(DNode* L); //���˫����
void InsertDList(DNode** L, int i, int e);//λ��i����Ԫ��e
void DelDList(DNode** L, int i);//ɾ����iλ��Ԫ��
void DestoryDList(DNode** L);//��������


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

void CreateDListB(DNode** L, int a[], int n) //β�巨����˫����
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

void DispDList(DNode* L) //���˫����
{
    DNode* p = L;//pָ��ͷ�ڵ�
    while (p != NULL)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

void InsertDList(DNode** L, int i, int e)//λ��i����Ԫ��e
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

void DelDList(DNode** L, int i)//ɾ����iλ��Ԫ��
{
    DNode* p = *L;//pָ��ͷ���
    int j = 0;
    while (p != NULL && j < i - 1)//p��λ��i-1�ڵ�
    {
        p = p->next;
        j++;
    }
    p->next = p->next->next;
}

void DestoryDList(DNode** L)//��������
{
    DNode* p = *L, * p2 = (*L)->next;//pָ��ͷ���,p2ָ���׽ڵ�
    while (p != NULL)
    {
        free(p);
        p = p2;
        p2 = p2->next;
    }
}