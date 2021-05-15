#include <math.h>
#include "Matrix.h"

void matrix_to_square(my_matrix *matrix)
{
    if (matrix->row == matrix->column)
        return;

    int delete_row = matrix->row > matrix->column;
    size_t n_del = 0;
    if (matrix->row > matrix->column)
        n_del = matrix->row - matrix->column;
    else
        n_del = matrix->column - matrix->row;

    for (size_t n = 0; n < n_del; n++)
    {
        double min = matrix->matrix[0][0];
        size_t to_del = 0;
        for (size_t i = 0; i < matrix->row; i++)
            for (size_t j = 0; j < matrix->column; j++)
                if (matrix->matrix[i][j] <= min)
                {
                    min = matrix->matrix[i][j];
                    to_del = delete_row ? i : j;
                }
        if (delete_row)
            matrix_del_row(matrix, to_del);
        else
            matrix_del_column(matrix, to_del);
    }
}

int avg_count(my_matrix matrix, int i, int j)
{
    double sum = 1;
    for (int i_new = 0; i_new < i; i_new++)
        sum *= matrix.matrix[i_new][j];
    double step = 1 / (double)i;
    int res = (int)pow(sum, step);
    return res;
}

int min_count(my_matrix matrix, int i, int j)
{
    int min = matrix.matrix[i][0];
    for (int j_new = 0; j_new < j; j_new++)
        if (matrix.matrix[i][j_new] < min)
            min = (int)matrix.matrix[i][j_new];
    return min;
}


void fill_matrix(my_matrix *matrix, int diff)
{
    for (size_t i = matrix->row - diff; i < matrix->row; i++)
        for (size_t j = 0; j < matrix->row - diff; j++)
            matrix->matrix[i][j] = avg_count(*matrix, i, j);

    for (size_t i = 0; i < matrix->row; i++)
        for (size_t j = matrix->row - diff; j < matrix->row; j++)
            matrix->matrix[i][j] = min_count(*matrix, i, j);
}
