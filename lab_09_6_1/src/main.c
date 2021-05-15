#include "Matrix.h"

#include "lab_operation.h"

#define ERR_MATRIX_CREATE 1
#define ERR_MATRIX_CHANGE 2
#define ERR_SCAN 3

// СЛОМАННЫЙ STYLE-CHECKER ЗАСТАВИЛ МЕНЯ ПИСАТЬ
// my_matrix * any_matrix
// Я/МЫ АЛЕКСЕЙ РОМАНОВ
int main()
{
    my_matrix * matrix_a = create_matrix_from_file(stdin);
    if (!matrix_a)
        return ERR_MATRIX_CREATE;

    my_matrix * matrix_b = create_matrix_from_file(stdin);
    if (!matrix_b)
    {
        free_matrix(matrix_a);
        return ERR_MATRIX_CREATE;
    }
    matrix_to_square(matrix_a);
    matrix_to_square(matrix_b);

    int delta = matrix_a->row - matrix_b->row;
    int err = 0;
    if (delta > 0)
    {
        err += matrix_add_columns(matrix_b, delta);
        err += matrix_add_rows(matrix_b, delta);
    }
    else
    {
        err += matrix_add_columns(matrix_a, -delta);
        err += matrix_add_rows(matrix_a, -delta);
    }
    if (err)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ERR_MATRIX_CHANGE;
    }

    if (delta > 0)
        fill_matrix(matrix_b, delta);
    else
        fill_matrix(matrix_a, -delta);

    int a = 0;
    int b = 0;
    if (scanf("%d %d", &a, &b) != 2)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ERR_SCAN;
    }

    if (a < 0 || b < 0)
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ERR_SCAN;
    }

    if (!a)
        fill_identity_matrix(matrix_a);

    if (!b)
        fill_identity_matrix(matrix_b);

    my_matrix * matrix_a_mul = mpow(matrix_a, a);
    my_matrix * matrix_b_mul = mpow(matrix_b, b);

    my_matrix * matrix_result = mul(matrix_a_mul, matrix_b_mul);

    print_matrix(matrix_result);

    free_matrix(matrix_a);
    free_matrix(matrix_a_mul);

    free_matrix(matrix_b);
    free_matrix(matrix_b_mul);

    free_matrix(matrix_result);

    return 0;
}