#include <stdio.h>

void counter(void) {
    static int x = 0;   // 静态局部变量
    x++;
    printf("x = %d\n", x);
}

int main(void) {
    counter();  // x = 1
    counter();  // x = 2
    counter();  // x = 3
    return 0;
}