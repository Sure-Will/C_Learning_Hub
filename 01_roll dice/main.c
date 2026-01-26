#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* 掷两枚骰子，返回点数和 */
static int roll_dice_sum(void)
{
    int d1 = rand() % 6 + 1;
    int d2 = rand() % 6 + 1;
    return d1 + d2;
}

/* 清空本行剩余输入，避免 "yyy" 残留影响下一次读取 */
static void clear_line(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* 丢弃 */
    }
}

/* 读取是否继续：返回 1 继续，0 结束 */
static int read_play_again(void)
{
    char ch = '\0';

    printf("\nPlay again?(y/Y means continue) ");
    if (scanf_s(" %c", &ch, 1) != 1) {
        clear_line();
        return 0;
    }
    clear_line(); /* 处理 "yyy" 等多余输入 */

    return (ch == 'y' || ch == 'Y');
}

/* 进行一局游戏：返回 1 表示胜利，0 表示失败 */
static int play_one_game(void)
{
    int sum = roll_dice_sum();
    printf("You rolled: %d\n", sum);

    if (sum == 7 || sum == 11) {
        printf("You win!\n");
        return 1;
    }
    if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lose!\n");
        return 0;
    }

    int point = sum;
    printf("Your point is %d\n", point);

    for (;;) {
        sum = roll_dice_sum();
        printf("You rolled: %d\n", sum);

        if (sum == point) {
            printf("You win!\n");
            return 1;
        }
        if (sum == 7) {
            printf("You lose!\n");
            return 0;
        }
        /* 其他点数继续掷 */
    }
}

int main(void)
{
    srand((unsigned int)time(NULL)); 
    /* 只在程序开始设置一次随机种子 */

    int wins = 0;
    int losses = 0;

    do {
        int win = play_one_game();
        if (win) {
            ++wins;
        }
        else {
            ++losses;
        }
    } while (read_play_again());

    printf("\nWins: %d Losses: %d\n", wins, losses);
    return 0;
}
