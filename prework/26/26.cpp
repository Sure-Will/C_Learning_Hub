#include <stdio.h>

// 函数：计算第 n 项的值
double getItem(int n) {
    return 1.0 / (2 * n);  // 第n项 = 1/(2n)，用1.0确保是小数除法
}

// 函数：计算前 n 项的和
double getSum(int n) {
    double sum = 0;  // 用来累加的变量
    int i;

    for (i = 1; i <= n; i++) {
        sum = sum + getItem(i);  // 调用 getItem 函数获取第i项，加到sum里
    }

    return sum;  // 返回总和
}

int main() {
    int n = 20;  // 要求前20项的和
    double result;

    result = getSum(n);  // 调用函数计算前20项的和

    printf("数列 1/2 + 1/4 + 1/6 + ... 前 %d 项的和为：%f\n", n, result);

    return 0;
}
