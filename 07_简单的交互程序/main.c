#include <stdio.h>

int main(void)
{
    double balance = 0.0;   // 账户余额（局部变量）
    int choice = -1;        // 菜单选择
    int ch = 0;             // 用于清理输入缓冲区

    while (1) {
        // 1) 显示菜单
        puts("======= 记账程序菜单 =======");
        puts("0. 清空账户余额");
        puts("1. 往账户上存钱");
        puts("2. 从账户上取钱");
        puts("3. 显示当前余额");
        puts("4. 退出程序");

        // 2) 读取选择（防御性：检查 scanf_s 返回值）
        printf("请选择操作（0-4）：");
        if (scanf_s("%d", &choice) != 1) {
            puts("输入无效：请输入整数 0~4。");

            // 清理这一行的垃圾输入，避免死循环
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue; // 回到菜单重来
        }

        // 可选：把本行多余字符清掉（比如用户输入 "1abc"）
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        // 3) switch 分发
        switch (choice) {
        case 0:
            balance = 0.0;
            printf("已清空余额，当前余额：%.2f 元。\n\n", balance);
            break;

        case 1: {
            double amount = 0.0;
            while (1) {
                printf("请输入存款金额：");
                if (scanf_s("%lf", &amount) != 1) {
                    puts("输入无效：请输入数字金额（例如 100 或 99.5）。");
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    continue;
                }
                while ((ch = getchar()) != '\n' && ch != EOF) {}

                if (amount <= 0.0) {
                    puts("存款金额必须大于 0。");
                    continue;
                }

                balance += amount;
                printf("成功存款 %.2f 元。\n\n", amount);
                break;
            }
            break;
        }

        case 2: {
            double amount = 0.0;
            while (1) {
                printf("请输入取款金额：");
                if (scanf_s("%lf", &amount) != 1) {
                    puts("输入无效：请输入数字金额（例如 50 或 20.5）。");
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    continue;
                }
                while ((ch = getchar()) != '\n' && ch != EOF) {}

                if (amount <= 0.0) {
                    puts("取款金额必须大于 0。");
                    continue;
                }
                if (amount > balance) {
                    printf("余额不足！当前余额：%.2f 元。\n", balance);
                    continue;
                }

                balance -= amount;
                printf("成功取款 %.2f 元。\n\n", amount);
                break;
            }
            break;
        }

        case 3:
            printf("当前余额：%.2f 元。\n\n", balance);
            break;

        case 4:
            puts("已退出程序。");
            return 0;

        default:
            puts("无效选择：请输入 0~4。\n");
            break;
        }
    }
}
