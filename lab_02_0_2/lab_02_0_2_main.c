#include <stdio.h>

#define SCAN_ER 1
#define TRIANGLE_NOT_EXIST 2
#define OBTUSE 2
#define ACUTE 0
#define STRAIGHT 1
#define VALUE_NUMBER 6

int result(int res)
{
    if (res == 0)
        return STRAIGHT;
    else if (res < 0)
        return ACUTE;
    else
        return OBTUSE;
}

float prod_scalar(float a, float b, float c, float d)
{
    return a * b + c * d;
}

float sub_cord(float cord_1, float cord_2)
{
    return cord_1 - cord_2;
}

float innerproduct(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float scalar_1 = prod_scalar(sub_cord(x2, x1), sub_cord(x3, x2),
        sub_cord(y2, y1), sub_cord(y3, y2));
        
    float scalar_2 = prod_scalar(sub_cord(x2, x1), sub_cord(x1, x3),
        sub_cord(y2, y1), sub_cord(y1, y3));
        
    float scalar_3 = prod_scalar(sub_cord(x3, x2), sub_cord(x1, x3),
        sub_cord(y3, y2), sub_cord(y1, y3));

    float innerproduct = scalar_1 * scalar_2 * scalar_3;
    
    return innerproduct;
}

int check_triangel(float x1, float y1, float x2, float y2)
{
    return (x1 * y2 - x2 * y1 == 0) ? SCAN_ER : 0;
}

int main()
{
    int check_count;

    float x1 = 0, y1 = 0;
    float x2 = 0, y2 = 0;
    float x3 = 0, y3 = 0;
    float triangle_type = 0;

    puts("Введите координаты треугольника ");
    check_count = scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3); 

    if (check_count != VALUE_NUMBER)
        return SCAN_ER;
    
    if (check_triangel(x2 - x1, y2 - y1, x3 - x1, y3 - y1) == 1)
        return TRIANGLE_NOT_EXIST;

    triangle_type = innerproduct(x1, y1, x2, y2, x3, y3);

    printf("Тип треугольника: %d", result(triangle_type));

    return 0;
}

