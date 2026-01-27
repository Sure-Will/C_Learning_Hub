#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    list<int> li;       // 原始list，用来保存一串整数
    deque<int> dqEven;  // 用来保存偶数
    deque<int> dqOdd;   // 用来保存奇数

    // 这里先放一些数据，你也可以改成从键盘输入
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    li.push_back(6);
    li.push_back(7);
    li.push_back(8);

    // 遍历list，把元素按奇偶拷贝到两个deque
    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        if ((*it) % 2 == 0)           // 判断是不是偶数
            dqEven.push_back(*it);    // 偶数放到dqEven
        else
            dqOdd.push_back(*it);     // 奇数放到dqOdd
    }

    // 输出结果验证
    cout << "原 list 内容：";
    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "偶数 deque 内容：";
    for (deque<int>::iterator it = dqEven.begin(); it != dqEven.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "奇数 deque 内容：";
    for (deque<int>::iterator it = dqOdd.begin(); it != dqOdd.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
