#include <stdio.h>
#define OK 0
#define FILE_CANT_OPEN 1
#define ER 2
#define INPUT_ER 3
#define NO_ELEMENT 4

void find_disp(FILE *ptr, double avg, double *disp)
{
    double n = 0;
    while (!feof(ptr))
    {
        fscanf(ptr, "%lf", &n);
        *disp += (n - avg) * (n - avg);
    }
}

int find_avg(FILE *ptr, double *avg, int *file_len)
{
    double n = 0;
    while (!feof(ptr))
    {
        if (fscanf(ptr, "%lf", &n) != 1)
            return INPUT_ER;

        (*file_len)++;
        *avg += n;
    }

    if (!(*file_len))
        return NO_ELEMENT;

    *avg /= *file_len;

    return OK;
}

int main(int argc, char *const argv[])
{
    double avg = 0;
    double disp = 0;
    int file_len = 0;

    FILE *ptr = fopen(argv[1], "r");

    if (!ptr)
        return FILE_CANT_OPEN;

    int any_er = find_avg(ptr, &avg, &file_len);

    if (any_er)
        return ER;

    fseek(ptr, 0, SEEK_SET);

    find_disp(ptr, avg, &disp);

    disp /= file_len;

    printf("%lf", disp);

    fclose(ptr);
    return OK;
}
