#define MAX_LEN 100
#include <stdio.h>

void print_matrix(int matrix[][MAX_LEN], int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void print_matrix_to_file(FILE *f, int matrix[][MAX_LEN], int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            fprintf(f, "%d ", matrix[i][j]);
        fprintf(f, "\n");
    }
}

int check_matrix(int matrix[][MAX_LEN], int x_len, int y_len, int i_check, int j_check, int len)
{
    if ((i_check + len <= y_len) && (j_check + len <= x_len))
    {
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
            {
                if (matrix[i + i_check][j + j_check] != 0)
                    return 0;
            }
        return 1;
    }
    else
        return 0;
}

void to_out(int matrix[][MAX_LEN], int i_check, int j_check, int len, int val)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            matrix[i + i_check][j + j_check] = val;
}
        
int main()
{
    FILE* f;
    f = fopen("in.txt", "r");
    int sizei, sizej, len;
    int x, y, value;
    if (f)
    {
        fscanf(f, "%d %d %d", &sizei, &sizej, &len);
        int matrix[MAX_LEN][MAX_LEN] = { 0 };
        int new_matrix[MAX_LEN][MAX_LEN] = { 0 };

        
        for (int i = 0; i < len; i++)
            if (fscanf(f, "%d %d %d", &x, &y, &value) == 3)
            {
                matrix[x - 1][y - 1] = value;
                new_matrix[x - 1][y - 1] = value;
            }
            
        for (int i = 0; i < sizei; i++)
            for (int j = 0; j < sizej; j++)
            {
                if (matrix[i][j] == 0)
                {
                    int leng = 2;
                    int res = 1;
                    while (res)
                    {
                        res = check_matrix(matrix, sizei, sizej, i, j, leng);
                        if (res)
                            to_out(new_matrix, i, j, leng, len);
                        leng++;
                    }
                }
            }
        fclose(f);           
        f = fopen("out.txt", "w");
        print_matrix(new_matrix, sizei, sizej);
        print_matrix_to_file(f, new_matrix, sizei, sizej);
        fclose(f);
    }
}