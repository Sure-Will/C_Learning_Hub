#include <stdio.h>

long long Funct(int n) // 定义一个函数 Funct，输入一个整数 n，返回一个 long long 类型（超长整型）的数
{
	if (n == 0 || n == 1) return 1; // 基础情况处理：如果 n 是 0 或 1，直接返回 1

	long long prev2 = 1; // prev2 代表"前两项"，初始化为 1 (对应 n=0 的值)
	long long prev1 = 1; // prev1 代表"前一项"，初始化为 1 (对应 n=1 的值)
	long long current = 0; // current 用于存储当前正在计算的那一项的值

	for (int i = 2; i <= n; i++) // 从第 3 项（索引为 2）开始循环计算，直到第 n 项
	{
		current = prev1 + prev2; // 核心逻辑：当前项 = 前一项 + 前两项

		// 准备下一次循环，像窗口滑动一样更新变量：
		prev2 = prev1;// 原来的"前一项"变成下一次的"前两项"
		prev1 = current;// 原来的"当前项"变成下一次的"前一项"
	}

	return current;
}

int main()
{
	for (int i = 0; i <= 50; i++) // 循环打印从第 0 项到第 50 项的斐波那契数
	{
		printf("Funct(%d) = %lld\n", i, Funct(i));// %d 对应 int 类型的 i；%lld 对应 long long 类型的返回值
	}

	return 0;
}
