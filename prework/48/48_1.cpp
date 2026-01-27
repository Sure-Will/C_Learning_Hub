#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;  // 定义两个 string 对象

    cout << "请输入第一个字符串：";
    cin >> s1;

    cout << "请输入第二个字符串：";
    cin >> s2;

    // std::string 可以直接用运算符比较
    if (s1 == s2) {
        cout << "两个字符串相等" << endl;
    }
    else if (s1 > s2) {
        cout << "\"" << s1 << "\" 大于 \"" << s2 << "\"" << endl;
    }
    else {
        cout << "\"" << s1 << "\" 小于 \"" << s2 << "\"" << endl;
    }

    return 0;
}