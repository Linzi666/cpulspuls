#define _CRT_SECURE_NO_WARNINGS 1#include <stdio.h>
#include <math.h>
#include <stdio.h>
int main() {
    //1461   是一个 4位数

    //  (1461 / 1000) * (1461 % 1000)
    //  (1461 / 10^(4-1))  *  (1461 % 10^(4-1)) = 1 * 461  第一次

    //   (1461 / 100) * (1461 % 100)
    //  (1461 / 10^(4-2))  *  (1461 % 10^(4-2)) = 14 * 61  第二次

    //  (1461 / 10) * (1461 % 10)
    //  (1461 / 10^(4-3))  *  (1461 % 10^(4-3)) = 146 * 1  第三次

    // 一个需要进行 4-1次， 

    //第一步，算出这个数的位数
    int count = 5; //一个数的位数
    int sum = 0;
    int i = 0;

    for (i = 10000; i < 100000; i++)
    {
        //  两位数，只用相加一次， 三位数，相加 2次， 四位数相加3次
        for (int k = 1; k < count; k++)
        {
            // (n / 10^ (count-k) ) * (n % （10^count-k）)
            sum += (i / (int)pow(10, count - k)) * (i % (int)(pow(10, count - k)));
        }
        if (sum == i)
            printf("%d ", sum);
        sum = 0;
    }

    return 0;
}