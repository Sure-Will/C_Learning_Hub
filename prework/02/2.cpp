#include <stdio.h>


int main()
{
	char ch;//定义一个字符变量ch，用来存储字母

	printf("请输入一个小写字母: "); 

	scanf_s("%c", &ch, 1);//从键盘读取一个字符存入ch，1表示只读取1个字符

	ch = ch - 32;//将小写字母转换为大写字母（ASCII码相差32）

	printf("转化后的大写字母是：%c\n", ch);//输出转换后的大写字母

	return 0;


}