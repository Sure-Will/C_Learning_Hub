#include <stdio.h>

/*
    功能：修改调用者中的指针 p 的指向
    参数：px 是“指向 int* 的指针”（即二级指针）
*/
void modify_pointer(int **px)
{
    // 基本的空指针检查，避免解引用空指针
    if (px == NULL) {
        return;
    }

    // 静态变量在全局静态区，地址稳定，函数结束后仍有效
    static int static_num = 4399;

    // *px 是调用者的指针 p
    // 让 p 指向 static_num
    *px = &static_num;

    // **px 等价于 *p，打印新的指向的值
    printf("modify_pointer 内部：**px = %d\n", **px);
}

/*
    测试函数：创建局部变量 num 和指针 p，并尝试修改 p 的
指向
*/
void test2(void)
{
    int num = 666;      // 局部变量
    int *p = &num;      // p 指向 num

    printf("调用前：*p = %d\n", *p);

    // 传入 p 的地址，这样 modify_pointer 才能改 p 本身
    modify_pointer(&p);

    // 调用后，p 已经指向 static_num
    printf("调用后：*p = %d\n", *p);
}

int main(void)
{
    test2();
    return 0;
}
