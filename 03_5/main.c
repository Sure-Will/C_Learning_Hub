#include <stdio.h>

int main(void) {
	int n; //用户输入的个数
	int ans = 0; // 用来保存异或后的结果
	int x; //用来保存当前输入的数字

	printf("请输入数组元素个数n：");
	if ((scanf_s("%d", &n) != 1) || n <= 0){
		printf("输入有误！n必须是正整数。\n");
		return 1;
	}
	
	printf("请依次输入 %d 个整数：\n", n);
	for (int i = 0; i < n; i++) {
		if (scanf_s("%d", &x) != 1 ) {
			printf("输入有误！请确保输入的是整数:\n");
			return 1;
		}
		ans ^= x;
	}

	printf("只出现一次的数字：%d", ans);
	return 0;

}