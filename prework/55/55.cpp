#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;        // 用来保存读入的字符序列
    s.reserve(100);  // 预留至少100个字符的空间，减少反复扩容

    char ch; // 用来保存每次读到的一个字符
    cout << "请输入字符（输入结束按 Ctrl+Z 再回车）：\n";

    while (cin.get(ch))   // 每次读一个字符（包括空格和换行）
    {
        s.push_back(ch);  // 把字符追加到string末尾
    }

    cout << "读入的内容为：\n" << s << endl;
    return 0;
}
