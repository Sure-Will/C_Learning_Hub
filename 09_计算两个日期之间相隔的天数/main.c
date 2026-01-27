#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int days_in_month(int year, int month) {
	static const int table[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month < 0 || month >= 12) {
		return 0;
	}
	if (month == 2) {
		return (28 + (is_leap_year(year) ? 1 : 0));
	}
}

bool is_valid_date(int year, int month, int day) {

}

void next_day(int *year, int *month, int *day) {

}

bool read_date(int *year, int *month, int *day) {

}

void clear_input_line(void) {

}

void print_date(int year, int month, int day) {


}

void print_next_day(int year, int month, int day) {


}

int main(void) {
	return 0;
}