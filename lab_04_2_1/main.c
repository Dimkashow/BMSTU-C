#include <stdio.h>

#define OK 0
#define ERROR_INPUT 1
#define CORRECT_ELEM 1
#define NO_NEG 2
#define MAX_SIZE 10
#define MIN_SIZE 1

void find_neg(int arr[], const int size, int *const count, double *const sum)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            *count += 1;
            *sum += arr[i];
        }
    }
}

const int arr_input(int arr[], const int size)
{
    int new_el = 0;
    puts("Enter arr: ");
    for (int i = 0; i < size; i++)
        new_el += scanf("%d", &arr[i]);
    
    if (new_el != size)
        return ERROR_INPUT;
    return OK;
}

int main() 
{
    int arr_size = 0;

    int count_neg = 0;
    //int *const pointer_count_neg = &count_neg;

    double sum_neg = 0;
    //double *const pointer_sum_neg = &sum_neg;

    int arr[MAX_SIZE] = { 0 };

    puts("Enter arr size: ");
    int check_input = scanf("%d", &arr_size);
    if (check_input != CORRECT_ELEM || arr_size > MAX_SIZE || arr_size < MIN_SIZE)
        return ERROR_INPUT;

    check_input = arr_input(arr, arr_size);
    if (check_input)
        return ERROR_INPUT;

    find_neg(arr, arr_size, &count_neg, &sum_neg);
        
    if (count_neg == 0)
        return NO_NEG;

    const double average_neg = sum_neg / count_neg;

    printf("Average of negative: %lf", average_neg);

    return OK;
}
