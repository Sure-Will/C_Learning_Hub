#include <stdio.h>                               

int main(void)
{
    int n; // 数组元素个数
    int a[100]; // 数组（最多100个元素，可自行调整）

    printf("请输入数组里的元素个数："); // 提示输入n
    scanf_s("%d", &n);                          

    printf("请依次输入这%d个元素：", n); // 提示输入数组元素
    for (int i = 0; i < n; i++)  // 循环读入n个数
        scanf_s("%d", &a[i]); // 将每个数存入a[i]

    for (int i = 0, j = n - 1; i < j; i++, j--) // i从左走，j从右走，直到相遇
    {
        int temp = a[i]; // 暂存左边元素
        a[i] = a[j]; // 右边元素换到左边
        a[j] = temp; // 暂存元素换到右边
    }

    printf("逆序后的数组为："); // 输出提示
    for (int i = 0; i < n; i++) // 输出逆序后的数组
    {
        if (i > 0) printf(" "); // 控制空格分隔
        printf("%d", a[i]); // 输出当前元素
    }
    printf("\n");

    return 0; 
}
