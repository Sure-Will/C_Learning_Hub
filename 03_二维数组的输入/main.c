#include <stdio.h>

int main(void) {
    int arr[2][3];

    printf("请输入 2x3 共 6 个整数：\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf_s("%d", &arr[i][j]);
        }
    }

    printf("你输入的矩阵是：\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}