#include <stdio.h>

int main(void)
{
    int n, k, m;                 // n人数，k起始编号，m报到m出列
    int alive[1000];             // alive[i]=1 表示编号 i+1 还在圈里（n不要超过1000）
    int left;                    // 还剩多少人没出列
    int idx;                     // 当前指向的位置（用下标0~n-1）
    int count;                   // 当前已经数到几了
    int i;                       // 循环变量

    printf("请输入 n k m（例如：5 2 3）：");
    if (scanf_s("%d %d %d", &n, &k, &m) != 3) // 读取3个整数
    {
        printf("输入错误：请按格式输入 n k m。\n");
        return 0;
    }

    if (n <= 0 || k < 1 || k > n || m <= 0 || n > 1000) // 做简单合法性检查
    {
        printf("输入范围错误：要求 n>0, 1<=k<=n, m>0, 且 n<=1000。\n");
        return 0;
    }

    for (i = 0; i < n; i++) alive[i] = 1; // 初始化：所有人都在圈里
    left = n;                              // 还剩 n 个人
    idx = k - 1;                           // 把编号k转成下标（k=1对应0）
    count = 0;                             // 当前报数从0开始累积

    printf("出列顺序为：");

    while (left > 0)                       // 只要还有人，就继续循环
    {
        if (alive[idx] == 1)               // 只对还在圈里的人报数
        {
            count++;                       // 报数+1
            if (count == m)                // 报到m，这个人出列
            {
                printf("%d", idx + 1);     // 输出出列人的编号（下标+1）
                left--;                    // 圈里人数减少
                alive[idx] = 0;            // 标记出列
                count = 0;                 // 下一轮从1重新报数

                if (left > 0) printf(" "); // 不是最后一个就输出空格
            }
        }

        idx++;                             // 指向下一个位置
        if (idx == n) idx = 0;             // 到末尾就回到开头，实现“围成一圈”
    }

    printf("\n");
    return 0;
}
