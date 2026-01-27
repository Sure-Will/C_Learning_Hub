#include <iostream>
using namespace std;

const double PI = 3.14159;  // 定义圆周率常量


// 基类 Base：所有图形的"父类"

class Base {
public:
    // 虚函数：用 virtual 关键字声明
    // = 0 表示这是"纯虚函数"，基类不实现，强制派生类必须实现
    virtual double getArea() = 0;

    // 虚析构函数：基类有虚函数时，析构函数也应该是虚的（好习惯）
    virtual ~Base() {}
};


// 派生类1：三角形 Triangle

class Triangle : public Base {  // : public Base 表示继承自 Base
private:
    double base;    // 底边长
    double height;  // 高

public:
    // 构造函数：初始化三角形的底和高
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    // 重写虚函数：实现三角形的面积计算
    // override 关键字表示这是重写父类的虚函数（可选但推荐写）
    double getArea() override {
        return 0.5 * base * height;  // 三角形面积 = 底 × 高 ÷ 2
    }
};


// 派生类2：正方形 Square

class Square : public Base {
private:
    double side;  // 边长

public:
    // 构造函数：初始化正方形的边长
    Square(double s) {
        side = s;
    }

    // 重写虚函数：实现正方形的面积计算
    double getArea() override {
        return side * side;  // 正方形面积 = 边长²
    }
};


// 派生类3：圆形 Circle

class Circle : public Base {
private:
    double radius;  // 半径

public:
    // 构造函数：初始化圆的半径
    Circle(double r) {
        radius = r;
    }

    // 重写虚函数：实现圆形的面积计算
    double getArea() override {
        return PI * radius * radius;  // 圆面积 = π × 半径²
    }
};


int main() {
    // 创建三个不同图形的对象
    Triangle tri(10, 5);   // 三角形：底10，高5
    Square squ(6);         // 正方形：边长6
    Circle cir(4);         // 圆形：半径4

    // 直接调用各对象的 getArea() 函数
    cout << "三角形面积：" << tri.getArea() << endl;
    cout << "正方形面积：" << squ.getArea() << endl;
    cout << "圆形面积：" << cir.getArea() << endl;

    cout << endl << "--- 使用基类指针演示多态 ---" << endl;

    // 用基类指针指向不同的派生类对象（多态的精髓！）
    Base* p;  // 声明一个基类指针

    p = &tri;  // 指向三角形
    cout << "三角形面积：" << p->getArea() << endl;

    p = &squ;  // 指向正方形
    cout << "正方形面积：" << p->getArea() << endl;

    p = &cir;  // 指向圆形
    cout << "圆形面积：" << p->getArea() << endl;

    return 0;
}