#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a(10); // 用vector保存10个整数
    int i, j;          // 循环变量
    int temp;          // 用来交换的临时变量

    cout << "请输入10个整数（用空格分隔）：";
    for (i = 0; i < 10; i++)
    {
        cin >> a[i]; // 读入第 i 个整数
    }

    // 冒泡排序：从小到大
    for (i = 0; i < 9; i++) // 需要比较 9 轮
    {
        for (j = 0; j < 9 - i; j++) // 每一轮把最大的“冒”到后面
        {
            if (a[j] > a[j + 1])    // 如果前面比后面大，就交换
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "排序后的结果（从小到大）：";
    for (i = 0; i < 10; i++)
    {
        cout << a[i];           // 输出第 i 个数
        if (i != 9) cout << " "; // 不是最后一个就输出空格
    }
    cout << endl;

    return 0;
}
