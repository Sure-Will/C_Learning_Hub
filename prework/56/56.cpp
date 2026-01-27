#include <iostream>
#include <string>
using namespace std;

string makeName(string name, const string& pre, const string& suf)
{
    name.insert(name.begin(), pre.begin(), pre.end()); // 在开头插入前缀（用迭代器区间）
    name.append(" ");                                  // 先补一个空格，让后缀更自然
    name.append(suf);                                  // 在末尾追加后缀
    return name;                                       // 返回新字符串
}

int main()
{
    string name; // 用来保存用户输入的名字
    string pre;  // 用来保存前缀
    string suf;  // 用来保存后缀

    cout << "请输入名字（例如 Tom）：";
    getline(cin, name); // 读取整行，避免名字里有空格时读不全

    cout << "请输入前缀（例如 Mr. 或 Ms.，可留空）：";
    getline(cin, pre); // 读取前缀

    cout << "请输入后缀（例如 Jr. 或 III，可ा 可留空）：";
    getline(cin, suf); // 读取后缀

    // 为了让输出更自然：如果用户输入的前缀非空且末尾没空格，就补一个空格
    if (!pre.empty() && pre.back() != ' ')
        pre.append(" "); // 保证前缀后面有空格

    string result = makeName(name, pre, suf); // 调用函数生成新名字
    cout << "生成的新字符串为：" << result << endl;

    return 0;
}
