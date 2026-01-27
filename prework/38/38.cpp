#include <iostream>
using namespace std;

// 第一个 add 函数：计算两个整数的和
int add(int a, int b) {
    return a + b;  // 返回两个整数相加的结果
}

// 第二个 add 函数：计算两个浮点数的和
// 函数名相同，但参数类型不同，这就是函数重载
double add(double a, double b) {
    return a + b;  // 返回两个浮点数相加的结果
}

int main() {
    int a, b;
    double x, y;

    cout << "请输入两个整数：";
    cin >> a >> b;
    cout << "整数之和：" << add(a, b) << endl;

    cout << "请输入两个浮点数：";
    cin >> x >> y;
    cout << "浮点数之和：" << add(x, y) << endl;

    return 0;
}
