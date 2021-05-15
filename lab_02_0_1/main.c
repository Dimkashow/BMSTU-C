#include <stdio.h>

#define SCAN_ER 1
#define QUANITY_VAL 2
#define NORMAL 0

int custom_power(int t, int k)
{
    int res = 1;
    int n = k;
    while (k) 
    {
        if (k & 1) 
            res *= t;
        t *= t;
	    k >>= 1;
    }
    if (n < 0 && res != 0)
        res = 1 / res;

    return res;
}

int main()
{
    int a, n;
    int res;
    
    printf("Введите основание и показатель степени (через пробел)\n");
    res = scanf("%d %d", &a, &n);

    if (res == QUANITY_VAL && n > 0)
    {
        printf("Результат: %d", custom_power(a, n));
    }
    else
    {
        return SCAN_ER;
    }

    return NORMAL;
}
