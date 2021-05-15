#include <stdio.h>

#define START_VALUE 20
#define VAL_FOR_FORMULA 25

int main()
{
    int money, res;

    puts("Введите кол-во имеющихся денег:");
    scanf("%d", &money);

    res = (money - START_VALUE) / VAL_FOR_FORMULA;

    printf("Можно купить %d шт.", res);
    
    return 0;
}
