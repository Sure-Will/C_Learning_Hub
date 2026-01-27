#include <stdio.h>

double FtoC(double f) // 把华氏温度 f 转成摄氏温度并返回
{
    double c = (f - 32.0) * 5.0 / 9.0; // 按公式计算摄氏温度（用小数避免整数除法）
    return c; // 把计算结果返回给主函数
}

int main(void)
{
    double f; // 用来保存用户输入的华氏温度
    double c; // 用来保存转换后的摄氏温度

    printf("请输入华氏温度F：");
    if (scanf_s("%lf", &f) != 1) // 读取一个 double（%lf），读不到就报错退出
    {
        printf("输入错误：请输入数字。\n");
        return 0;
    }

    c = FtoC(f); // 调用函数，把 f 转成摄氏温度
    printf("对应的摄氏温度C为：%.2f\n", c); // 保留两位小数输出

    return 0;
}
