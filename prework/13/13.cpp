#include <stdio.h>

int main(void)
{
    int n;              // 用来遍历 100 到 200 的整数
    int count = 0;      // 用来统计符合条件的个数

    printf("100~200之间满足：除3余2、除5余3、除7余2 的整数有：\n");

    for (n = 100; n <= 200; n++) // 从 100 遍历到 200（含 200）
    {
        if (n % 3 == 2 && n % 5 == 3 && n % 7 == 2) // 同时满足三个取余条件
        {
            printf("%d ", n);    // 输出符合条件的数
            count++;             // 计数加 1
        }
    }

    printf("\n共有 %d 个。\n", count);

    return 0;
}
