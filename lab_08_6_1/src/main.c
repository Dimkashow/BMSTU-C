#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "cdio_arr.h"
#include "mem_oper.h"
#include "u_find.h"

#define OK 0
#define ERR_INPUT 1
#define ERR_NEG 2
#define ERR_MEM 3
#define ERR_CREAT 1
#define MEM_ADD 3
#define ERR_POS 4

int main()
{
    double *arr = NULL;
    int n = 0;
    int p = 0;
    double u1 = 0;
    double u2 = 0;

    int err = creat_arr(&arr, &n);
    if (err)
    {
        puts("Create array error");
        free(arr);
        return ERR_CREAT;
    }

    u1_find(arr, n, &u1);
    delete_from_arr(arr, &n, u1);
    err = change_mem(&arr, &n);
    if (err)
    {
        puts("Change mem error");
        free(arr);
        return ERR_MEM;
    }

    u2_find(arr, n - MEM_ADD, &u2);
    if (scanf("%d", &p) != 1)
    {
        puts("Input error");
        free(arr);
        return ERR_INPUT;
    }
    if (p >= (n - MEM_ADD) || p < 0)
    {
        puts("P position error");
        free(arr);
        return ERR_POS;
    }

    add_to_arr(arr, n, p, u2);
    print_arr(arr, n);
    free(arr);

    return OK;
}
