#include <iostream>

using namespace std;

const int N = 100010;

int m;
//һ����stk��ʾջ����tt��ʾ�±�
int stk[N], tt;


int main() {
    int M;
    cin >> M;
    while (M--) {
        string op;
        int x;
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if (op == "pop") tt--;
        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;
        else cout << stk[tt] << endl;

    }
}

