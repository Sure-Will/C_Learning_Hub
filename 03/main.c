#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/* 题1：判断奇数（位运算） */
bool isOdd(int n)
{
	return (n & 1);
}

/* 题2：判断是否为2的幂（正整数） */
int isPowerOfTwo(int n)
{
	return (n > 0) && ((n & (n - 1)) == 0);
}


/* 题3：求 Last Set Bit（最低有效位的1对应的值）*/
int last_set_bit(int n) {
	int bit = 1;            // 从最低位 1 开始
	while ((n & bit) == 0)
	{
		bit <<= 1;          // 这一位不是 1 就继续往左
	}

	return bit;             // 返回对应的 2^k
}

int main(void) {
	int n;
	bool odd;
	bool pow2;
	unsigned int lsb = 0;

	printf("请输入一个整数n：");
	scanf_s("%d", &n);

	odd = isOdd(n);
	pow2 = isPowerOfTwo(n);

	if (odd) {
		printf("%d 是奇数\n", n);
	}
	else {
		printf("%d 是偶数\n", n);
	}

	if (pow2) {
		printf("%d 是2的幂\n", n);
	}
	else {
		printf("%d 不是2的幂\n", n);
	}

	if (n == 0) {
		printf("n=0时没有最低有效位1（题目要求 n!= 0）\n");
	}
	else {
		lsb = last_set_bit(n);
		printf("%d的最低有效位1对应的值是：%u\n", n, lsb);
	}

	return 0;
}