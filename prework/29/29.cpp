#include <stdio.h>

// 函数：计算16位整数每4位的和
int sumOf4Bits(int num) {
    int sum = 0;  // 用来累加结果
    int i;

    // 循环4次，每次取出4位
    for (i = 0; i < 4; i++) {
        sum = sum + (num & 0xF);  // num & 0xF 取出最低4位，加到sum里
        num = num >> 4;           // 右移4位，把下一组移到最低位
    }

    return sum;
}

int main() {
    int number;
    int result;

    printf("请输入一个整数：");
    scanf_s("%d", &number);

    result = sumOf4Bits(number);  // 调用函数计算

    printf("每4位的和为：%d\n", result);

    return 0;
}