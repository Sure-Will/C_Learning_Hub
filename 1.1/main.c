#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int chinese, math, english;
    double avg;

    printf("请输入语文、数学、英语成绩：");

    if (scanf("%d %d %d", &chinese, &math, &english) != 3)
    {
        return 1;
    }

    avg = (chinese + math + english) / 3.0;
    printf("平均成绩为：%.2f\n", avg);

    return(0);

}