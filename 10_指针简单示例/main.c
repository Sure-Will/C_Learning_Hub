#include <stdio.h>

int main(void) {
    int a = 0;
    int* p1 = &a;// 让指针指向 a
    
       

    *p1 = 10;       // 通过指针修改 a
    printf("*p1: %d\n", *p1);

    return 0;
}