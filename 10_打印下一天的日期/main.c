	#include <stdio.h>
	#include <stdbool.h>

	/* 业务逻辑层 */
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

	void next_day(int *year, int *month, int *day) {
		if (year == NULL || month == NULL || day == NULL) {
			return;
		}

		int dim = days_in_month(*year, *month);
		if (dim == 0) {
			return;
		}

		(*day)++;

		if (*day > dim) {
			*day = 1;
			(*month)++;

			if (*month > 12) {
				*month = 1;
				(*year)++;
			}
		}
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
	bool read_date(int *year, int *month, int *day) {
		if (year == NULL || month == NULL || day == NULL) {
			return false;
		}
		printf("请输入日期（年/月/日，例如 2004/3/31）：");
		if (scanf_s("%d/%d/%d", year, month, day) != 3) {
			puts("格式错误：请严格按 年/月/日 输入。");
			clear_input_line();
			return false;
		}

		clear_input_line();

		if (!is_valid_date(*year, *month, *day)) {
			puts("日期不存在：请检查月份范围和当前天。");
			return false;
		}

		return true;

	}

	/* 打印日期：只负责输出格式 */
	void print_date(int year, int month, int day) {
		printf("%d年%d月%d日", year, month, day);
	}

	int main(void) {
		int year = 0, month = 0, day = 0;
		while (!read_date(&year, &month, &day)) {

		}

		next_day(&year, &month, &day);
		printf("下一天是：");
		print_date(year, month, day);
		putchar('\n');
			return 0;
	}