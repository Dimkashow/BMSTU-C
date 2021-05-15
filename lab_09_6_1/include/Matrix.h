#ifndef PROJECT_INCLUDE_MATRIX_H_
#define PROJECT_INCLUDE_MATRIX_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define scan_type "%lf "
typedef double type;

typedef struct Matrix
{
    type **matrix;
    size_t row;
    size_t column;
} my_matrix;

// Init/release operations
my_matrix *create_matrix_from_file(FILE *f);

my_matrix *create_matrix(size_t rows, size_t cols);

void copy_matrix(my_matrix *a, const my_matrix *b);

int free_matrix(my_matrix *matrix);

void fill_identity_matrix(my_matrix *matrix);


// Basic operations
int get_rows(const my_matrix *matrix, size_t *rows);

int get_cols(const my_matrix *matrix, size_t *cols);

int get_elem(const my_matrix *matrix, size_t row, size_t col, double *val);

int set_elem(my_matrix *matrix, size_t row, size_t col, double val);

void print_matrix(const my_matrix *matrix);

// Math operations
my_matrix *mul_scalar(const my_matrix *matrix, double val);

my_matrix *transp(const my_matrix *matrix);

my_matrix *sum(const my_matrix *l, const my_matrix *r);

my_matrix *sub(const my_matrix *l, const my_matrix *r);

my_matrix *mul(const my_matrix *l, const my_matrix *r);

my_matrix *mpow(const my_matrix *matrix, size_t n);

// Extra operations
int det(const my_matrix *matrix, double *val);

my_matrix *adj(const my_matrix *matrix);

my_matrix *inv(const my_matrix *matrix);

// my_matrix resizing
void matrix_del_row(my_matrix *matrix, size_t pos);

void matrix_del_column(my_matrix *matrix, size_t pos);

int matrix_add_rows(my_matrix *matrix, size_t new_rows_size);

int matrix_add_columns(my_matrix *matrix, size_t new_columns);

#endif  // PROJECT_INCLUDE_MATRIX_H_
