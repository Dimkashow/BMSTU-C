#ifndef IU7_CPROG_LABS_2019_DMITRYKOVALEV_SORTING_H
#define IU7_CPROG_LABS_2019_DMITRYKOVALEV_SORTING_H

int article_comparator(const void *element1, const void *element2);

int name_comparator(const void *element1, const void *element2);

int count_comparator(const void *element1, const void *element2);

void sort_products(product_list *const products, const char *const key);

#endif //IU7_CPROG_LABS_2019_DMITRYKOVALEV_SORTING_H
