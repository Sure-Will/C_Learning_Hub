#include <stdio.h>

int arr[5] = { 1, 2, 3, 4, 5 };

int* get_value(int idx) {
    if (idx < 0 || idx >= 5) {
        return NULL; // 越界返回空指针
    }
    printf("arr[%d]: %d\n", idx, arr[idx]);
    printf("&arr[%d]: %p\n", idx, (void*)&arr[idx]);
    return &arr[idx];
}

int main(void) {
    int* p = get_value(0);
    if (p != NULL) {
        printf("*p: %d\n", *p);
    }
    return 0;
}
