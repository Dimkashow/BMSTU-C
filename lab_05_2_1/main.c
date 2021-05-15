#include <stdio.h>
#define MAX_SIZE 10
#define MIN_SIZE 1

#define NEED_ARG 2
#define INPUT_ER 1
#define RIGHT 0
#define ER 1

void find_result(int matrix[][MAX_SIZE], const int row, const int column, int arr[])
{
    for (int i = 0; i < column; i++)
    {
        int res = 1;
        for (int j = 0; j < row - 1; j++)
            if (matrix[j + 1][i] * matrix[j][i] >= 0)
                res = 0;
        arr[i] = res;
        if (row == 1)
            arr[i] = 0;
        printf("%d ", arr[i]);
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

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
    int arr[MAX_SIZE] = { 0 };

    int row, column;

    puts("Enter count row and column");
    const int check_input = scanf("%d %d", &row, &column);

    if (check_variables(check_input, row, column))
        return INPUT_ER;

    if (input_matrix(matrix, row, column))
        return INPUT_ER;

    find_result(matrix, row, column, arr);

    return 0;
}
