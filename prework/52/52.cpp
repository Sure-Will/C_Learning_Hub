#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 1) 准备一个 list<char*>（指向C风格字符串）
    list<const char*> li; // 用 const char* 更安全：表示不修改字符串内容
    li.push_back("Hello");
    li.push_back("world");
    li.push_back("C-style");
    li.push_back("string");

    // 2) 把 list 里的 char* 元素赋值给 vector<string>
    vector<string> vs; // 用来保存转换后的string
    for (list<const char*>::iterator it = li.begin(); it != li.end(); ++it)
    {
        vs.push_back(string(*it)); // 把 C字符串转换成 string 并放入vector
    }

    // 3) 输出 vector<string> 验证
    cout << "vector<string> 内容为：" << endl;
    for (size_t i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << endl; // 输出第 i 个字符串
    }

    return 0;
}
