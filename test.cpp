#include <stdio.h>
#include <string.h>
#include <math.h>
double M[15][35];
int E[15][35];

void init()
{
    int i, j;
    for (i = 0; i <= 9; ++i)
    {
        for (j = 1; j <= 30; ++j)
        {
            long long e = pow(2, j) - 1; // 阶码
            double m = 1 - pow(2, -(i+1)); // 尾数
            double t = log10(m) + e * log10(2);
            E[i][j] = t;
            M[i][j] = pow(10, t - E[i][j]);
        }
    }
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    init();
    char str[25];
    while (1 == scanf("%s", str))
    {
        if (0 == strcmp(str, "0e0"))
            return 0;
        str[17] = ' '; // str[17]是字符e
        double a; int b;
        sscanf(str, "%lf %d", &a, &b); // 从字符串输入
        int i, j, flag = 0;
        for (i = 0; i <= 9; ++i) // 查表
        {
            for (j = 1; j <= 30; ++j)
            {
                if (b == E[i][j] && fabs(a - M[i][j]) < 1e-4) // 注意判断double是否相等时的精度问题
                {
                    printf("%d %d\n", i, j);
                    flag = 1;
                }
            if (flag) break;
            }
        }
    }
    return 0;
}