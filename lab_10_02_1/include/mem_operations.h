#ifndef IU7_CPROG_LABS_2019_DMITRYKOVALEV_MEM_OPERATIONS_H
#define IU7_CPROG_LABS_2019_DMITRYKOVALEV_MEM_OPERATIONS_H

#define START_MEM 100

int init_struct(product_list *list);

int realloc_list(product_list *list);

void free_products(product_list *products);

#endif //IU7_CPROG_LABS_2019_DMITRYKOVALEV_MEM_OPERATIONS_H
