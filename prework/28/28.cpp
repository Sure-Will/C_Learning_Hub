#include <stdio.h>

int main(void)
{
    int a[10];              // 用来保存10个整数
    int i, j;               // i控制第几趟，j控制相邻比较的位置
    int temp;               // 用来交换两个数
    int swapped;            // 用来记录这一趟有没有发生交换

    printf("请依次输入 10 个整数：\n");
    for (i = 0; i < 10; i++)
    {
        printf("请输入第 %d 个整数：", i + 1);
        if (scanf_s("%d", &a[i]) != 1) // 读取第 i 个整数
        {
            printf("输入错误：请输入整数。\n");
            return 0;
        }
    }

    for (i = 0; i < 9; i++)           // 共需要做 9 趟
    {
        swapped = 0;                  // 每一趟开始前先假设没有交换

        for (j = 0; j < 9 - i; j++)   // 每趟比较到最后未排好位置为止
        {
            if (a[j] > a[j + 1])      // 如果前一个比后一个大就交换
            {
                temp = a[j];          // 交换 a[j] 和 a[j+1]
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;          // 记录发生了交换
            }
        }

        if (swapped == 0)             // 如果这一趟一次都没交换，说明已经有序
        {
            break;                    // 提前结束排序
        }
    }

    printf("从小到大排序结果为：");
    for (i = 0; i < 10; i++)
    {
        printf("%d", a[i]);           // 输出排序后的数组
        if (i != 9) printf(" ");
    }
    printf("\n");

    return 0;
}
