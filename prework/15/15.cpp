#include <stdio.h>

int checkLetter(char ch) // 判断 ch 属于哪一类：1大写 2小写 0不是字母
{
    if (ch >= 'A' && ch <= 'Z') return 1; // ch 在 'A'~'Z' 之间说明是大写字母
    if (ch >= 'a' && ch <= 'z') return 2; // ch 在 'a'~'z' 之间说明是小写字母
    return 0;                             // 其他情况都不是 26 个英文字母
}

int main(void)
{
    char ch; // 用来保存用户输入的字符
    int result; // 用来保存函数返回的判断结果

    printf("请输入一个字符：");
    scanf_s(" %c", &ch, 1); // 读取一个字符（前面的空格用于跳过回车/空格）

    result = checkLetter(ch); // 调用函数判断字符类型

    if (result == 1)
        printf("你输入的是大写字母。\n");
    else if (result == 2)
        printf("你输入的是小写字母。\n");
    else
        printf("你输入的不是英文字母。\n");

    return 0;
}
