#include <stdio.h>

long sum(int n) // 递归计算 1^2 + 2^2 + ... + n^2
{
    if (n == 1) return 1;          // 递归出口：sum(1)=1
    return sum(n - 1) + (long)n * n; // 递推：sum(n)=sum(n-1)+n^2（转 long 防溢出更稳）
}

int main(void)
{
    int n; // 用来保存用户输入的 n

    printf("请输入n（n>0）：");
    if (scanf_s("%d", &n) != 1 || n <= 0) // 读取 n 并判断是否大于 0
    {
        printf("输入错误：n 必须是正整数。\n");
        return 0;
    }

    printf("sum(%d) = %ld\n", n, sum(n)); // 调用递归函数并输出结果
    return 0;
}
