#include <stdio.h>
#include <math.h>

#define HALF 0.5
#define DOUBLING 2

int main()
{
    float height, side1, side2, side3;
    float half_diff;
    float perimeter;

    puts("Введите основания и высоту равнобедренной трапеции: ");
    scanf("%f %f %f", &side1, &side2, &height);
    if (side1 < side2) 
    {
        half_diff = (side2 - side1) * HALF;
    }
    else 
    {
        half_diff = (side1 - side2) * HALF;
    }

    side3 = sqrt(half_diff * half_diff + height * height);
    perimeter = side3 * DOUBLING + side1 + side2;

    printf("\nПериметр равен: %.5f", perimeter);

    return 0;
}
