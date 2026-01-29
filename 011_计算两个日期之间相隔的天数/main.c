#include <stdio.h>
#include <stdbool.h>


/* 业务逻辑层 */
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
		if (is_leap_year(y)){
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

}

bool is_leap_year(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
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

}

/* 打印日期：只负责输出格式 */
void print_date(int year, int month, int day) {
	printf("%d年%d月%d日", year, month, day);
}

int main(void) {
	int y1 = 2021, m1 = 1, d1 = 1, y2 = 2021, m2 = 1, d2 = 2;
	bool r = is_earlier_date(y1, m1, d1, y2, m2, d2); // ← 在这一行打断点
	return 0;
}