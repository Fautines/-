#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];//next数组
char s[M], p[N];//s表示字符串，p表示模板串

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;//表示p和s都是从下标为1开始存放到数组中
    //计算next数组
    for (int i = 2, j = 0; i <= n; i++)//指针i不回溯，当i=1的时候表示
    {
        while (j && p[i] != p[j + 1]) j = ne[j];//当当前模式串无法匹配上的时候，指针j就回next一次
        if (p[i] == p[j + 1]) j++;//如果能匹配上，指针j就进一个
        ne[i] = j;//区别于匹配字符串每次都要在next数组中记录值
    }
    //匹配字符串
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];//如果无法匹配，指针j回退
        //用while是由于移动后可能仍然失配，所以要继续移动直到匹配或整个p串移到后面（j = 0)
        if (s[i] == p[j + 1]) j++;//当前元素匹配，j移向p串下一位
        if (j == n)
        {//匹配成功
            printf("%d ", i - n);
            j = ne[j];//继续匹配下一个子串
        }
    }

    return 0;
}

