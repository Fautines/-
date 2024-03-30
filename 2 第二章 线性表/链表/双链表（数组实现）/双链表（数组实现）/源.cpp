#include<iostream>

using namespace std;

const int N = 100010;

int m;
//e[i]表示的是节点i的值是多少
//
//
//
int e[N], l[N], r[N], idx;


//初始化
void init() {
    // 0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}


//在下标是k点的右边，插入x
void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];//①
    l[idx] = k;//②
    l[r[k]] = idx;//③
    r[k] = idx;//④
    idx++;
}


//删除第k个点
void remove(int k) {
    r[l[k]] = r[k];//让该点的左边的右边等于该点的右边
    l[r[k]] = l[k];//让该点的右边的左边等于该点的左边
}


int main() {
    cin >> m;
    init();
    while (m--) {
        string op;
        cin >> op;
        int k, x;
        if (op == "L") {
            cin >> x;
            add(0, x);
        }
        else if (op == "R") {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "D") {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else {
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}