#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int read_sides(double* a, double* b, double* c) {
	printf("请输入三条边：");
	return scanf("%lf %lf %lf", a, b, c) == 3;
}

int is_triangle(double a, double b, double c) {
	return a > 0 && b > 0 && c > 0
		&& a + b > c
		&& a + c > b
		&& b + c > a;
}

double area(double a, double b, double c) {
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void print_input_invalid(void) {
	printf("输入无效！\n");
}

void print_not_triangle(void) {
	printf("输入的三条边无法构成三角形！\n");
}

void print_area(double area) {
	printf("三角形面积为：%f\n", area);
}

int main(void) {
	double a = 0, b = 0, c = 0;

	if (!read_sides(&a, &b, &c)) {
		print_input_invalid();
		return 1;
	}

	if (!is_triangle(a, b, c)) {
		print_not_triangle();
		return 1;
	}

	print_area(area(a, b, c));
	return 0;


}



