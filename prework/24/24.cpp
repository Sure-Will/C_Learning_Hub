#include <stdio.h>

int pos[8];            // pos[row] 表示第 row 行的皇后放在第几列
int count = 0;         // 用来统计一共有多少种摆法

int absInt(int x)      // 计算整数绝对值（避免引入其他库）
{
    return (x < 0) ? -x : x;
}

int isSafe(int row, int col) // 判断 (row, col) 位置能不能放皇后
{
    int i;
    for (i = 0; i < row; i++) // 只需要检查前面已经放好的 0..row-1 行
    {
        if (pos[i] == col) return 0; // 同一列冲突
        if (absInt(pos[i] - col) == absInt(i - row)) return 0; // 同一斜线冲突
    }
    return 1; // 不冲突就安全
}

void printBoard(void) // 打印当前棋盘
{
    int r, c;
    printf("第 %d 种解：\n", count);

    for (r = 0; r < 8; r++)
    {
        for (c = 0; c < 8; c++)
        {
            if (pos[r] == c) printf("Q "); // 该位置是皇后
            else printf(". ");             // 其他位置用点表示
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int row) // 从第 row 行开始放皇后
{
    int col;

    if (row == 8) // 8 行都放完了，得到一种解
    {
        count++;      // 解的数量 +1
        printBoard(); // 输出这一种解
        return;
    }

    for (col = 0; col < 8; col++) // 尝试把皇后放在当前行的每一列
    {
        if (isSafe(row, col))     // 如果这个位置安全
        {
            pos[row] = col;       // 记录当前行皇后的位置
            dfs(row + 1);         // 继续放下一行
        }
    }
}

int main(void)
{
    printf("开始求 8 皇后问题的所有解...\n\n");
    dfs(0); // 从第 0 行开始放

    printf("总共有 %d 种解。\n", count);
    return 0;
}
