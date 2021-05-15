#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "cdio_arr.h"

#define OK 0
#define ERR_INPUT 1
#define ERR_NEG 2
#define ERR_MEM 3

void arr_del(double *const arr, int *n, const int pos)
{
    if (pos != -1)
    {
        for (int i = pos; i < *n - 1; i++)
            *(arr + i) = *(arr + i + 1);
        (*n)--;
    }
}

int creat_arr(double **const arr, int *const n)
{
    puts("Enter array size");
    int input_err = scanf("%d", n);
    if (input_err != 1)
        return ERR_INPUT;
    if (*n < 0)
        return ERR_NEG;
    *arr = calloc(*n, sizeof(double));
    if (!*arr)
        return ERR_MEM;

    puts("Enter arr");
    for (int i = 0; i < *n; i++)
        if (scanf("%lf", (*arr + i)) != 1)
            return ERR_INPUT;

    return OK;
}

void add_by_pos(double *const arr, const int n, const int pos, const double u2)
{
    for (int i = n - 1; i > pos; i--)
        *(arr + i) = *(arr + i - 1);
    *(arr + pos) = u2;
}

void add_to_arr(double *const arr, const int n, const int pos, const double u2)
{
    add_by_pos(arr, n, pos, u2);
    add_by_pos(arr, n, 0, u2);
    *(arr + n - 1) = u2;
}

void print_arr(const double *const arr, const int n)
{
    for (int i = 0; i < n; i++)
        printf("%lf ", *(arr + i));
}

void delete_from_arr(double *const arr, int *const n, const double u)
{
    int to_del[2] = { -1, -1 };
    double diff[2] = { -1, -1 };

    for (int i = 0; i < *n; i++)
    {
        double odd = fabs(*(arr + i) - u);
        if (odd > *(diff + 1))
        {
            *(to_del + 1) = i;
            *(diff + 1) = odd;
            if (*(diff + 1) > *(diff))
            {
                double buff = *(diff + 1);
                *(diff + 1) = *(diff);
                *(diff) = buff;

                buff = *(to_del + 1);
                *(to_del + 1) = *(to_del);
                *(to_del) = buff;
            }
        }
    }
    if (*(to_del + 1) > *(to_del) && *(to_del) != -1)
        --*(to_del + 1);
    arr_del(arr, n, *(to_del));
    arr_del(arr, n, *(to_del + 1));
}