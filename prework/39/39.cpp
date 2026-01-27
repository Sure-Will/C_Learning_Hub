#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;      // 纯虚函数：让Shape成为抽象类
    virtual ~Shape() {}             // 虚析构：用基类指针删除派生类更安全
};

class Rectangle : public Shape
{
private:
    double w; // 宽
    double h; // 高

public:
    Rectangle(double width, double height) // 构造函数：初始化长宽
    {
        w = width;
        h = height;
    }

    double area() override // 计算长方形面积
    {
        return w * h; // 面积=宽*高
    }
};

class Trapezoid : public Shape
{
private:
    double a; // 上底
    double b; // 下底
    double h; // 高

public:
    Trapezoid(double top, double bottom, double height) // 构造函数：初始化上底下底高
    {
        a = top;
        b = bottom;
        h = height;
    }

    double area() override // 计算梯形面积
    {
        return (a + b) * h / 2.0; // 面积=(上底+下底)*高/2
    }
};

class Circle : public Shape
{
private:
    double r; // 半径

public:
    Circle(double radius) // 构造函数：初始化半径
    {
        r = radius;
    }

    double area() override // 计算圆面积
    {
        double pi = 3.1415926; // 圆周率（不用复杂库）
        return pi * r * r;     // 面积=πr²
    }
};

int main()
{
    Shape* p; // 基类指针：可以指向任意派生类对象

    Rectangle rect(3, 4);      // 长方形：宽3 高4
    Trapezoid trap(3, 5, 4);   // 梯形：上底3 下底5 高4
    Circle cir(2);             // 圆：半径2

    p = &rect; // 基类指针指向长方形对象
    cout << "长方形面积：" << p->area() << endl; // 通过虚函数计算面积

    p = &trap; // 基类指针指向梯形对象
    cout << "梯形面积：" << p->area() << endl;   // 自动调用Trapezoid::area()

    p = &cir;  // 基类指针指向圆对象
    cout << "圆形面积：" << p->area() << endl;   // 自动调用Circle::area()

    return 0;
}
