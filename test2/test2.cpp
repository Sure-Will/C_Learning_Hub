// 这是一个单行注释
#include <stdio.h>  //标准库的头文件

int add(int x, int y); //函数的声明

int main()
{
    //来自于标准库头文件stdio.h函数
    //格式化打印
    int a = 1;
    int b = 2;
    int c = 3, d = 4, e = 5;
    printf("Hello,world, a:%d\n", a);
    printf("(a + b)=%d\n", add(a, b));
    return 0;
}

// 补充 add 函数的实现
int add(int x, int y)
{
    return x + y;
}