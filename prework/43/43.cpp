#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s; // 用来保存读入的整行字符串

    cout << "请输入一整行：";
    getline(cin, s); // 读取整行（可以包含空格）

    cout << "你输入的整行是：" << s << endl;
    return 0;
}
