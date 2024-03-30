#include<iostream>
using namespace std;

#define MaxSize 100 //����ջ��Ԫ�ص�������
typedef struct SqStack {
    int data[MaxSize]; //���ջ�е�Ԫ��
    int top; //ջ��ָ��
}SqStack;

//��ʼ��
void InitStack(SqStack& S) {
    S.top = -1;
}

//��ջ��
bool Empty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

//��ջ
void Push(SqStack& S, int x) {
    if (S.top == MaxSize - 1) {
        cout << "ջ��" << endl;
        return;
    }
    S.data[++S.top] = x;
}

//��ջ
void Pop(SqStack& S, int& x) {
    if (S.top == -1) {
        cout << "ջ��" << endl;
        return;
    }
    x = S.data[S.top--];
}

//��ջ��Ԫ��
int GetTop(SqStack S) {
    if (S.top == -1) {
        cout << "ջ��" << endl;
        return -1;
    }
    else {
        return S.data[S.top];
    }
}

//����ջ
void PrintStack(SqStack S) {
    while (S.top != -1) {
        cout << S.data[S.top--] << " ";
    }
    cout << endl;
}

//����ջ
void DestroyStack(SqStack& S) {
    S.top = -1;
}

int main() {
    SqStack S;
    InitStack(S);
    Push(S, 1);//��ջ
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    cout << "ջ��Ԫ��Ϊ��" << GetTop(S) << endl;
    cout << "��ջ˳��Ϊ��";
    PrintStack(S);
    int x;
    Pop(S, x);
    cout << x << "��ջ" << endl;
    cout << "ջ��ʣ��Ԫ�أ�";
    PrintStack(S);
    Pop(S, x);
    cout << x << "��ջ" << endl;
    cout << "ջ��ʣ��Ԫ�أ�";
    PrintStack(S);
    if (!Empty(S)) {
        cout << "��ǰջ��Ϊ��" << endl;
    }
    else {
        cout << "��ǰջΪ��" << endl;
    }
    return 0;
}
