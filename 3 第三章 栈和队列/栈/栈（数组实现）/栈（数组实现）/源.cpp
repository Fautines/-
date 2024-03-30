#include <iostream>

using namespace std;

const int N = 100010;

int m;
//一般用stk表示栈，用tt表示下标
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

