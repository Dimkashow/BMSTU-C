#include <stdlib.h>

#include "mem_oper.h"

#define OK 0
#define ERR_MEM 3
#define MEM_ADD 3

int change_mem(double **arr, int *n)
{
    double *new_arr = NULL;
    new_arr = realloc(*arr, (*n + MEM_ADD) * sizeof(double));
    if (!new_arr)
        return ERR_MEM;
    *arr = new_arr;
    *(n) += MEM_ADD;
    return OK;
}
