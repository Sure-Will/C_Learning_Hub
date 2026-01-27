#include <stdio.h>

void replacePart(char a[], const char b[]) // 把 b[第5~17个] 复制到 a，从 a 的第12个位置开始替换
{
    int aStart = 11;   // a 的第12个字符(从1开始数) -> 下标 11（从0开始数）
    int bStart = 4;    // b 的第5个字符 -> 下标 4
    int bEnd = 16;     // b 的第17个字符 -> 下标 16
    int i, k;

    k = aStart; // 从 aStart 位置开始写入，等价于“替换 a 的后半段”

    for (i = bStart; i <= bEnd && b[i] != '\0'; i++)
    {
        a[k++] = b[i]; // 把 b 的指定字符复制到 a
    }

    a[k] = '\0'; // 结束字符串，截断 a 原来后面的内容
}

int main(void)
{
    char a[100] = "My name is Li jilin.";                 // 字符串 a（可修改）
    char b[100] = "Mr. Zhang Haoling is very happy.";     // 字符串 b

    printf("原字符串a：%s\n", a);
    printf("字符串b：%s\n", b);

    replacePart(a, b); // 调用函数进行替换

    printf("处理后a：%s\n", a);
    return 0;
}
