#include <stdio.h>

static long long ll_abs(long long x)
{
    return (x < 0) ? -x : x;
}

/* 欧几里得算法：求最大公约数 */
static long long gcd_ll(long long a, long long b)
{
    a = ll_abs(a);
    b = ll_abs(b);

    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return (a == 0) ? 1 : a;  // 避免出现 gcd(0,0) 的麻烦
}

/* 把符号统一到分子上：保证分母为正 */
static void normalize_fraction(long long *num, long long *den)
{
    if (*den < 0) {
        *den = -*den;
        *num = -*num;
    }
}

/* 分数约分成最简 */
static void reduce_fraction(long long *num, long long *den)
{
    normalize_fraction(num, den);

    long long g = gcd_ll(*num, *den);
    *num /= g;
    *den /= g;
}

/* 读取一个分数：形如 a/b，并做输入校验 */
static int read_fraction(const char *prompt, long long *num, long long *den)
{
    while (1) {
        int ch;

        printf("%s", prompt);
        if (scanf_s("%lld/%lld", num, den) != 2) {
            puts("输入格式错误，请按 分子/分母 形式输入，例如 1/4。");

            // 清理这一行残留，避免死循环
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }

        // 清理这一行多余字符（例如用户输入后面还有空格/字符）
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        if (*den == 0) {
            puts("分母不能为 0，请重新输入。");
            continue;
        }

        // 输入通过
        return 1;
    }
}

/* 分数相加：a/b + c/d = (a*d + c*b) / (b*d) */
static void add_fractions(long long a, long long b,
    long long c, long long d,
    long long *out_num, long long *out_den)
{
    *out_num = a * d + c * b;
    *out_den = b * d;

    reduce_fraction(out_num, out_den);
}

int main(void)
{
    long long a, b, c, d;
    long long sum_num, sum_den;

    read_fraction("请输入第一个分数(分子/分母): ", &a, &b);
    read_fraction("请输入第二个分数(分子/分母): ", &c, &d);

    add_fractions(a, b, c, d, &sum_num, &sum_den);

    if (sum_den == 1) {
        printf("两个分数的和是一个整数，即： %lld\n", sum_num);
    }
    else {
        printf("两个分数的和是一个分数，即： %lld/%lld\n", sum_num, sum_den);
    }

    return 0;
}
