#include <stdio.h>
#include <math.h>

#define QUANITY_VAL 2
#define SCAN_ERROR 1
#define SUCC 0

float sum_of_series(float x, float epsilon)
{
    float value_of_series = 1;
    float result_sum = 1;
    int devider = 1;
    
    while (fabs(value_of_series) > epsilon)
    {
        value_of_series = value_of_series * x / devider;
        result_sum += value_of_series;
        devider++;
    }
    
    return result_sum;
}

int check_input(int res, float eps)
{
    if (res != QUANITY_VAL || eps <= 0 || eps > 1)
        return SCAN_ERROR;
    return SUCC;
}

int main()
{
    float x, eps;
    
    printf("Введите X и epsilon:\n");
    int res = scanf("%f %f", &x, &eps);
    
    int false_input = check_input(res, eps);
    if (false_input)
        return SCAN_ERROR;
    
    float close_value = sum_of_series(x, eps);
    float absolute_value = expf(x);
    
    printf("Приблизительное значение e^x: %f\n", close_value);
    printf("Точное значение e^x: %f\n", absolute_value);
    printf("Абсолютная ошибка: %f\n", fabs(absolute_value - close_value));
    printf("Приблеженная ошибка: %f\n", fabs((absolute_value - close_value) / absolute_value));

    return SUCC;
}
