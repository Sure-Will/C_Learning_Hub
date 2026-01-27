#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;

    // 方式1：使用输入运算符 >>
    cout << "请输入一行文字（用 >> 读取）：";
    cin >> s1;
    cout << ">> 读取到的内容：[" << s1 << "]" << endl;

    cin.ignore();  // 清除缓冲区中残留的换行符（重要！）

    // 方式2：使用 getline 函数
    cout << "请输入一行文字（用 getline 读取）：";
    getline(cin, s2);
    cout << "getline 读取到的内容：[" << s2 << "]" << endl;

    return 0;
}
