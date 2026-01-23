#include <stdio.h>

int main(void) {
	int score;

	printf("请输入成绩（0-100）：");
	if (scanf_s("%d", &score) != 1) {
		puts("输入有误！");
		return 1;
	}

	if (score < 0 || score > 100) {
		puts("请输入有效成绩");
		return 1;
	}

	switch (score / 10) {

	case 10:
	case 9:
		puts("成绩为A");
		break;
	case 8:
		puts("成绩为B");
		break;
	case 7:
		puts("成绩为C");
		break;
	case 6:
		puts("成绩为D");
		break;
	default:
		puts("成绩为F");
		break;
	}

	return 0;
}