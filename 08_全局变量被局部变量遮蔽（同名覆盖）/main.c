#include <stdio.h>

int global_num = 1;  // 全局变量

void test1(void) {
	int global_num = 10; // 局部变量，遮蔽全局变量
	printf("test1: global_num = %d\n", global_num);
}

int main(void) {
	printf("main: global_num = %d\n", global_num); // 访问全局变量
	test1();
	printf("main: global_num = %d\n", global_num); // 仍是全局变量
	return 0;
}