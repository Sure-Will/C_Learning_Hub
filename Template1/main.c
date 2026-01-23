//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
//
//int main(void) {
//    int arr[5] = {0};
//
//    for (int i = 0; i < ARR_SIZE(arr); ++i) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

#include <stdio.h>

int main(void) {
    const int a = 10;
    //a = 20; // 错误：不能修改 const 变量
        printf("%d\n", a);
    return 0;
}