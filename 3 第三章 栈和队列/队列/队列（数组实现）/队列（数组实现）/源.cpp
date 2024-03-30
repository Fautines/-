#include <iostream>

using namespace std;

const int N = 100010;

int m;
//q[N]表示队列，hh表示队列的头，tt表示队列的尾
//为了区别栈和队列，队列的tt一般默认-1
int q[N], hh, tt = -1;


int main()
{
    cin >> m;

    while (m--)
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[++tt] = x;
        }
        else if (op == "pop") hh++;
        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}
