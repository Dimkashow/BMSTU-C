#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

int article_comparator(const void *element1, const void *element2)
{
    return strcmp(((product *)element1)->article, ((product *)element2)->article);
}

int name_comparator(const void *element1, const void *element2)
{
    return strcmp(((product *)element1)->name, ((product *)element2)->name);
}

int count_comparator(const void *element1, const void *element2)
{
    return ((product *)element1)->count - ((product *)element2)->count;
}

void sort_products(product_list *const products, const char *const key)
{
    if (!strcmp(key, "ARTICLE"))
        qsort(products->products, products->size, sizeof(product), article_comparator);
    else if (!strcmp(key, "NAME"))
        qsort(products->products, products->size, sizeof(product), name_comparator);
    else
        qsort(products->products, products->size, sizeof(product), count_comparator);
}