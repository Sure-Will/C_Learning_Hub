#include <stdio.h>
#include <math.h>  // 引入数学库，用于sqrt（开平方根）函数

int main()
{
    double a, b, c;  // 存储三角形的三条边，用double类型支持小数

    // 第1步：输入三条边
    printf("请输入三角形的三条边（用空格分隔）：");
    scanf_s("%lf %lf %lf", &a, &b, &c);  // %lf 是double类型的格式符

    // 第2步：判断能否构成三角形（三角形成立条件：任意两边之和大于第三边）
    if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0)
    {
        printf("\n可以组成三角形！\n");

        // 第3步：判断三角形类型
        printf("三角形类型：");

        // 判断是否为等边三角形（三条边都相等）
        if (a == b && b == c)
        {
            printf("等边三角形\n");
        }
        // 判断是否为等腰三角形（任意两条边相等）
        else if (a == b || a == c || b == c)
        {
            printf("等腰三角形\n");
        }
        // 判断是否为直角三角形（勾股定理：最长边的平方 = 另外两边的平方和）
        // 需要考虑浮点数误差，所以用fabs判断差值是否小于0.0001
        else if (fabs(a * a + b * b - c * c) < 0.0001 ||
            fabs(a * a + c * c - b * b) < 0.0001 ||
            fabs(b * b + c * c - a * a) < 0.0001)
        {
            printf("直角三角形\n");
        }
        else
        {
            printf("普通三角形\n");
        }

        // 第4步：计算面积（使用海伦公式）
        // 海伦公式：s = (a+b+c)/2，面积 = sqrt(s*(s-a)*(s-b)*(s-c))
        double s = (a + b + c) / 2;  // s是半周长
        double area = sqrt(s * (s - a) * (s - b) * (s - c));  // 计算面积

        printf("三角形面积：%.2lf\n", area);  // %.2lf 表示保留2位小数
    }
    else
    {
        // 如果不能构成三角形，输出提示信息
        printf("\n不能组成三角形！\n");
        printf("原因：三角形的任意两边之和必须大于第三边。\n");
    }

    return 0;
}