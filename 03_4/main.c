#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0;
	int b = 0;
	int ret = 0;
	printf("请输入a和b的值：");
	ret = scanf("%d %d", &a, &b);
	if (ret != 2) {
		printf("输入有误，请输入两个整数。\n");
		return 1;
	}
	
	printf("读入后：%d %d\n", a, b);

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("交换后a和b的值分别为：%d %d\n", a, b);
	return 0;
}