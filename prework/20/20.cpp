#include <stdio.h>

void itoa(int n, char s[]) // 把整数 n 转成字符串，结果放到 s 里
{
    long long x = n;        // 用 long long 接一下，避免 -INT_MIN 溢出
    int sign = 0;           // 用来记录是否是负数
    int i = 0;              // 用来表示当前写到 s 的哪个位置

    if (x < 0)              // 如果是负数先记号，再转成正数处理
    {
        sign = 1;           // 记录负号
        x = -x;             // 变成正数再拆数字
    }

    if (x == 0)             // 特判：输入为 0 时要输出 "0"
    {
        s[i++] = '0';       // 把字符 '0' 放进字符串
    }
    else
    {
        while (x > 0)       // 反复取个位数字
        {
            int digit = (int)(x % 10); // 取出个位
            s[i++] = (char)('0' + digit); // 把数字变成字符存进去（注意此时是倒序）
            x /= 10;        // 去掉个位
        }
    }

    if (sign)               // 如果原来是负数，补一个 '-'
    {
        s[i++] = '-';       // 负号也先按“倒序”放进去
    }

    s[i] = '\0';            // 字符串结束符

    // 把 s[0..i-1] 反转，让数字顺序正确
    {
        int left = 0;       // 左指针
        int right = i - 1;  // 右指针
        while (left < right)
        {
            char temp = s[left]; // 交换两个字符
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}

int main(void)
{
    int n;            // 用来保存输入的整数
    char s[50];       // 用来保存转换后的字符串（空间要够大）

    printf("请输入一个整数：");
    if (scanf_s("%d", &n) != 1) // 读取整数，读不到就退出
    {
        printf("输入错误：请输入整数。\n");
        return 0;
    }

    itoa(n, s);       // 调用 itoa，把 n 转成字符串放进 s
    printf("转换后的字符串为：%s\n", s);

    return 0;
}
