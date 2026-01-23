#include <stdio.h>

int main(void) {
    int x = 10;
    int* a, b[3], c;

    a = &x;
    b[0] = 1; b[1] = 2; b[2] = 3;
    c = 99;

    printf("*a = %d\n", *a);
    printf("b[1] = %d\n", b[1]);
    printf("c = %d\n", c);
    return 0;
}
#include <stdio.h>

int main(void) {

    int* p1 = &a;// 让指针指向 a
    int a = 0;
       

    *p1 = 10;       // 通过指针修改 a
    printf("*p1: %d\n", *p1);

    return 0;
}