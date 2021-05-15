#include <stdio.h>
#define MAX_SIZE 10
#define MIN_SIZE 1

#define NEED_ARG 2
#define INPUT_ER 1
#define RIGHT 0
#define ER 1

#define NO 0
#define YES 1

void add_row(int matrix[][MAX_SIZE], const int row, const int column, const int new_row)
{
    for (int i = row - 1; i >= new_row; i--)
        for (int j = 0; j < column; j++)
            matrix[i + 1][j] = matrix[i][j];

    for (int i = 0; i < column; i++)
        matrix[new_row][i] = -1;
}

int check_number(int n)
{
    if (n < 0)
        n = -n;
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    if (sum % 2)
        return YES;
    return NO;
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

int input_matrix(int matrix[][MAX_SIZE], const int row, const int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return ER;
    return RIGHT;
}

void modify_matrix(int matrix[][MAX_SIZE], int *const pointer_to_row, const int column)
{
    for (int i = 0; i < *pointer_to_row; i++)
    {
        int kol = 0;
        for (int j = 0; j < column; j++)
            kol += check_number(matrix[i][j]);
        if (kol >= 2)
        {
            add_row(matrix, *pointer_to_row, column, i);
            i++;
            ++(*pointer_to_row);
        }
    }
}

int main()
{
    int matrix[MAX_SIZE*2][MAX_SIZE] = { 0 };

    int row, column;
    int *const pointer_to_row = &row;

    puts("Enter count row and column");
    const int check_input = scanf("%d %d", &row, &column);

    if (check_variables(check_input, row, column))
        return INPUT_ER;

    if (input_matrix(matrix, row, column))
        return INPUT_ER;

    modify_matrix(matrix, pointer_to_row, column);

    print_matrix(matrix, row, column);

    return 0;
}