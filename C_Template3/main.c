#include <stdio.h>

void foo(void) {
	int x = 10;          // 局部变量：只在 foo 里可见
	printf("x = %d\n", x);
}

int main(void) {
	foo();               // 调用时创建 x，函数结束后就销毁
	// printf("%d\n", x); // 这一行会报错：x 在这里不可见
	return 0;
}