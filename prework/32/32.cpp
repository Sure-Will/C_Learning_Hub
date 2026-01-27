#include <iostream>
using namespace std;

// 定义 Box 类
class Box {
private:
    // 私有成员变量：盒子的三个尺寸
    double length;  // 长
    double width;   // 宽
    double height;  // 高

public:
    // 设置盒子形状（设置长、宽、高）
    void setShape(double l, double w, double h) {
        length = l;   // 把传入的参数 l 赋值给成员变量 length
        width = w;    // 把传入的参数 w 赋值给成员变量 width
        height = h;   // 把传入的参数 h 赋值给成员变量 height
    }

    // 计算并返回盒子体积
    double getVolume() {
        return length * width * height;  // 体积 = 长 × 宽 × 高
    }

    // 计算并返回盒子表面积
    double getSurfaceArea() {
        // 表面积 = 2 × (长×宽 + 长×高 + 宽×高)
        return 2 * (length * width + length * height + width * height);
    }
};

int main() {
    Box box;  // 创建一个 Box 对象，名字叫 box
    double l, w, h;

    // 让用户输入盒子的尺寸
    cout << "请输入盒子的长：";
    cin >> l;
    cout << "请输入盒子的宽：";
    cin >> w;
    cout << "请输入盒子的高：";
    cin >> h;

    box.setShape(l, w, h);  // 调用成员函数设置盒子形状

    // 输出结果
    cout << "盒子的体积为：" << box.getVolume() << endl;
    cout << "盒子的表面积为：" << box.getSurfaceArea() << endl;

    return 0;
}
