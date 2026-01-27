#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // 创建一个vector对象

    // 先放入10个整数（这里我放 1~10，你也可以换成别的）
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i); // 把 i 加到vector末尾
    }

    // 用迭代器把每个元素变成原来的2倍
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        *it = (*it) * 2; // it 指向元素，*it 就是那个元素本身
    }

    // 输出vector内容
    cout << "翻倍后的vector内容为：";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it; // 输出当前元素
        if (it + 1 != v.end()) cout << " "; // 不是最后一个就输出空格
    }
    cout << endl;

    return 0;
}
