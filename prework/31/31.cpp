#include <iostream>
using namespace std;

class String
{
public:
    char head[100]; // 用来存放字符串（最多99个字符 + '\0'）

    String(char* Head) // 构造函数：初始化 head
    {
        int i = 0; // 用来控制复制到第几个字符

        if (Head == NULL) // 防止传进来的是空指针
        {
            head[0] = '\0'; // 设置为空字符串
            return;
        }

        while (Head[i] != '\0' && i < 99) // 最多复制99个字符，避免越界
        {
            head[i] = Head[i]; // 把Head里的字符复制到head里
            i++;
        }
        head[i] = '\0'; // 补上字符串结束符
    }

    void reverse() // 把 head 里的字符串逆序存放
    {
        int len = 0; // 用来统计字符串长度
        int left, right;
        char temp;

        while (head[len] != '\0') // 计算字符串长度
        {
            len++;
        }

        left = 0;          // 左边下标从0开始
        right = len - 1;   // 右边下标从最后一个字符开始

        while (left < right) // 左右交换直到中间
        {
            temp = head[left];       // 暂存左边字符
            head[left] = head[right]; // 左边放右边
            head[right] = temp;      // 右边放暂存的左边

            left++;
            right--;
        }
    }

    void print() // 输出 head 里的字符串
    {
        cout << head << endl; // 直接输出字符数组
    }
};

int main()
{
    char input[100]; // 用来接收用户输入的一行字符串

    cout << "请输入一行字符串（最多99个字符）：";
    cin.getline(input, 100); // 读入一整行（包含空格）

    String s(input); // 用输入内容初始化对象

    cout << "原字符串：";
    s.print();

    s.reverse(); // 逆序

    cout << "逆序后的：";
    s.print();

    return 0;
}
