#include <stdio.h>

int isLeapYear(int y) // 判断 y 是否闰年：闰年2月有29天
{
    if (y % 400 == 0) return 1;              // 能被400整除是闰年
    if (y % 4 == 0 && y % 100 != 0) return 1; // 能被4整除但不能被100整除是闰年
    return 0;                                 // 其他情况不是闰年
}

int daysInMonth(int y, int m) // 返回某年某月的天数
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31; // 大月31天
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;                                 // 小月30天
    // 走到这里说明是 2 月
    return isLeapYear(y) ? 29 : 28; // 闰年29天，平年28天
}

void nextSecond(int* y, int* mo, int* d, int* h, int* mi, int* s) // 把时间变为下一秒
{
    (*s)++;                              // 先加1秒
    if (*s < 60) return;                 // 秒没到60就结束

    *s = 0;                              // 秒归0，分钟进1
    (*mi)++;
    if (*mi < 60) return;                // 分钟没到60就结束

    *mi = 0;                             // 分钟归0，小时进1
    (*h)++;
    if (*h < 24) return;                 // 小时没到24就结束

    *h = 0;                              // 小时归0，日期进1
    (*d)++;

    {
        int maxDay = daysInMonth(*y, *mo); // 计算当月最大天数
        if (*d <= maxDay) return;          // 日期没超过当月天数就结束
    }

    *d = 1;                              // 日期归1，月份进1
    (*mo)++;
    if (*mo <= 12) return;               // 月份没超过12就结束

    *mo = 1;                             // 月份归1，年份进1
    (*y)++;
}

int main(void)
{
    int y, mo, d, h, mi, s; // 用来保存输入的年月日时分秒

    printf("请输入年 月 日 时 分 秒（用空格分开）：");
    if (scanf_s("%d %d %d %d %d %d", &y, &mo, &d, &h, &mi, &s) != 6) // 必须读到6个整数
    {
        printf("输入错误：请按格式输入6个整数。\n");
        return 0;
    }

    nextSecond(&y, &mo, &d, &h, &mi, &s); // 调用函数，计算下一秒

    printf("下一秒为：%d年%d月%d日 %d时%d分%d秒\n", y, mo, d, h, mi, s);

    return 0;
}
