#include <stdio.h>

int main(void)
{
    double r;                 // 用来保存用户输入的半径
    double h;                 // 用来保存用户输入的高
    double s;                 // 用来保存底面积
    double v;                 // 用来保存体积
    double pi = 3.1415926;    // 用来保存圆周率（不用复杂库）

    printf("请输入圆柱半径 r：");
    if (scanf_s("%lf", &r) != 1) // 读取半径，读不到就退出
    {
        printf("输入错误：请输入数字。\n");
        return 0;
    }

    printf("请输入圆柱高度 h：");
    if (scanf_s("%lf", &h) != 1) // 读取高度，读不到就退出
    {
        printf("输入错误：请输入数字。\n");
        return 0;
    }

    s = pi * r * r;           // 计算底面积 S=πr²
    v = s * h;                // 计算体积 V=S*h

    printf("底面积 S = %.2f\n", s); // 输出底面积，保留两位小数
    printf("体积 V = %.2f\n", v);   // 输出体积，保留两位小数

    return 0;
}
