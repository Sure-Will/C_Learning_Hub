#include <stdio.h>

int main(void)
{
    int score;                 // 用来保存每次输入的成绩
    int count80 = 0;           // 用来统计 80 分及以上的人数
    int countFail = 0;         // 用来统计不及格（<60）的人数
    double sum = 0.0;          // 用来累加总分（用 double 方便算平均值）
    int i;                     // 循环变量

    printf("请依次输入 10 个同学的成绩：\n");

    for (i = 1; i <= 10; i++)  // 循环 10 次，分别读入 10 个成绩
    {
        printf("请输入第 %d 个成绩：", i);

        if (scanf_s("%d", &score) != 1) // 判断是否成功读到一个整数
        {
            printf("输入错误：请输入整数成绩。\n");
            return 0;
        }

        sum += score;          // 把当前成绩累加到总分里

        if (score >= 80)       // 判断是否 80 分及以上
        {
            count80++;         // 满足就人数加 1
        }

        if (score < 60)        // 判断是否不及格（默认 <60）
        {
            countFail++;       // 不及格人数加 1
        }
    }

    printf("\n80分及以上人数：%d\n", count80);
    printf("不及格人数（<60）：%d\n", countFail);
    printf("平均分：%.2f\n", sum / 10.0); // 总分除以 10 得到平均值

    return 0;
}
