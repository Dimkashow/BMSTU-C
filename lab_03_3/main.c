#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ARGS_ER 1
#define FILE_ER 2

int get_number_by_pos(FILE *ptr, int pos)
{
    int n;
    fseek(ptr, (pos - 1) * sizeof(int), SEEK_SET);
    fread(&n, sizeof(int), 1, ptr);
    return n;
}

void put_number_by_pos(FILE *ptr, int pos, int n)
{
    fseek(ptr, (pos - 1) * sizeof(int), SEEK_SET);
    fwrite(&n, sizeof(int), 1, ptr);
}

void sort_file(FILE *ptr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int index_min_elem = i;
        for (int j = i + 1; j <= size; j++)
        {
            int curr_numb = get_number_by_pos(ptr, j);
            int min_index_numb = get_number_by_pos(ptr, index_min_elem);
            if (curr_numb < min_index_numb)
            {
                index_min_elem = j;
            }
        }
        int temp = get_number_by_pos(ptr, i);
        int curr_numb = get_number_by_pos(ptr, index_min_elem);
        put_number_by_pos(ptr, i, curr_numb);
        put_number_by_pos(ptr, index_min_elem, temp);
    }
}


int numb_counter(FILE *ptr)
{
    int count = 0;
    int temp_numb;
    while (fread(&temp_numb, sizeof(int), 1, ptr) == 1)
        ++count;

    fseek(ptr, 0, SEEK_SET);
    return count;
}


void menu()
{
    puts("Print file: app.exe p file_name");
    puts("Sort file: app.exe s file_name");
    puts("Create random file: app.exe c file_name");
}

int print_file(FILE *const ptr)
{
    int n = 0;
    int len = 0;

    while (fread(&n, sizeof(int), 1, ptr) == 1)
    {
        printf("%d ", n);
        len++;
    }
    return len;
}

void add_random_num(FILE *ptr)
{
    int i = 0;
    while (i != 100)
    {
        int n = rand() % 1000;
        fwrite(&n, sizeof(int), 1, ptr);
        i++;
    }
}

int main(int argc, char *argv[])
{
    FILE *ptr;

    menu();

    if (argc != 3)
        return ARGS_ER;
    else if (argv[1][0] == 'p')
    {
        ptr = fopen(argv[2], "rb");
        if (!ptr)
            return FILE_ER;

        int len = print_file(ptr);
        if (!len)
            return FILE_ER;

        fclose(ptr);
        return OK;
    }
    else if (argv[1][0] == 's')
    {
        ptr = fopen(argv[2], "r + b");
        int count_numbs = numb_counter(ptr);
        if (0 == count_numbs)
            return FILE_ER;

        sort_file(ptr, count_numbs);

        fclose(ptr);
        return OK;
    }
    else if (argv[1][0] == 'c')
    {
        ptr = fopen(argv[2], "wb");

        if (!ptr)
            return FILE_ER;

        add_random_num(ptr);
        fclose(ptr);
        return OK;
    }
    else
        return ARGS_ER;
}