#include <stdio.h>

int main() {
    int a, b;  // 声明两个变量，暂时不赋值

    printf("请输入第一个数 a：");
    scanf_s("%d", &a);  // 从键盘读取一个整数，存到变量a中

    printf("请输入第二个数 b：");
    scanf_s("%d", &b);  // 从键盘读取一个整数，存到变量b中

    printf("交换前：a = %d, b = %d\n", a, b);

    // 用加减法交换（不用第三个变量）
    a = a + b;
    b = a - b;
    a = a - b;

    printf("交换后：a = %d, b = %d\n", a, b);

    return 0;
}