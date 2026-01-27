#include <stdio.h>

int main(void)
{
    int i, j; // i 表示行号，j 表示列号

    for (i = 1; i <= 5; i++) // 控制 5 行
    {
        for (j = 1; j <= 5; j++) // 控制每行 5 个数   
        {
            int val; // 用来保存当前位置要输出的数字

            if (j <= i)
                val = i - j + 1; // 左下三角：从 i 递减到 1
            else
                val = 1;         // 右上部分：全是 1

            printf("%d", val);   // 按题目示例紧挨着输出
        }
        printf("\n");            // 每输出完一行就换行
    }

    return 0;
}
