#include <stdio.h> //包含标准输入输出库，用于printf和scanf

int main() //主函数，程序从这里开始执行
{
	float x, y; //定义两个浮点型变量：x用于存储输入值，y用于存储计算结果

	printf("请输入x的值："); //提示用户输入x

	scanf_s("%f", &x); //从键盘读取一个整数，存入变量x；（%f表示浮点型，&x表示x的内存地址）

	////根据x的值进行分段计算y的值
	if (x < 5) //如果x小于5
	{
		y = x;
	}
	else if (x < 15) //否则如果x小于15
	{
		y = x + 6;
	}
	else //否则（即x大于等于15）
	{
		y = x - 6;
	}

	printf("对应的y值为:%f\n", y);//输出计算结果y的值，%f表示以浮点型格式输出

	return 0;

}