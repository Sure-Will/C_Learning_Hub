#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n; // 用户要发的手牌数量

    // 4种花色：C(梅花), D(方块), H(红心), S(黑桃)
    char suits[] = { 'C', 'D', 'H', 'S' };

    // 13种点数：2~10, J, Q, K, A
    // 用字符串数组更好打印（"10"是两位）
    const char* points[] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

    int deck[52]; // 用来存放52张牌的“编号”
    int i;

    // 1) 初始化牌堆：0~51
    for (i = 0; i < 52; i++) {
        deck[i] = i; // 第 i 个位置先放编号 i
    }

    // 2) 让随机数每次运行都不一样
    srand((unsigned int)time(NULL));

    // 3) 洗牌：Fisher-Yates 洗牌法（新手也好理解）
    for (i = 51; i > 0; i--) {
        int j = rand() % (i + 1); // 在 0~i 之间随机选一个位置
        int temp = deck[i];       // 交换 deck[i] 和 deck[j]
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // 4) 输入要发几张牌
    printf("请输入您需要的手牌数量：");
#ifdef _MSC_VER
    scanf_s("%d", &n); // VS里更“规矩”的写法
#else
    scanf("%d", &n);
#endif

    // 5) 合法性检查
    if (n < 1 || n > 52) {
        printf("输入不合法！手牌数量必须在 1~52 之间。\n");
        return 0;
    }

    // 6) 模拟“发牌中....”
    printf("发牌中....\n");
    printf("发牌中....\n");
    printf("发牌中....\n");

    // 7) 输出手牌
    printf("您的手牌是：\n");

    for (i = 0; i < n; i++) {
        int card = deck[i];          // 取第 i 张牌的编号
        int suitIndex = card / 13;   // 0~3 对应花色
        int pointIndex = card % 13;  // 0~12 对应点数

        // 打印格式：花色字母 + 点数，比如 D9、SJ、C10
        printf("%c%s", suits[suitIndex], points[pointIndex]);

        if (i != n - 1) {
            printf("\t"); // 用 Tab 分隔更像示例
        }
    }

    printf("\n");
    return 0;
}
