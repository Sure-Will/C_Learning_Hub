#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
    map<string, int> m; // key是string，value是int

    // 下标操作用的类型：string（也就是key的类型）
    string key = "apple"; // 这是一个可以用于 m[key] 的类型

    m[key] = 10;          // m[key] 返回的是 int&，所以可以直接赋值
    m["banana"] = 20;     // 也可以直接用字符串字面量（能转成string）

    // 用一个引用接住，能更直观看出它是“引用”
    int& ref = m["apple"]; // ref 绑定到 map 里 "apple" 对应的 value

    cout << "m[\"apple\"] = " << m["apple"] << endl;
    cout << "ref = " << ref << endl;

    // 修改 ref 会影响 map 里的值，证明它是引用
    ref = 99;
    cout << "修改 ref 后，m[\"apple\"] = " << m["apple"] << endl;

    return 0;
}
