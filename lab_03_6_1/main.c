#include <stdio.h>
#define OK 0
#define EMPTY_ER 1;
#define DIGIT_ER 3;
#define ERROR 4;


int find_result(FILE *const f, int *const res)
{
    if (feof(f))
    {
        return EMPTY_ER;
    }

    int new;
    int old;
    int check_input = fscanf(f, "%d %d", &old, &new);
    if (check_input != 2)
        return DIGIT_ER;
    int napr = 0;
    int now = 0;
    int max = -1;
    
    if (new > old)
    {
        napr = 1;
        now = 2;
        max = 2;
    }
    else if (old > new)
    {
        napr = -1;
        now = 2;
        max = 2;
    }
    
    while (!feof(f))
    {
        check_input = fscanf(f, "%d", &new);
        if (check_input != 1)
            return DIGIT_ER;
        if (napr == 0)
        {
            if (new > old)
            {
                now = 2;
                napr = 1;
            }

            if (new < old)
            {
                now = 2;
                napr = -1;
            }
        }
        else if (napr == 1)
        {
            if (new > old)
                now++;
            else
            {
                if (now > max)
                    max = now;

                if (new == old)
                {
                    napr = 0;
                    now = 0;
                }

                if (new < old)
                {
                    napr = -1;
                    now = 2;
                }
            }
        }
        else
        {
            if (new < old)
                now++;
            else
            {
                if (now > max)
                    max = now;

                if (new == old)
                {
                    napr = 0;
                    now = 0;
                }

                if (new > old)
                {
                    napr = 1;
                    now = 2;
                }
            }
        }
        old = new;
    }
    if (now > max)
        max = now;
    *res = max;
    return OK;
}

int main()
{
    int res = -1;
    int const res_code = find_result(stdin, &res);

    if (res_code)
        return ERROR;
    printf("%d", res);

    return OK;
}