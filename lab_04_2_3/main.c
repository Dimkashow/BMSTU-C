#include <stdio.h>

#define OK 0
#define ERROR_INPUT 1
#define CORRECT_ELEM 1
#define MAX_SIZE 10
#define MIN_SIZE 1
#define NEED_DEL 1
#define NO 0
#define EMPTY_ARR 0
#define NO_ELEM 2

const int check_number(int n)
{
    int sqr = 0;
    int j = 0;
    while (sqr < n)
    {
        j++;
        sqr = j * j;
    }
    if (sqr == n)
        return NEED_DEL;
    return NO;
}

void print_arr(int arr[], const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void find_result(int arr[], int *const size)
{
    for (int i = 0; i < *size; i++)
    {
        if (check_number(arr[i]))
        {
            for (int j = i; j < *size; j++)
                arr[j] = arr[j + 1];
            *size -= 1;
            i--;
        }
    }
}

const int arr_input(int arr[], int *const size)
{
    int new_el = 0;
    puts("Enter arr: ");
    for (int i = 0; i < *size; i++)
        new_el += scanf("%d", &arr[i]);

    if (new_el != *size)
        return ERROR_INPUT;
    return OK;
}

int main()
{
    int arr_size = 0;
    //int *const pointer_arr_size = &arr_size;

    int arr[MAX_SIZE] = { 0 };

    puts("Enter arr size: ");
    int check_input = scanf("%d", &arr_size);
    if (check_input != CORRECT_ELEM || arr_size > MAX_SIZE || arr_size < MIN_SIZE)
        return ERROR_INPUT;

    check_input = arr_input(arr, &arr_size);
    if (check_input)
        return ERROR_INPUT;

    find_result(arr, &arr_size);

    if (arr_size == EMPTY_ARR)
        return NO_ELEM;

    print_arr(arr, arr_size);

    return OK;
}
