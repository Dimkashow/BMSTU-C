#include "Matrix.h"

#define MEM_ER 1;
#define MATRIX_ER 2;

my_matrix *create_matrix_from_file(FILE *f)
{
    int rows_scan = 0;
    int cols_scan = 0;
    if (fscanf(f, "%d %d", &rows_scan, &cols_scan) != 2)
    {
        return ((void *)0);
    }
    if (rows_scan <= 0 || cols_scan <= 0)
    {
        return ((void *)0);
    }
    size_t rows = rows_scan;
    size_t cols = cols_scan;

    my_matrix * matrix = create_matrix(rows, cols);
    if (!matrix)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (fscanf(f, scan_type, &matrix->matrix[i][j]) != 1)
            {
                free_matrix(matrix);
                return ((void *)0);
            }
        }
    }
    return matrix;
}


my_matrix *create_matrix(size_t rows, size_t cols)
{
    my_matrix * matrix = malloc(sizeof(my_matrix));
    matrix->matrix = (type **)malloc(rows * sizeof(type *));
    if (!(matrix->matrix))
    {
        free_matrix(matrix);
        return ((void *)0);
    }

    matrix->row = 0;
    for (size_t i = 0; i < rows; i++)
    {
        matrix->matrix[i] = (type *)malloc(sizeof(type) * cols);
        if (!(matrix->matrix[i]))
        {
            free_matrix(matrix);
            return ((void *)0);
        }
        ++(matrix->row);
    }

    matrix->column = cols;

    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = 0; j < matrix->column; j++)
        {
            matrix->matrix[i][j] = 0;
        }
    }

    return matrix;
}

int get_rows(const my_matrix *matrix, size_t *rows)
{
    if (!matrix->matrix || *rows >= matrix->row)
    {
        return MATRIX_ER;
    }
    *rows = matrix->row;
    return 0;
}

int get_cols(const my_matrix *matrix, size_t *cols)
{
    if (!matrix->matrix || *cols >= matrix->column)
    {
        return MATRIX_ER;
    }
    *cols = matrix->column;
    return 0;
}

int get_elem(const my_matrix *matrix, size_t row, size_t col, double *val)
{
    if (!matrix || row >= matrix->row || col >= matrix->column || !val)
    {
        return MATRIX_ER;
    }
    *val = matrix->matrix[row][col];
    return 0;
}

int set_elem(my_matrix *matrix, size_t row, size_t col, double val)
{
    if (!matrix || row >= matrix->row || col >= matrix->column)
    {
        return MATRIX_ER;
    }
    matrix->matrix[row][col] = (type)val;
    return 0;
}

int free_matrix(my_matrix *matrix)
{
    if (!matrix)
    {
        return MATRIX_ER;
    }
    for (size_t j = 0; j < matrix->row; j++)
    {
        free((matrix->matrix)[j]);
    }
    free(matrix->matrix);
    free(matrix);
    return 0;
}

my_matrix *mul_scalar(const my_matrix *matrix, double val)
{
    if (!matrix)
    {
        return ((void *)0);
    }
    my_matrix * mul = create_matrix(matrix->row, matrix->column);
    if (!mul)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < mul->row; i++)
    {
        for (size_t j = 0; j < mul->column; j++)
        {
            mul->matrix[i][j] = (type)val * matrix->matrix[i][j];
        }
    }
    return mul;
}

my_matrix *transp(const my_matrix *matrix)
{
    if (!matrix)
    {
        return ((void *)0);
    }
    my_matrix * t_matrix = create_matrix(matrix->column, matrix->row);
    if (!t_matrix)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < t_matrix->row; i++)
    {
        for (size_t j = 0; j < t_matrix->column; j++)
        {
            t_matrix->matrix[i][j] = matrix->matrix[j][i];
        }
    }
    return t_matrix;
}

my_matrix *sum(const my_matrix *l, const my_matrix *r)
{
    if (!l || !r)
    {
        return ((void *)0);
    }
    if (l->column != r->column || l->row != r->row)
    {
        return ((void *)0);
    }
    my_matrix * matrix = create_matrix(l->row, l->column);
    if (!matrix)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = 0; j < matrix->column; j++)
        {
            matrix->matrix[i][j] = l->matrix[i][j] + r->matrix[i][j];
        }
    }
    return matrix;
}

my_matrix *sub(const my_matrix *l, const my_matrix *r)
{
    if (!l || !r)
    {
        return ((void *)0);
    }
    if (l->column != r->column || l->row != r->row)
    {
        return ((void *)0);
    }
    my_matrix * matrix = create_matrix(l->row, l->column);
    if (!matrix)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = 0; j < matrix->column; j++)
        {
            matrix->matrix[i][j] = l->matrix[i][j] - r->matrix[i][j];
        }
    }
    return matrix;
}

my_matrix *mul(const my_matrix *l, const my_matrix *r)
{
    if (!l || !r)
    {
        return ((void *)0);
    }
    if (l->column != r->row)
    {
        return ((void *)0);
    }
    my_matrix * matrix = create_matrix(l->row, r->column);
    if (!matrix)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = 0; j < matrix->column; j++)
        {
            matrix->matrix[i][j] = 0;
            for (size_t z = 0; z < l->column; z++)
            {
                matrix->matrix[i][j] += l->matrix[i][z] * r->matrix[z][j];
            }
        }
    }
    return matrix;
}

void matrix_del_column(my_matrix *matrix, size_t pos)
{
    if (!matrix || pos >= matrix->column)
    {
        return;
    }
    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = pos; j < matrix->column - 1; j++)
        {
            matrix->matrix[i][j] = matrix->matrix[i][j + 1];
        }
    }
    matrix->column--;
}

void matrix_del_row(my_matrix *matrix, size_t pos)
{
    if (!matrix || pos >= matrix->row)
    {
        return;
    }

    free(matrix->matrix[pos]);
    for (size_t i = pos; i < matrix->row - 1; i++)
    {
        matrix->matrix[i] = matrix->matrix[i + 1];
    }
    --(matrix->row);
}

void create_minor(my_matrix *matrix, size_t i, size_t j)
{
    matrix_del_row(matrix, i);
    matrix_del_column(matrix, j);
}

void copy_matrix(my_matrix *a, const my_matrix *b)
{
    if (!a || !b)
    {
        return;
    }
    for (size_t i = 0; i < a->row; i++)
    {
        for (size_t j = 0; j < a->column; j++)
        {
            a->matrix[i][j] = b->matrix[i][j];
        }
    }
}

int det(const my_matrix *matrix, double *val)
{
    if (!matrix || !val)
    {
        return MATRIX_ER;
    }
    double res = 0;
    int degree = 1;
    *val = 0;
    if (matrix->row != matrix->column)
    {
        return MATRIX_ER;
    }
    if (matrix->row == 1)
    {
        *val = matrix->matrix[0][0];
        return 0;
    }
    for (size_t i = 0; i < matrix->column; i++)
    {
        my_matrix * new_matrix = create_matrix(matrix->row, matrix->row);
        if (!new_matrix)
        {
            return MEM_ER;
        }
        copy_matrix(new_matrix, matrix);
        create_minor(new_matrix, 0, i);
        det(new_matrix, val);
        free_matrix(new_matrix);
        res += matrix->matrix[0][i] * degree * (*val);
        degree = -degree;
    }
    *val = res;
    return 0;
}

my_matrix *adj(const my_matrix *matrix)
{
    if (!matrix)
    {
        return ((void *)0);
    }
    my_matrix * new_matrix = create_matrix(matrix->column, matrix->row);
    if (!new_matrix)
    {
        return ((void *)0);
    }
    if (new_matrix->column == 1)
    {
        my_matrix *single = create_matrix(1, 1);
        if (!single)
        {
            return ((void *)0);
        }
        single->matrix[0][0] = 1;
        free_matrix(new_matrix);
        return single;
    }
    double val = 0;
    for (size_t i = 0; i < new_matrix->row; i++)
    {
        int degree = (i % 2) ? -1 : 1;
        for (size_t j = 0; j < new_matrix->column; j++)
        {
            my_matrix * minor = create_matrix(matrix->row, matrix->column);
            if (!minor)
            {
                free_matrix(new_matrix);
                return ((void *)0);
            }
            copy_matrix(minor, matrix);
            create_minor(minor, i, j);
            det(minor, &val);
            free_matrix(minor);
            new_matrix->matrix[j][i] = (type)val * degree;
            degree = -degree;
        }
    }
    return new_matrix;
}

my_matrix *inv(const my_matrix *matrix)
{
    if (!matrix)
    {
        return ((void *)0);
    }
    my_matrix * adj_matrix = adj(matrix);
    if (!adj_matrix)
    {
        return ((void *)0);
    }
    double val = 0;
    det(matrix, &val);
    if (val == 0)
    {
        return ((void *)0);
    }
    for (size_t i = 0; i < adj_matrix->row; i++)
    {
        for (size_t j = 0; j < adj_matrix->column; j++)
        {
            adj_matrix->matrix[i][j] /= (type)val;
        }
    }
    return adj_matrix;
}

int matrix_add_columns(my_matrix *matrix, size_t new_columns)
{
    for (size_t i = 0; i < matrix->row; i++)
    {
        type * ptr = realloc(matrix->matrix[i], (new_columns + matrix->column) * sizeof(type));
        if (!ptr)
        {
            free_matrix(matrix);
            return MEM_ER;
        }
        matrix->matrix[i] = ptr;
    }
    matrix->column += new_columns;
    return 0;
}


int matrix_add_rows(my_matrix *matrix, size_t new_rows)
{
    type * * new_ptr = realloc(matrix->matrix, (new_rows + matrix->row) * sizeof(type *));
    if (!new_ptr)
        return MEM_ER;

    matrix->matrix = new_ptr;

    for (size_t i = 0; i < new_rows; i++)
    {
        type * ptr = malloc((new_rows + matrix->row) * sizeof(type));
        if (!ptr)
            return MEM_ER;
        matrix->matrix[i + matrix->row] = ptr;
    }
    matrix->row += new_rows;
    return 0;
}

void print_matrix(const my_matrix *matrix)
{
    for (size_t i = 0; i < matrix->row; i++)
    {
        for (size_t j = 0; j < matrix->column; j++)
            printf("%-7.lf ", matrix->matrix[i][j]);
        puts("");
    }
}

my_matrix *mpow(const my_matrix *matrix, size_t n)
{
    my_matrix * matrix_mul_a = create_matrix(matrix->row, matrix->column);
    copy_matrix(matrix_mul_a, matrix);
    for (size_t i = 1; i < n; i++)
    {
        my_matrix * matrix_new_mul_a = mul(matrix_mul_a, matrix);
        copy_matrix(matrix_mul_a, matrix_new_mul_a);
        free_matrix(matrix_new_mul_a);
    }
    return matrix_mul_a;
}

void fill_identity_matrix(my_matrix *matrix)
{
    for (size_t i = 0; i < matrix->row; i++)
        for (size_t j = 0; j < matrix->column; j++)
            matrix->matrix[i][j] = i == j;
}
