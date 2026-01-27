#include <iostream>
using namespace std;

class Mammal
{
public:
    virtual void speak() // 基类虚函数：让派生类可以重写
    {
        cout << "Mammal is speaking..." << endl; // 基类默认说话方式
    }

    virtual ~Mammal() {} // 虚析构：好习惯
};

class Dog : public Mammal
{
public:
    void speak() override // 重写基类的 speak()
    {
        cout << "Dog: 汪汪！" << endl; // 狗的说话方式
    }
};

int main()
{
    Dog d;        // 声明一个 Dog 类对象
    d.speak();    // 直接调用 Dog 的 speak()

    // 额外演示：用基类指针调用（更能体现“虚函数”的作用）
    Mammal* p = &d;  // 基类指针指向 Dog 对象
    p->speak();      // 会调用 Dog::speak()

    return 0;
}
