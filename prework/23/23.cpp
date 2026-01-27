#include <stdio.h>

int isWordChar(char ch) // 判断 ch 是否属于“单词字符”（字母或数字）
{
    if (ch >= 'A' && ch <= 'Z') return 1; // 大写字母算单词字符
    if (ch >= 'a' && ch <= 'z') return 1; // 小写字母算单词字符
    if (ch >= '0' && ch <= '9') return 1; // 数字也算单词字符
    return 0;                             // 其他（空格、标点）都不算
}

int main(void)
{
    char str[501];          // 用来保存输入的一行文本（最多500字符）
    int count = 0;          // 用来统计单词数量
    int inWord = 0;         // 用来表示当前是否处在一个单词内部
    int i;                  // 循环变量

    printf("请输入一行文本：\n");
    gets_s(str, 501);       // 读取一整行（包含空格）

    for (i = 0; str[i] != '\0'; i++) // 从头扫描到字符串结束
    {
        if (isWordChar(str[i]))      // 当前字符是单词字符
        {
            if (inWord == 0)         // 之前不在单词里，现在进入单词
            {
                count++;             // 发现一个新单词，数量+1
                inWord = 1;          // 标记：现在在单词里
            }
        }
        else                          // 当前字符不是单词字符（空格/标点等）
        {
            inWord = 0;              // 标记：离开单词
        }
    }

    printf("单词数量：%d\n", count);
    return 0;
}
