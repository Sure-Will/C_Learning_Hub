#include <stdio.h>

int main(void)
{
    char str[201];          // 用来保存用户输入的一行字符串（最多 200 个字符）
    int letter = 0;         // 用来统计英文字母个数
    int space = 0;          // 用来统计空格个数
    int digit = 0;          // 用来统计数字个数
    int other = 0;          // 用来统计其他字符个数
    int i;                  // 循环变量

    printf("请输入一行字符串：");
    gets_s(str, 201);       // 读取一整行（VS 下用 gets_s 更安全）

    for (i = 0; str[i] != '\0'; i++) // 从第 0 个字符扫到字符串结束
    {
        char ch = str[i];   // 取出当前字符方便判断

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) // 判断是否英文字母
            letter++;
        else if (ch == ' ') // 判断是否空格
            space++;
        else if (ch >= '0' && ch <= '9') // 判断是否数字
            digit++;
        else
            other++;        // 其他所有字符都归为 other
    }

    printf("英文字母个数：%d\n", letter);
    printf("空格个数：%d\n", space);
    printf("数字个数：%d\n", digit);
    printf("其他字符个数：%d\n", other);

    return 0;
}
