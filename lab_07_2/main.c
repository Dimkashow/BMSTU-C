#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR_FILENAME 1
#define ERROR_ARGS 53
#define OK 0
#define SUCCESS 0
#define ERROR_FILEDATA 2

#define MAX_NAME_LEN 31
#define MAX_MANUFACTURER_LEN 15
#define ARRAY_LEN 300

typedef struct
{
    char name[31];
    char manufacturer[16];
    unsigned int price;
    unsigned int count;
} supplies;

void sort_supplies(supplies sup[], const int len)
{
    supplies temp;
    for (int i = 0; i < len - 1; i ++)
    {
        int min_i = i;
        for (int j = i + 1; j < len; j++)
        {
            if (sup[j].price > sup[min_i].price)
                min_i = j;
            else if (sup[j].price == sup[min_i].price)
                if (sup[j].count > sup[min_i].count)
                    min_i = j;
        }
        temp = sup[i];
        sup[i] = sup[min_i];
        sup[min_i] = temp;
    }
}

int read_file(FILE *const f, supplies list[], int *const list_len)
{
    while (fgets(list[*list_len].name, MAX_NAME_LEN, f))
    {
        if (!fgets(list[*list_len].manufacturer, MAX_MANUFACTURER_LEN, f))
            return ERROR_FILEDATA;

        if (fscanf(f, "%u %u", &list[*list_len].price, &list[*list_len].count) != 2)
            return ERROR_FILEDATA;

        *list_len += 1;
        fseek(f, 1, SEEK_CUR);
    }
    return OK;
}

void print_supplies(FILE *const out, const supplies sup[], const int len)
{
    for (int i = 0; i < len; i++)
        fprintf(out, "%s%s%u\n%u\n", sup[i].name, sup[i].manufacturer, sup[i].price, sup[i].count);
}

void print_same_sup(const supplies sup[], const int len, const char str[MAX_NAME_LEN], int *const kol)
{
    for (int i = 0; i < len; i++)
    {
        int len_name = strlen(sup[i].name) - 1;
        int len_substr = strlen(str);

        if (len_name >= len_substr)
        {
            char check[MAX_NAME_LEN];
            strcpy(check, &sup[i].name[len_name - len_substr]);
            check[strlen(check) - 1] = '\0';

            if (!strcmp(check, str))
            {
                printf("%s%s%u\n%u\n", sup[i].name, sup[i].manufacturer, sup[i].price, sup[i].count);
                ++(*kol);
            }
        }
    }
}

int check_number(int n)
{
    int i = 0;
    while (n > 0)
    {
        n = n / 10;
        i++;
    }
    return i;
}

int find_new_len(supplies *const new, int *const len)
{
    if (scanf("%s %s %u %u", new->name, new->manufacturer, &new->price, &new->count) != 4)
        return ERROR_FILEDATA;

    *len += strlen(new->name);
    *len += strlen(new->manufacturer);
    *len += check_number(new->price);
    *len += check_number(new->count);
    *len += 4;

    return OK;
}

void find_pos_to_enter(FILE *const file_in, const supplies new, int *const len_to_out)
{
    rewind(file_in);
    supplies check;
    while (!feof(file_in))
    {
        while (fgets(check.name, MAX_NAME_LEN, file_in))
        {
            if (!fgets(check.manufacturer, MAX_MANUFACTURER_LEN, file_in))
                return;

            if (fscanf(file_in, "%u %u", &check.price, &check.count) != 2)
                return;

            fseek(file_in, 1, SEEK_CUR);

            if (new.price > check.price)
                break;
            else if (new.price == check.price)
                if (new.count > check.count)
                    break;
            *len_to_out += strlen(check.name);
            *len_to_out += strlen(check.manufacturer);
            *len_to_out += check_number(check.price);
            *len_to_out += check_number(check.count);
            *len_to_out += 2;
        }
    }
    rewind(file_in);
}

void shift_file(FILE *const f_from, const int sup_len, const int len_to_shift)
{
    int size = 0;
    while (!feof(f_from))
    {
        getc(f_from);
        size++;
    }
    fseek(f_from, 0, SEEK_SET);

    for (int z = 0; z < sup_len; z++)
    {
        for (int i = 1; i != size - len_to_shift + 1; i++)
        {
            int j = -i;
            fseek(f_from, j, SEEK_END);
            char c = fgetc(f_from);
            fputc(c, f_from);
        }
    }
}

void put_in_file_new_sup(FILE *const ptr, const supplies new, const int len)
{
    fseek(ptr, len, SEEK_SET);
    fprintf(ptr, "%s\n%s\n%u\n%u\n", new.name, new.manufacturer, new.price, new.count);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        return ERROR_ARGS;

    if ((strcmp(argv[1], "st") == OK) && (argc == 4))
    {
        FILE *file_in;
        FILE *file_out;

        if (!(file_in = fopen(argv[2], "rt")))
            return ERROR_FILENAME;

        if (!(file_out = fopen(argv[3], "wt")))
        {
            fclose(file_in);
            return ERROR_FILENAME;
        }

        supplies sup[ARRAY_LEN];
        int len = 0;
        int er = read_file(file_in, sup, &len);
        if (er)
        {
            fclose(file_in);
            fclose(file_out);
            return ERROR_FILEDATA;
        }

        if (!len)
        {
            fclose(file_in);
            fclose(file_out);
            return ERROR_FILEDATA;
        }

        sort_supplies(sup, len);
        print_supplies(file_out, sup, len);

        fclose(file_in);
        fclose(file_out);

        return SUCCESS;
    }
    else if (strcmp(argv[1], "ft") == 0 && argc == 4)
    {
        FILE *file_in;
        if (!(file_in = fopen(argv[2], "rt")))
            return ERROR_FILENAME;

        supplies sup[ARRAY_LEN];
        int len = 0;
        int er = read_file(file_in, sup, &len);
        if (er)
        {
            fclose(file_in);
            return ERROR_FILEDATA;
        }
        if (!len)
        {
            fclose(file_in);
            return ERROR_FILEDATA;
        }
        int kol = 0;
        print_same_sup(sup, len, argv[3], &kol);

        if (!kol)
            return ERROR_FILEDATA;

        fclose(file_in);

        return OK;
    }
    else if (strcmp(argv[1], "at") == 0 && argc == 3)
    {
        FILE *file_in;
        if (!(file_in = fopen(argv[2], "r+")))
            return ERROR_FILENAME;

        int new_sup_len = 0;
        supplies new_sup;
        int er = find_new_len(&new_sup, &new_sup_len);
        if (er)
            return ERROR_FILEDATA;

        int len_to_enter = 0;
        find_pos_to_enter(file_in, new_sup, &len_to_enter);

        shift_file(file_in, new_sup_len, len_to_enter);

        put_in_file_new_sup(file_in, new_sup, len_to_enter);

        fclose(file_in);
        return OK;
    }

    return ERROR_ARGS;
}
