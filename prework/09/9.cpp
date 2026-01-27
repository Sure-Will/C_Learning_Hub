#include <stdio.h>

int main(void)
{
    int score;                 // 用来保存每次输入的成绩
    int maxScore = 0;          // 用来保存最高成绩
    int minScore = 0;          // 用来保存最低成绩
    int count = 0;             // 用来统计输入了多少个有效成绩

    while (1)
    {
        printf("请输入学生成绩（输入负数结束）：");

        if (scanf_s("%d", &score) != 1)   // 判断是否成功读到一个整数
        {
            printf("输入不是整数，程序结束。\n");
            return 0;                     // 直接结束程序，避免死循环
        }

        if (score < 0)                    // 输入负数则结束输入
        {
            break;
        }

        if (count == 0)                   // 第一个有效成绩：初始化最大最小值
        {
            maxScore = score;             // 第一次输入当作最高分
            minScore = score;             // 第一次输入当作最低分
        }
        else                               // 后续成绩：更新最大最小值
        {
            if (score > maxScore) maxScore = score;  // 如果更大就更新最高分
            if (score < minScore) minScore = score;  // 如果更小就更新最低分
        }

        count++;                           // 有效成绩数量 +1
    }

    if (count == 0)                        // 没有输入任何有效成绩
    {
        printf("没有输入任何成绩，无法统计最高分和最低分。\n");
    }
    else
    {
        printf("共输入 %d 个成绩。\n", count);
        printf("最高成绩：%d\n", maxScore);
        printf("最低成绩：%d\n", minScore);
    }

    return 0;
}
