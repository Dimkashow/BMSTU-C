#ifndef IU7_CPROG_LABS_2019_DMITRYKOVALEV_STRUCT_H
#define IU7_CPROG_LABS_2019_DMITRYKOVALEV_STRUCT_H

typedef struct product
{
    char *article;
    char *name;
    int count;
} product;

typedef struct product_list
{
    product *products;
    int size;
    int aloc_memory;
} product_list;

#endif //IU7_CPROG_LABS_2019_DMITRYKOVALEV_STRUCT_H
