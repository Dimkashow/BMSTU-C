
#include <stdio.h>
#include <math.h>

#include "testing.h"

#define EPS 0.0000001

void test_u1_int(int *n)
{
    double a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    double u = 0;
    double u_expected = 4.5;
    u1_find(a, 8, &u);
    if (fabsf(u_expected - u) < EPS)
        ++(*n);
}

void test_u1_zero(int *n)
{
    double b[4] = { -1, 0, 1, 0 };
    double u = 0;
    double u_expected = 0;
    u1_find(b, 4, &u);
    if (fabsf(u_expected - u) < EPS)
        ++(*n);
}

void test_u1_double(int *n)
{
    double c[5] = { 1.12, 2.32, 3.783, 4.2345, 5.9321 };
    double u = 0;
    double u_expected = 3.47792;
    u1_find(c, 5, &u);
    if (fabsf(u_expected - u) < EPS)
        ++(*n);
}

int test_u1_find()
{
    int n = 0;
    test_u1_int(&n);
    test_u1_zero(&n);
    test_u1_double(&n);
    printf("u1_find_TEST %d/3\n", n);
    if (n != 3)
        return 1;
    return 0;
}

void test_u2_int(int *n)
{
    double a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    double u = 0;
    double u_expected = 8;
    u2_find(a, 8, &u);
    if (fabsf(u_expected - u) < EPS)
        ++(*n);
}

void test_u2_zero(int *n)
{
    double b[4] = { -1, 0, 1, 0 };
    double u = 0;
    double u_expected = 1;
    u2_find(b, 4, &u);
    if (fabsf(u_expected - u) < EPS)
        ++(*n);
}

void test_arr_del_double(int *ok)
{
    int kol = 0;
    int n = 3;
    double b[3] = { 12.3, 3.4, 45.43 };
    double b_test[2] = { 12.3, 45.43 };
    double pos = 1;
    arr_del(b, &n, pos);
    for (int i = 0; i < n; i++)
        kol += (fabsf(*(b + i) - *(b_test + i)) > EPS);
    if (!kol)
        ++(*ok);
}

void test_u2_double(int *n)
{
    double c[5] = { 1.12, 2.32, 3.783, 4.2345, 5.9321 };
    double u = 0;
    double u_expected = 5.9321;
    u2_find(c, 5, &u);
    if (fabsf(u_expected - u) < EPS)
        ++(*n);
}

int test_u2_find()
{
    int n = 0;
    test_u2_int(&n);
    test_u2_zero(&n);
    test_u2_double(&n);

    printf("u2_find TEST %d/3\n", n);
    if (n != 3)
        return 1;
    return 0;
}

void test_arr_del_int(int *ok)
{
    int kol = 0;
    int n = 8;
    double a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    double a_test[7] = { 1, 2, 4, 5, 6, 7, 8 };
    double pos = 2;
    arr_del(a, &n, pos);
    for (int i = 0; i < n; i++)
        kol += (fabsf(*(a + i) - *(a_test + i)) > EPS);
    if (!kol)
        ++*(ok);
}

int test_arr_del()
{
    int ok = 0;
    test_arr_del_int(&ok);
    test_arr_del_double(&ok);
    printf("test_arr_del TEST %d/2\n", ok);
    if (ok != 2)
        return 1;
    return 0;
}

int test_add_by_pos()
{
    int kol = 0;
    int ok = 0;
    int n = 4;
    double a[5] = { 5, 6, 7, 8 };
    double a_test[5] = { -1, 5, 6, 7, 8 };
    double pos = 0;
    add_by_pos(a, n, pos, -1);
    for (int i = 0; i < n; i++)
        kol += (fabsf(*(a + i) - *(a_test + i)) > EPS);
    if (!kol)
        ok++;
    else
        kol = 0;

    printf("test_add_by_pos %d/1\n", ok);
    if (ok != 1)
        return 1;
    return 0;
}

int main()
{
    int res = 0;
    res += test_u1_find();
    res += test_u2_find();
    res += test_arr_del();
    res += test_add_by_pos();

    return res;
}