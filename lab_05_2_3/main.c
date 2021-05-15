#include <stdio.h>
#define MAX_SIZE 11
#define MIN_SIZE 1

#define NEED_ARG 2
#define INPUT_ER 1
#define RIGHT 0
#define ER 1

#define NO 0
#define YES 1

void swap(int matrix[][MAX_SIZE], const int row, const int column, const int need)
{
    for (int i = 0; i <= column; i++)
    {
        int tmp = matrix[need][i];
        matrix[need][i] = matrix[need + 1][i];
        matrix[need + 1][i] = tmp;
    }
}

void sort_matrix(int matrix[][MAX_SIZE], const int row, const int column)
{
    for (int i = 0; i < (row - 1); i++)
        for (int j = 0; j < (row - i - 1); j++)
        {
            if (matrix[j][column] > matrix[j + 1][column])
                swap(matrix, row, column, j);
        }
}

void find_multiply_res(int matrix[][MAX_SIZE], const int row, const int column)
{
    for (int i = 0; i < row; i++)
    {
        int res = 1;
        for (int j = 0; j < column; j++)
            res *= matrix[i][j];
        matrix[i][column] = res;
    }
}

int input_matrix(int matrix[][MAX_SIZE], const int row, const int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return ER;
    return RIGHT;
}

int check_variables(const int count, const int row, const int column)
{
    if (count != 2)
        return ER;

    if (row < MIN_SIZE || row > MAX_SIZE)
        return ER;

    if (column < MIN_SIZE || column > MAX_SIZE)
        return ER;

    return RIGHT;
}

void print_matrix(int matrix[][MAX_SIZE], const int row, const int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d ", matrix[i][j]);
        puts("\n");
    }
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE] = { 0 };

    int row, column;

    puts("Enter count row and column");
    const int check_input = scanf("%d %d", &row, &column);

    if (check_variables(check_input, row, column))
        return INPUT_ER;

    if (input_matrix(matrix, row, column))
        return INPUT_ER;

    find_multiply_res(matrix, row, column);
    sort_matrix(matrix, row, column);
    print_matrix(matrix, row, column);

    return 0;
}
