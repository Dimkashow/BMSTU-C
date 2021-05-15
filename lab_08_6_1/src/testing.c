#include "testing.h"

void u1_find(double *arr, int n, double *u1)
{
    for (int i = 0; i < n; i++)
        *u1 += *(arr + i);
    (*u1) /= n;
}

void u2_find(double *arr, int n, double *u2)
{
    double max = *(arr);
    for (int i = 0; i < n; i++)
        if (max < *(arr + i))
            max = *(arr + i);
    *u2 = max;
}

void arr_del(double *arr, int *n, int pos)
{
    if (pos != -1)
    {
        for (int i = pos; i < *n - 1; i++)
            *(arr + i) = *(arr + i + 1);
        (*n)--;
    }
}

void add_by_pos(double *arr, int n, int pos, double u2)
{
    for (int i = n - 1; i > pos; i--)
        *(arr + i) = *(arr + i - 1);
    *(arr + pos) = u2;
}