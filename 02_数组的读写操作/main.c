#include <stdio.h>

int main(void) {
    int arr[5];
    int i;

    // 读
    printf("输入 5 个整数：\n");
    for (i = 0; i < 5; i++) {
        scanf_s("%d", &arr[i]);
    }

    // 写（修改）
    arr[2] = 99;

    // 输出
    printf("数组内容：\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}