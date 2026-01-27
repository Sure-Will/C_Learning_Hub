#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    deque<string> dq; // 用来保存读入的字符串序列
    string s;         // 用来保存每次读到的一个字符串

    cout << "请输入若干字符串（用空格分开，结束请输入 Ctrl+Z 再回车）：\n";

    while (cin >> s)          // 每次读入一个字符串（遇空格/换行会分隔）
    {
        dq.push_back(s);      // 把读到的字符串放到deque末尾
    }

    cout << "deque中的元素为：\n";
    for (deque<string>::iterator it = dq.begin(); it != dq.end(); ++it)
    {
        cout << *it << endl;  // 输出迭代器指向的元素
    }

    return 0;
}
