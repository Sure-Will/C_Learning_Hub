#include <iostream>
#include <cstring>   // 包含 strcmp() 函数
using namespace std;

int main() {
    char s1[100], s2[100];  // 定义两个字符数组（C风格字符串）

    cout << "请输入第一个字符串：";
    cin >> s1;

    cout << "请输入第二个字符串：";
    cin >> s2;

    // C 风格字符串必须用 strcmp() 函数比较
    int result = strcmp(s1, s2);  // 比较两个字符串

    if (result == 0) {
        cout << "两个字符串相等" << endl;
    }
    else if (result > 0) {
        cout << "\"" << s1 << "\" 大于 \"" << s2 << "\"" << endl;
    }
    else {
        cout << "\"" << s1 << "\" 小于 \"" << s2 << "\"" << endl;
    }

    return 0;
}
