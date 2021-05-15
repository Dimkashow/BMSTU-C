#ifndef IU7_CPROG_LABS_2019_DMITRYKOVALEV_CDIO_ARR_H
#define IU7_CPROG_LABS_2019_DMITRYKOVALEV_CDIO_ARR_H

int creat_arr(double **const arr, int *const n);

void delete_from_arr(double *const arr, int *const n, const double u);

void add_to_arr(double *const arr, const int n, const int pos, const double u2);

void print_arr(const double *const arr, const int n);

void arr_del(double *const arr, int *n, const int pos);

void add_by_pos(double *const arr, const int n, const int pos, const double u2);

#endif //IU7_CPROG_LABS_2019_DMITRYKOVALEV_CDIO_ARR_H
