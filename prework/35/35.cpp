#include <iostream>
using namespace std;

class Complex
{
private:
    double real; // 实部
    double imag; // 虚部

public:
    Complex(double r = 0, double i = 0) // 构造函数：给实部/虚部赋初值
    {
        real = r;
        imag = i;
    }

    void print() // 输出复数
    {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl; // 虚部为正时输出 a + bi
        else
            cout << real << " - " << -imag << "i" << endl; // 虚部为负时输出 a - bi
    }

    friend Complex operator+(const Complex& a, const Complex& b); // 声明友元：重载 +
};

Complex operator+(const Complex& a, const Complex& b) // 友元函数：实现 a + b
{
    Complex temp;                 // 用来保存结果
    temp.real = a.real + b.real;  // 实部相加
    temp.imag = a.imag + b.imag;  // 虚部相加
    return temp;                  // 返回结果
}

int main(void)
{
    double r1, i1, r2, i2; // 用来保存输入的两个复数的实部和虚部

    cout << "请输入第1个复数的实部和虚部（用空格分开）：";
    cin >> r1 >> i1;

    cout << "请输入第2个复数的实部和虚部（用空格分开）：";
    cin >> r2 >> i2;

    Complex c1(r1, i1);      // 创建第1个复数对象
    Complex c2(r2, i2);      // 创建第2个复数对象
    Complex c3 = c1 + c2;    // 使用重载的 + 进行复数相加

    cout << "c1 = ";
    c1.print();

    cout << "c2 = ";
    c2.print();

    cout << "c1 + c2 = ";
    c3.print();

    return 0;
}
