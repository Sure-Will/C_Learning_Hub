#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
编写一个程序实现以下需求：

用户键盘录入一整行字符数据，包含数字和字母。

当用户按下回车键后结束数据录入。

请统计用户输入的一整行字符数据中，数字和字母分别有多少个。

*/

int main(void)
{
	char line[1024]; //保存用户输入的一整行
	int i = 0; //用来遍历字符串下标
	int digitCount = 0; //数字个数
	int letterCount = 0; //字母个数

	printf("请输入一整行字符(包含数字和字母)：");

	if (fgets(line, sizeof(line), stdin) == NULL) //尝试读取一整行输入，如果读取失败，就提示错误并结束程序。
	{
		printf("读取失败！\n");
		return 1;
	}

	while (line[i] != '0' && line[i] != '\n') //只要当前字符不是字符串结束符 \0，并且也不是换行符 \n，就继续循环处理这个字符。
	{
		if (line[i] >= '0' && line[i] <= '9') //满足当前字符在0到9之间的条件的话，数字计数器+1
		{
			digitCount++;
		}
		else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) //如果前面的if不成立，来判断是否为字母，如果是，字母计数器+1
		{
			letterCount++;
		}
		
		i++; // 指针往后移动，检查下一个字符
	}

	printf("数字个数：%d\n", digitCount);
	printf("字母个数：%d\n", letterCount);

	return 0;
}