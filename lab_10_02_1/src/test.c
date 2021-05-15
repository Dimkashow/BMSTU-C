#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "mem_operations.h"
#include "struct_operations.h"

int testing_check_article()
{
    int res = 0;
    res += !(check_article("LOL"));
    res += !(check_article("SUPER"));
    res += (check_article("TeSt"));
    res += (check_article("111St"));
    res += (check_article("ST111ST"));

    return (res > 1);
}

int test_list(product_list *list, char *path)
{
    if (init_struct(list))
    {
        free_products(list);
        return 1;
    }
    FILE *f = fopen(path, "r");
    if (!f)
    {
        free_products(list);
        return 1;
    }

    if (read_list(list, f))
    {
        free_products(list);
        return 1;
    }
    fclose(f);
    return 0;
}

int compare_list(product_list *list_a, product_list *list_b)
{
    for (int i = 0; i < list_a->size; i++)
    {
        if (strcmp(list_a->products[i].name, list_b->products[i].name))
            return 1;
        if (list_a->products[i].count != list_b->products[i].count)
            return 1;
        if (strcmp(list_a->products[i].article, list_b->products[i].article))
            return 1;
    }
    return 0;
}

int testing_join_name_to_article(product_list *list)
{
    join_name_to_article(list);
    product_list list_to_compare;
    test_list(&list_to_compare, "test/2testdata.txt");

    int res = compare_list(list, &list_to_compare);
    free_products(&list_to_compare);
    return res;
}

int testing_delete_el_by_param(product_list *list)
{
    delete_el_by_param(list);
    product_list list_to_compare;
    test_list(&list_to_compare, "test/3testdata.txt");

    int res = compare_list(list, &list_to_compare);
    free_products(&list_to_compare);
    return res;
}

int main()
{
    product_list list;
    test_list(&list, "test/1testdata.txt");

    int res = 0;

    res += testing_check_article();
    res += testing_join_name_to_article(&list);
    res += testing_delete_el_by_param(&list);

    free_products(&list);
    return res;
}