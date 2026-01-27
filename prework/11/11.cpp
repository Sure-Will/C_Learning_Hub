#include <stdio.h>

int main(void)
{
    long long n;                 // 用来保存用户输入的自然数
    long long remain;            // 用来保存还没有分解完的部分
    long long i;                 // 用来从 2 开始尝试做除数

    printf("请输入一个自然数：");
    if (scanf_s("%lld", &n) != 1) // 读取一个 long long，读不到就退出
    {
        printf("输入错误：请输入整数。\n");
        return 0;
    }

    printf("%lld=", n);          // 先输出“n=”
    printf("1");                 // 按题目示例，最前面固定输出 1

    if (n == 1)                  // n=1 时，结果就是 1=1
    {
        printf("\n");
        return 0;
    }

    remain = n;                  // 从 n 开始分解

    i = 2;                       // 从 2 开始试除
    while (remain > 1)           // remain 变成 1 说明分解完了
    {
        if (remain % i == 0)     // 如果能整除，说明 i 是一个因子
        {
            printf("*%lld", i);  // 输出这个因子
            remain /= i;         // 把 remain 除掉这个因子，继续分解
        }
        else
        {
            i++;                 // 不能整除就换下一个 i
        }
    }

    printf("\n");
    return 0;
}
