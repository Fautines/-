#include <iostream>

using namespace std;

const int N = 100010;

int m;
//q[N]��ʾ���У�hh��ʾ���е�ͷ��tt��ʾ���е�β
//Ϊ������ջ�Ͷ��У����е�ttһ��Ĭ��-1
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
