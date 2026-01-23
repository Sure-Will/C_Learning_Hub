#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
键盘输入一个位于(0, 1)范围内的浮点数，并将其转化为百分比形式，
结果保留一位小数。例如：输入0.12转换为12.0%，而输入0.1234转换为12.3%。
*/
int main(void)
{
	double x; //输入的小数
	double p; //输出的百分数

	printf("请输入一个位于0到1之间的浮点数：");

	if (scanf("%lf", &x) != 1)
	{
		printf("输入的格式错误！/n");
		return 1;
	}

	if (x <= 0 || x >= 1) //注意到题目是开区间
	{
		printf("输入的数字不在范围内！/n");
		return 1;
	}
	
	p = x * 100; //转成百分制
	printf("转换为百分比：%.1f%%", p);
	
	return 0;

}
