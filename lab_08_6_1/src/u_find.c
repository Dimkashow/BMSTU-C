#include "u_find.h"

void u1_find(double *const arr, const int n, double *const u1)
{
    for (int i = 0; i < n; i++)
        *u1 += *(arr + i);
    (*u1) /= n;
}

void u2_find(double *const arr, const int n, double *const u2)
{
    double max = *(arr);
    for (int i = 0; i < n; i++)
        if (max < *(arr + i))
            max = *(arr + i);
    *u2 = max;
}
