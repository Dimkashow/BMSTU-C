#include "Matrix.h"
#include "lab_operation.h"

#define FILE_ER 1

int equal_matrix(my_matrix *matrix1, my_matrix *matrix2)
{
    if (matrix1->row != matrix2->row && matrix1->column != matrix2->column)
        return 0;

    for (size_t i = 0; i < matrix1->row; i++)
        for (size_t j = 0; j < matrix1->column; j++)
            if (matrix1->matrix[i][j] != matrix2->matrix[i][j])
                return 0;
    return 1;
}

int test_fill(char *to_test, char *expected, int diff)
{
    FILE * f = ((void *)0);
    if (!(f = fopen(to_test, "r")))
        return FILE_ER;
    my_matrix * matrix_to_fill = create_matrix_from_file(f);
    fclose(f);
    fill_matrix(matrix_to_fill, diff);

    if (!(f = fopen(expected, "r")))
        return FILE_ER;
    my_matrix * matrix_expected = create_matrix_from_file(f);
    fclose(f);

    int res = equal_matrix(matrix_expected, matrix_to_fill);

    free_matrix(matrix_to_fill);
    free_matrix(matrix_expected);

    return (!res);
}

int test_square(char *to_test, char *expected)
{
    FILE * f = ((void *)0);
    if (!(f = fopen(to_test, "r")))
        return FILE_ER;
    my_matrix * matrix_to_fill = create_matrix_from_file(f);
    fclose(f);
    matrix_to_square(matrix_to_fill);

    if (!(f = fopen(expected, "r")))
        return FILE_ER;
    my_matrix * matrix_expected = create_matrix_from_file(f);
    fclose(f);

    int res = equal_matrix(matrix_expected, matrix_to_fill);

    free_matrix(matrix_to_fill);
    free_matrix(matrix_expected);

    return (!res);
}

int testing_fill()
{
    int res = 0;
    if (test_fill("test_data/data_1.txt", "test_data/data_2.txt", 2))
    {
        puts("STD FILL FAILED");
        res++;
    }

    if (test_fill("test_data/data_3.txt", "test_data/data_4.txt", 3))
    {
        puts("BIG NUMBER FILL FAILED");
        res++;
    }

    if (test_fill("test_data/data_5.txt", "test_data/data_6.txt", 1))
    {
        puts("ONE NUMBER FILL FAILED");
        res++;
    }

    return res;
}


int testing_square_matrix()
{
    int res = 0;
    if (test_square("test_data/data_7.txt", "test_data/data_8.txt"))
    {
        puts("DEL ROWS SQUARE FAILED");
        res++;
    }

    if (test_square("test_data/data_9.txt", "test_data/data_10.txt"))
    {
        puts("DEL COLS SQUARE FAILED");
        res++;
    }

    if (test_square("test_data/data_11.txt", "test_data/data_12.txt"))
    {
        puts("NOTHING DEL FAILED");
        res++;
    }

    return res;
}

int main()
{
    int res = 0;
    res += testing_fill();
    res += testing_square_matrix();
    return res;
}