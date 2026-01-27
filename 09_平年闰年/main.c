#include <stdio.h>
#include <stdbool.h>
/*
用C语言编写程序实现以下需求：

编写一个函数，输入一个公元年份（如2004），判断该年是否为闰年，并返回判断结果。

平年闰年的规则如下：

如果年份不是4的倍数，则是平年。
如果年份是4的倍数但不是100的倍数，则是闰年。
如果年份是100的倍数但不是400的倍数，则是平年。
如果年份是400的倍数，则是闰年。
要求使用bool类型作为函数的返回值。

注意：日历有一系列的题目，这道题编写的函数在下一道题目中可能会用到。
*/

bool is_leap_year(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int read_year(void) {
	int year = 0;

	printf("请输入公元年份（如 2004）：");
	if (scanf_s("%d", &year) == 1) {
		if (year > 0) {
			return year;
		}
		puts("输入的不是正整数，请重新输入");
	}
	else {
		puts("输入的不是整数，请重新输入");
	}
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {

	}

}

void print_year_type(int year, bool is_leap) {
	if (is_leap) {
		printf("%d年是闰年", year);
	}
	else {
		printf("%d年是平年", year);
	}
}


int main(void) {
	int year = read_year();
	bool leap = is_leap_year(year);
	print_year_type(year, leap);
	return 0;
}