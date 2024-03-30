#include<iostream>
using namespace std;

#define MaxSize 100 //定义栈中元素的最大个数
typedef struct SqStack {
    int data[MaxSize]; //存放栈中的元素
    int top; //栈顶指针
}SqStack;

//初始化
void InitStack(SqStack& S) {
    S.top = -1;
}

//判栈空
bool Empty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

//入栈
void Push(SqStack& S, int x) {
    if (S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    }
    S.data[++S.top] = x;
}

//出栈
void Pop(SqStack& S, int& x) {
    if (S.top == -1) {
        cout << "栈空" << endl;
        return;
    }
    x = S.data[S.top--];
}

//读栈顶元素
int GetTop(SqStack S) {
    if (S.top == -1) {
        cout << "栈空" << endl;
        return -1;
    }
    else {
        return S.data[S.top];
    }
}

//遍历栈
void PrintStack(SqStack S) {
    while (S.top != -1) {
        cout << S.data[S.top--] << " ";
    }
    cout << endl;
}

//销毁栈
void DestroyStack(SqStack& S) {
    S.top = -1;
}

int main() {
    SqStack S;
    InitStack(S);
    Push(S, 1);//入栈
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    cout << "栈顶元素为：" << GetTop(S) << endl;
    cout << "出栈顺序为：";
    PrintStack(S);
    int x;
    Pop(S, x);
    cout << x << "出栈" << endl;
    cout << "栈中剩余元素：";
    PrintStack(S);
    Pop(S, x);
    cout << x << "出栈" << endl;
    cout << "栈中剩余元素：";
    PrintStack(S);
    if (!Empty(S)) {
        cout << "当前栈不为空" << endl;
    }
    else {
        cout << "当前栈为空" << endl;
    }
    return 0;
}
