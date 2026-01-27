#include <stdio.h>

int main()
{
	int num; //定义变量num，用来存储当前检查的三位数
	int ge, shi, bai; //定义三个变量，分别存储个位、十位、百位数字
	int sum; //定义变量sum，用来存储各位数字的立方和

	printf("100到999之间的水仙花数有：\n");

	for (num = 100; num <= 999; num++) //从100到999依次检查每一个三位数
	{
		bai = num / 100; //提取百位数字（用整除运算）
		shi = num / 10 % 10; //提取十位数字（先除以10再取余）
		ge = num % 10; //提取个位数字（直接模10）
	

	sum = bai * bai * bai + shi * shi * shi + ge * ge * ge; //计算百位、十位、个位的立方之和

	if (sum == num) //判断立方和是否等于原数
	{
		printf("%d\n", num); //如果相等，说明是水仙花数，输出这个数
	}
	}

	return 0;

}