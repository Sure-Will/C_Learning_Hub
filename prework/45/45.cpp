#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;    // 用来存每次读到的一个字符串（一个词）
    string result;  // 用来保存拼接后的大字符串

    cout << "请输入多个字符串（用空格分开，输入结束按 Ctrl+Z 再回车）：\n";

    while (cin >> word)           // 每次读入一个字符串（遇空格换行就算分隔）
    {
        result += word;           // 直接拼接，不加空格
    }

    cout << "连接后的大字符串为：\n" << result << endl;
    return 0;
}
