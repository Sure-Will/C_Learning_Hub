#include <iostream>
using namespace std;

// 定义计数器类
class Counter {
private:
    int value;  // 计数器的值（私有成员，外部不能直接访问）

public:
    // 构造函数：创建对象时初始化计数器值，默认为0
    Counter(int v = 0) {
        value = v;
    }

    // 增值函数：让计数器加1
    void increment() {
        value++;
    }

    // 减值函数：让计数器减1
    void decrement() {
        value--;
    }

    // 获取当前计数值
    int getValue() {
        return value;
    }
};

int main() {
    Counter c(10);  // 创建计数器对象，初始值为10

    cout << "初始值：" << c.getValue() << endl;

    // 增值3次
    c.increment();
    c.increment();
    c.increment();
    cout << "增值3次后：" << c.getValue() << endl;

    // 减值1次
    c.decrement();
    cout << "减值1次后：" << c.getValue() << endl;

    return 0;
}