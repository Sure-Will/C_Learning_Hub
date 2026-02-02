#include <stdio.h>

int is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int year, int month) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return is_leap_year(year) ? 29 : 28;
	}
}

int days_between(int year, int month, int day) {
	int total_days = 0;

	for (int i = 1970; i < year; i++) {
		total_days += is_leap_year(i) ? 366 : 365;
	}

	for (int i = 1; i < month; i++) {
		total_days += days_in_month(year, i);
	}

	total_days += day - 1;

	return total_days;
}

const char *day_of_week(int days) {
	const char *days_of_week[] = {
		"Thursday","Friday", "Saturday",
		"Sunday", "Monday","Tuesday", "Wednesday"
	};
	return days_of_week[days % 7];

}

int main(void) {
	int year = 0, month = 0, day = 0;

	printf("请输入日期（年 月 日）：");
	scanf_s("%d %d %d", &year, &month, &day);

	if (year < 1970 || (year == 1970 && month < 1) || (year == 0 && month < 1 && day < 1)) {
		printf("输入的日期必须在1970年1月1日之后!\n");
		return 1;
	}

	int days = days_between(year, month, day);

	printf("%d年%d月%d日是%s\n", year, month, day, day_of_week(days));
	return 0;

}