#include <stdio.h>

int main()
{
	int score; //定义变量score，用来存储百分制成绩
	char grade; //定义字符变量grade，用来存储等级（A、B、C、D、E）

	printf("请输入百分制成绩（0-100）："); //提示用户输入成绩
	scanf_s("%d", &score); //读取用户输入的成绩

	//使用if-else多分支判断成绩属于哪个等级
	if (score >= 90 && score < 100) //如果成绩在90到100之间
	{
		grade = 'A'; //等级为A（优秀）
	}
	else if (score >= 80 && score < 90) //如果成绩在80到89之间
	{
		grade = 'B'; //等级为B（良好）
	}
	else if (score >= 70 && score < 79) //如果成绩在70到79之间
	{
		grade = 'C'; //等级为C（中等）
	}
	else if (score >= 60 && score < 69) //如果成绩在60到69之间
	{
		grade = 'D'; //等级为D（合格）
	}
	else //如果成绩不在60-100范围内
	{
		printf("输入的成绩无效！\n"); //提示成绩无效
		return 1; //程序异常结束
	}

	printf("百分制成绩 %d 对应的五级分制为：%c\n", score, grade);

	return 0;
}