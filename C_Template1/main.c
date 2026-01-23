#include <stdio.h>

int add(int x, int y) {   // 函数定义：返回两数之和
    return x + y;
}

int main(void) {
    int a, b;

    printf("请输入两个整数：");
    scanf_s("%d %d", &a, &b);  // MSVC 用 scanf_s

    int result = add(a, b);    // 函数调用
    printf("结果是：%d\n", result);

    return 0;
}