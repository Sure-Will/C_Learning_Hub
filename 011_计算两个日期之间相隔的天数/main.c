#include <stdio.h>
#include <stdbool.h>


/* 业务逻辑层 */

bool is_leap_year(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool is_earlier_date(int y1, int m1, int d1, int y2, int m2, int d2) {
	if (y1 != y2) {
		return y1 < y2;
	}
	else if (m1 != m2) {
		return m1 < m2;
	}
	else {
		return d1 < d2;
	}
}

long long days_from_1_1_1(int year, int month, int day) {
	long long total = 0;
	for (int y = 1; y < year; y++) {
		if (is_leap_year(y)) {
			total += 366;
		}
		else {
			total += 365;
		}

	}
	for (int m = 1; m < month; m++) {
		total += days_in_month(year, m);
	}
	total += day;
	return total;
}

long long days_between(int y1, int m1, int d1, int y2, int m2, int d2) {
	long long t1 = days_from_1_1_1(y1, m1, d1);
	long long t2 = days_from_1_1_1(y2, m2, d2);
	return t2 - t1;
}



int days_in_month(int year, int month) {
	static const int table[12] = {
		31,28,31,30,31,30,
		31,31,30,31,30,31
	};

	if (month < 1 || month > 12) {
		return 0;
	}
	if (month == 2) {
		return 28 + (is_leap_year(year) ? 1 : 0);
	}

	return table[month - 1];
}

bool is_valid_date(int year, int month, int day) {
	if (year <= 0) {
		return false;
	}

	int dim = days_in_month(year, month);
	if (dim == 0) {
		return false;
	}

	if (day < 1 || day > dim) {
		return false;
	}

	return true;
}



/* 输入输出层 */

void clear_input_line(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
	}
}

/*
读取日期：要求格式 年/月/日
- 成功读取并且日期合法：返回 true
- 否则返回 false（由 main 决定是否重试）
*/
bool read_two_dates_ordered(int *y1, int *m1, int *d1, int *y2, int *m2, int *d2) {
	if (y1 == NULL || m1 == NULL || d1 == NULL || y2 == NULL || m2 == NULL || d2 == NULL) {
		return false;
	}

	printf("请输入第一个日期（年/月/日，例如 2020/1/1）：");
	if (scanf_s("%d/%d/%d", y1, m1, d1) != 3) {
		puts("格式错误：请严格按照 年/月/日 输入。");
		clear_input_line();
		return false;
	}
	clear_input_line();

	if (!is_valid_date(*y1, *m1, *d1)) {
		puts("第一个日期不存在：请检查月份范围和当月天数。");
		return false;
	}

	printf("请输入第二个日期（年/月/日，例如 2021/1/2）：");
	if (scanf_s("%d/%d/%d", y2, m2, d2) != 3) {
		puts("格式错误：请严格按照 年/月/日 输入。");
		clear_input_line();
		return false;
	}
	clear_input_line();

	if (!is_valid_date(*y2, *m2, *d2)) {
		puts("第二个日期不存在：请检查月份范围和当月天数。");
		return false;
	}

	if (!is_earlier_date(*y1, *m1, *d1, *y2, *m2, *d2)) {
		puts("输入顺序错误：第一个日期必须严格早于第二个日期。");
		return false;
	}
	return true;
}

/* 打印日期：只负责输出格式 */
void print_date(int year, int month, int day) {
	printf("%d年%d月%d日", year, month, day);
}

int main(void) {
	int y1, m1, d1, y2, m2, d2;



	if (read_two_dates_ordered(&y1, &m1, &d1, &y2, &m2, &d2)) {
		long long diff = days_between(y1, m1, d1, y2, m2, d2);
		printf("日期1：%d年%d月%d日\n", y1, m1, d1);
		printf("日期2：%d年%d月%d日\n", y2, m2, d2);
		printf("这两个日期之间相隔 %lld 天\n", diff);
	}
	else {
		puts("日期输入无效，请重新运行程序并输入有效日期。");
	}
	return 0;
}