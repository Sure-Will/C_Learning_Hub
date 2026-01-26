#include <stdio.h>

static cube_int(int n) {
	return n * n * n;
}

static int is_armstrong_number(int n) {
	if (n < 100 || n > 999) {
		return 0;
	}
	int hundreds = n / 100;
	int tens = n / 10 % 10;
	int ones = n % 10;

	int sum = cube_int(hundreds) + cube_int(tens) + cube_int(ones);

	return sum == n;
}

static int print_all_armstrong_number(void) {
	int count = 0;

	for (int n = 100; n <= 999; ++n) {
		if (is_armstrong_number(n)) {
			printf("%d\n", n);
			count++;
		}

	}

	return count;
}

int main(void) {
	puts("所有水仙花数如下：");
	int total = print_all_armstrong_number();
	printf("总共有：%d个\n", total);

	return 0;
}