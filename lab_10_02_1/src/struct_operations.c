#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "mem_operations.h"

#define MAX_LEN 512
#define DIFF 0
#define SAME 1

#define MEM_ER 1
#define READ_ER 2

int check_article(const char *str)
{
    while (*str)
        if (!isupper(*str++))
            return DIFF;
    return SAME;
}

int join_name_to_article(product_list *list)
{
    for (int i = 0; i < list->size; i++)
    {
        size_t new_size = strlen(list->products[i].article) + strlen(list->products[i].name);
        strcat(list->products[i].article, list->products[i].name);
        list->products[i].article[new_size] = '\0';
        for (int j = 0; list->products[i].article[j] != 0; j++)
            if (list->products[i].article[j] <= 'z' && list->products[i].article[j] >= 'a')
                list->products[i].article[j] += 'A' - 'a';
    }
    return 0;
}

int read_list(product_list *list, FILE *f)
{
    char article[MAX_LEN];
    char name[MAX_LEN];
    int count = 0;

    for (; ;)
    {
        puts("Enter article: ");
        if (fscanf(f, "%512s", article) != 1)
            return READ_ER;

        if (!strcmp(article, "nothing"))
        {
            if (!list->size)
                return MEM_ER;
            break;
        }
        if (!check_article(article))
            return READ_ER;

        puts("Enter name: ");
        if (fscanf(f, "%512s", name) != 1)
            return READ_ER;

        puts("Enter count: ");
        if (fscanf(f, "%d", &count) != 1)
            return READ_ER;

        if (count < 0)
            return READ_ER;

        if (list->size == list->aloc_memory)
            realloc_list(list);

        list->products[list->size].article = malloc((strlen(article) + strlen(name) + 1) * sizeof(char));
        strcpy(list->products[list->size].article, article);
        list->products[list->size].article[strlen(article)] = '\0';

        list->products[list->size].name = malloc((strlen(name) + 1) * sizeof(char));
        strcpy(list->products[list->size].name, name);
        list->products[list->size].name[strlen(name)] = '\0';

        list->products[list->size].count = count;
        ++(list->size);
    }
    return 0;
}

void delete_el_by_param(product_list *list)
{
    for (int i = 0; i < list->size; i++)
        if (!strcmp(list->products[i].article, "LIPSTICK") && !list->products[i].count)
        {
            free(list->products[i].name);
            free(list->products[i].article);
            for (int j = i; j < list->size - 1; j++)
                list->products[j] = list->products[j + 1];
            --(list->size);
            --i;
        }
}

void print_to_file(product_list products, FILE *f)
{
    for (int i = 0; i < products.size; i++)
    {
        fprintf(f, "%s\n", products.products[i].article);
        fprintf(f, "%s\n", products.products[i].name);
        fprintf(f, "%d\n", products.products[i].count);
    }
}