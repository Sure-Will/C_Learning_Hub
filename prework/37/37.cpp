#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    double a, b, c; // 三条边长

    int isValid() const // 判断是否能构成三角形
    {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

public:
    Triangle(double x = 1, double y = 1, double z = 1) // 构造函数：初始化三边
    {
        a = x;
        b = y;
        c = z;
    }

    double area() const // 计算面积
    {
        if (!isValid()) return 0.0;          // 不合法就返回0（避免sqrt负数）
        double p = (a + b + c) / 2.0;        // 半周长p
        return sqrt(p * (p - a) * (p - b) * (p - c)); // 海伦公式
    }

    void show() const // 显示三边与面积
    {
        cout << "三边为：" << a << ", " << b << ", " << c
            << "  面积=" << area() << endl;
    }

    friend double operator+(const Triangle& t1, const Triangle& t2); // 重载+
};

double operator+(const Triangle& t1, const Triangle& t2) // 返回面积之和
{
    return t1.area() + t2.area(); // 两个面积直接相加
}

int main()
{
    double a1, b1, c1;
    double a2, b2, c2;

    cout << "请输入第1个三角形三边：";
    cin >> a1 >> b1 >> c1;

    cout << "请输入第2个三角形三边：";
    cin >> a2 >> b2 >> c2;

    Triangle t1(a1, b1, c1);
    Triangle t2(a2, b2, c2);

    cout << "t1：";
    t1.show();
    cout << "t2：";
    t2.show();

    cout << "两个三角形面积之和 t1 + t2 = " << (t1 + t2) << endl;

    return 0;
}
