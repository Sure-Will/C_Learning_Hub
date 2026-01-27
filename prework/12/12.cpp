#include <stdio.h>

int main(void)
{
    int a[11];             // 用来保存数组（最多支持 10 个原始数 + 1 个新数）
    int n;                  // 用来保存原来有多少个数
    int x;                  // 用来保存要插入的新数
    int i;                  // 循环变量

    printf("请输入N（原来有多少个整数，N<=10）：");
    if (scanf_s("%d", &n) != 1 || n < 1 || n > 10) // 读取 N 并做简单范围判断
    {
        printf("输入错误：N 应该是 1~10 的整数。\n");
        return 0;
    }

    printf("请依次输入 %d 个已排序的整数（从小到大）：", n);
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &a[i]); // 把第 i 个整数存入数组
    }

    printf("请输入要插入的新整数：");
    scanf_s("%d", &x); // 读取新数 x

    i = n - 1; // 从最后一个元素开始比较
    while (i >= 0 && a[i] > x) // 只要 a[i] 比 x 大，就往后挪
    {
        a[i + 1] = a[i];       // 把 a[i] 往后移动一格
        i--;                   // 继续往前找位置
    }

    a[i + 1] = x; // 找到位置后，把 x 放进去（i+1 就是插入点）

    printf("插入后的有序结果为：");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d", a[i]);    // 输出第 i 个数
        if (i != n) printf(" "); // 不是最后一个就输出空格
    }
    printf("\n");

    return 0;
}
