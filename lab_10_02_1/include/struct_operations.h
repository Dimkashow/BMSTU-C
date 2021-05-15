#ifndef IU7_CPROG_LABS_2019_DMITRYKOVALEV_STRUCT_OPERATIONS_H
#define IU7_CPROG_LABS_2019_DMITRYKOVALEV_STRUCT_OPERATIONS_H

int check_article(const char *str);

int join_name_to_article(product_list *list);

int read_list(product_list *list, FILE *f);

void delete_el_by_param(product_list *list);

void print_to_file(product_list products, FILE *f);

#endif //IU7_CPROG_LABS_2019_DMITRYKOVALEV_STRUCT_OPERATIONS_H
