#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "sorting.h"
#include "mem_operations.h"
#include "struct_operations.h"

#define MAX_LEN_KEY 8
#define MEM_ER 1
#define READ_ER 2

int main()
{
    product_list list;
    if (init_struct(&list))
    {
        free_products(&list);
        return MEM_ER;
    }

    if (read_list(&list, stdin))
    {
        free_products(&list);
        return READ_ER;
    }

    char sort_key[MAX_LEN_KEY];
    if (fscanf(stdin, "%s", sort_key) != 1)
    {
        free_products(&list);
        return READ_ER;
    }

    if (strcmp(sort_key, "ARTICLE") && strcmp(sort_key, "NAME") && strcmp(sort_key, "COUNT"))
    {
        free_products(&list);
        return READ_ER;
    }

    join_name_to_article(&list);

    delete_el_by_param(&list);

    if (list.size <= 1)
    {
        free_products(&list);
        return MEM_ER;
    }
    sort_products(&list, sort_key);

    FILE *f = NULL;
    if ((f = fopen("stockpile.txt", "w+")) == NULL)
    {
        free_products(&list);
        return MEM_ER;
    }

    print_to_file(list, f);

    free_products(&list);
    fclose(f);

    return 0;
}