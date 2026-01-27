#include <iostream>
using namespace std;

class Tree
{
private:
    int ages; // 用来保存树龄

public:
    Tree(int a) // 构造函数：初始化树龄
    {
        ages = a; // 把传入的初始树龄保存到 ages
    }

    void grow(int years) // 让树长 years 年
    {
        ages += years; // ages 加上 years
    }

    void showAge() // 输出当前树龄
    {
        cout << "当前树龄为：" << ages << endl; // 打印 ages
    }
};

int main()
{
    Tree t(3);          // 定义一个 Tree 对象，初始树龄设为 3

    t.showAge();        // 显示当前树龄
    t.grow(5);          // 让树再长 5 年
    t.showAge();        // 再显示一次树龄

    return 0;
}
