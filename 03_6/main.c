#include <stdio.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main(void)
{
	int nums[] = { 55, 66, 1, 1, 2, 2, 3, 3, 4, 4 };
	int n = ARR_SIZE(nums);

	int xor = 0;
	for (int i = 0; i < n; i++) {
		xor ^= nums[i];
	}

	int mask = xor & -xor; // 取最低位的 1

	int num1 = 0, num2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] & mask)
		{
			num1 ^= nums[i];
		}
		else
		{
			num2 ^= nums[i];
		}
	}

	printf("num1 = %d, num2 = %d\n", num1, num2); // 输出 55 和 66（顺序可能互换）
	return 0;
}