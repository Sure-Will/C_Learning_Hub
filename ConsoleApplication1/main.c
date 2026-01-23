#include <stdio.h>

int main(void)
{
    int n;          // 用来保存用户输入的整数
    char ch;        // 用来保存接下来读到的字符

    printf("请输入一个整数：");
    scanf_s("%d", &n); // 只读取整数，回车产生的 '\\n' 还留在缓冲区里

    printf("你刚才输入的整数是：%d\n", n);

    printf("请再输入一个字符：");
    ch = getchar();  // 这里会先读到上一次输入留下的 '\\n'
    printf("getchar() 读到的字符 ASCII=%d\n", (int)ch);

    if (ch == '\n')
        printf("说明：你并没有来得及输入字符，它读到的是残留的换行符 '\\n'\n");
    else
        printf("你输入的字符是：'%c'\n", ch);

    return 0;
}
