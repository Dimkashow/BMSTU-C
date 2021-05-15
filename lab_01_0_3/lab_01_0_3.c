#include <stdio.h>

#define VALUE_FOR_FORMULA 240
#define FROM_M_TO_CM  100

int main()
{
    float height, radius, weight, mass, weight_res;

    puts("Введите рост(в см), длинну окружности грудной клетки (в см) и вес:");
    scanf("%f %f %f", &height, &radius, &weight);

    weight_res = height * radius / VALUE_FOR_FORMULA;
    height /= FROM_M_TO_CM;
    mass = weight / (height * height);

    printf("\nНормальный вес равен: %.4f кг.\n\
Индекс массы тела равна: %.4f", weight_res, mass);
    
    return 0;
}

