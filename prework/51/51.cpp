#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    // ---------- 1) 用 list<int> 初始化 vector<double> ----------
    list<int> li; // 准备一个 list<int>
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);

    vector<double> vd1(li.begin(), li.end()); // 区间构造：int 自动转 double

    cout << "由 list<int> 初始化得到的 vector<double>：";
    for (size_t i = 0; i < vd1.size(); i++)
    {
        cout << vd1[i]; // 输出第 i 个元素
        if (i + 1 != vd1.size()) cout << " ";
    }
    cout << endl;

    // ---------- 2) 用 vector<int> 初始化 vector<double> ----------
    vector<int> vi; // 准备一个 vector<int>
    vi.push_back(10);
    vi.push_back(20);
    vi.push_back(30);

    vector<double> vd2(vi.begin(), vi.end()); // 同样用区间构造

    cout << "由 vector<int> 初始化得到的 vector<double>：";
    for (size_t i = 0; i < vd2.size(); i++)
    {
        cout << vd2[i];
        if (i + 1 != vd2.size()) cout << " ";
    }
    cout << endl;

    return 0;
}
