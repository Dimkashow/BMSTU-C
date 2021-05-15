#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"

#define START_MEM 100
#define MEM_ER 1

int init_struct(product_list *list)
{
    list->products = malloc(sizeof(product) * START_MEM);
    if (!list->products)
        return MEM_ER;

    list->aloc_memory = START_MEM;
    list->size = 0;

    for (int i = 0; i < START_MEM; i++)
    {
        list->products[i].article = NULL;
        list->products[i].name = NULL;
        list->products[i].count = 0;
    }
    return 0;
}

int realloc_list(product_list *list)
{
    list->products = realloc(list->products, list->size + START_MEM);
    if (!list->products)
        return MEM_ER;
    list->aloc_memory += START_MEM;
    return 0;
}


void free_products(product_list *products)
{
    for (int i = 0; i < products->size; i++)
    {
        if (products->products[i].name)
            free(products->products[i].name);

        if (products->products[i].article)
            free(products->products[i].article);
    }
    free(products->products);
}
