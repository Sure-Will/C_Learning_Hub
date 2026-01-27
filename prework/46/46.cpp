#include <iostream>
#include <string>
#include <cctype>    // 包含 ispunct() 函数
using namespace std;

int main() {
    string input;   // 存储用户输入的原始字符串
    string result;  // 存储去除标点后的结果

    cout << "请输入一个包含标点符号的字符串：" << endl;
    getline(cin, input);  // 读取整行输入（包括空格）

    // 遍历输入字符串中的每一个字符
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];  // 取出第 i 个字符

        // ispunct(ch) 判断 ch 是否是标点符号
        // 如果不是标点符号，就把它加到结果字符串中
        if (!ispunct(ch)) {
            result += ch;  // 把字符追加到 result 末尾
        }
    }

    cout << "去除标点后：" << result << endl;

    return 0;
}