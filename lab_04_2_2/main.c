#include <stdio.h>

#define OK 0
#define ERROR_INPUT 1
#define CORRECT_ELEM 1
#define MAX_SIZE 10
#define MIN_SIZE 1
#define NO_NEW_NUMBERS 2
#define NEED_AD 1
#define NO 0

const int check_number(int n)
{
    int last = n % 10;
    int first = 0;

    while (n != 0)
    {
        first = n;
        n /= 10;
    }

    if (last == first)
        return NEED_AD;
    return NO;
}

void print_arr(int arr[], const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void create_mass(int arr[], const int size, int new_arr[], int *const pointer_new_size)
{
    for (int i = 0; i < size; i++)
    {
        if (check_number(arr[i]))
        {
            new_arr[*pointer_new_size] = arr[i];
            *pointer_new_size += 1;
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

    int new_size = 0;
    //int *const pointer_new_size = &new_size;

    int arr[MAX_SIZE] = { 0 };
    int new_arr[MAX_SIZE] = { 0 };

    puts("Enter arr size: ");
    int check_input = scanf("%d", &arr_size);
    if (check_input != CORRECT_ELEM || arr_size > MAX_SIZE || arr_size < MIN_SIZE)
        return ERROR_INPUT;

    check_input = arr_input(arr, arr_size);
    if (check_input)
        return ERROR_INPUT;

    create_mass(arr, arr_size, new_arr, &new_size);

    if (new_size == 0)
        return NO_NEW_NUMBERS;
    
    print_arr(new_arr, new_size);
    
    return OK;
}
