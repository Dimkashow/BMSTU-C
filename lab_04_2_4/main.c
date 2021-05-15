#include <stdio.h>

#define OK 0
#define ERROR_INPUT 1
#define CORRECT_ELEM 1
#define MAX_SIZE 10
#define MIN_SIZE 1
#define EMPTY_ARR 0
#define NO_ELEM 2

void insertion_sort(int mass[], const int n)
{
    int new, loc;

    for (int i = 1; i < n; i++)
    {
        new = mass[i];
        loc = i - 1;
        while (loc >= 0 && mass[loc] > new)
        {
            mass[loc + 1] = mass[loc];
            loc = loc - 1;
        }
        mass[loc + 1] = new;
    }
}

void print_arr(int arr[], const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
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

    int arr[MAX_SIZE] = { 0 };

    puts("Enter arr size: ");
    int check_input = scanf("%d", &arr_size);
    if (check_input != CORRECT_ELEM || arr_size > MAX_SIZE || arr_size < MIN_SIZE)
        return ERROR_INPUT;

    check_input = arr_input(arr, arr_size);
    if (check_input)
        return ERROR_INPUT;

    if (arr_size == EMPTY_ARR)
        return NO_ELEM;

    insertion_sort(arr, arr_size);
    print_arr(arr, arr_size);

    return OK;
} 
