#include <iostream>
using namespace std;

class Time
{
private:
    int minute; // 分
    int sec;    // 秒

public:
    Time(int m = 0, int s = 0) // 构造函数：初始化分和秒
    {
        minute = m;
        sec = s;
    }

    void show() // 输出当前时间
    {
        cout << "当前时间："
            << minute << " 分 "
            << sec << " 秒" << endl;
    }

    Time& operator++() // 重载前置 ++：走一秒
    {
        sec++;                 // 秒加1
        if (sec >= 60)         // 如果秒满60
        {
            sec = 0;           // 秒归0
            minute++;          // 分钟加1
        }
        return *this;          // 返回自身（前置++常这么写）
    }
};

int main(void)
{
    int m, s; // 用来保存用户输入的分和秒
    int step; // 用来保存要走多少秒
    int i;    // 循环变量

    cout << "请输入初始分钟和秒：";
    cin >> m >> s;

    cout << "请输入要走多少秒：";
    cin >> step;

    Time t(m, s); // 创建秒表对象
    cout << "初始：";
    t.show();

    for (i = 0; i < step; i++) // 每循环一次代表走一秒
    {
        ++t;                   // 调用重载的 ++，让时间走一秒
    }

    cout << "走完后：";
    t.show();

    return 0;
}
