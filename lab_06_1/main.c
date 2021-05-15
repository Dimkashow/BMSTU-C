#include <stdio.h>
#include <string.h>
#include <stddef.h>


#define MAX_LEN_STR 15
#define COUNT_TESTS 3

const char *my_strrchr(const char *str, const int ch)
{
    const char *res = NULL;
    while (*str)
        if (ch == *str++)
            res = str - 1;
    if (*str == ch)
        res = str;
    if (res)
        return res;
    return NULL;
}

const char *my_strchr(const char *str, const int ch)
{
    while (*str)
        if (ch == *str++)
            return --str;
    if (*str == ch)
        return str;
    return NULL;
}

size_t my_strcspn(const char *str1, const char *str2)
{
    int i = 0;
    while (*str1)
    {
        const char *ptr = str2;
        int res = 0;
        while (*ptr)
            res += (*str1 == *ptr++);
        if (res)
            return i;
        i++;
        str1++;
    }
    return i;
}

size_t my_strspn(const char *str1, const char *str2)
{
    int i = 0;
    while (*str1)
    {
        const char *ptr = str2;
        int res = 0;
        while (*ptr)
            res += (*str1 == *ptr++);
        if (!res)
            return i;
        i++;
        str1++;
    }
    return i;
}

const char *my_strpbrk(const char *str1, const char *str2)
{
    while (*str1)
    {
        const char *ptr = str2;
        while (*ptr)
            if (*str1 == *ptr++)
                return str1;
        str1++;
    }
    return NULL;
}

void strbrk_test(const char tests_arr[][MAX_LEN_STR], const char delims[][MAX_LEN_STR])
{
    puts("Strpbrk tests: ");
    for (int i = 0; i < COUNT_TESTS; i++)
    {
        char res = my_strpbrk(tests_arr[i], delims[i]) == strpbrk(tests_arr[i], delims[i]);
        printf("Test %d - %d\n", i + 1, res);
    }
}

void strspn_test(const char tests_arr[][MAX_LEN_STR], const char delims[][MAX_LEN_STR])
{
    puts("Strspn tests: ");
    for (int i = 0; i < COUNT_TESTS; i++)
    {
        char res = my_strspn(tests_arr[i], delims[i]) == strspn(tests_arr[i], delims[i]);
        printf("Test %d - %d\n", i + 1, res);
    }
}

void strcspn_test(const char tests_arr[][MAX_LEN_STR], const char delims[][MAX_LEN_STR])
{
    puts("Strspn tests: ");
    for (int i = 0; i < COUNT_TESTS; i++)
    {
        char res = my_strcspn(tests_arr[i], delims[i]) == strcspn(tests_arr[i], delims[i]);
        printf("Test %d - %d\n", i + 1, res);
    }
}

void strchr_test(const char tests_arr[][MAX_LEN_STR], const char symbols_code[COUNT_TESTS])
{
    puts("Strchr tests: ");
    for (int i = 0; i < COUNT_TESTS; i++)
    {
        char res = my_strchr(tests_arr[i], symbols_code[i]) == strchr(tests_arr[i], symbols_code[i]);
        printf("Test %d - %d\n", i + 1, res);
    }
}

void strrchr_test(const char tests_arr[][MAX_LEN_STR], const char symbols_code[COUNT_TESTS])
{
    puts("Strrchr tests: ");
    for (int i = 0; i < COUNT_TESTS; i++)
    {
        char res = my_strrchr(tests_arr[i], symbols_code[i]) == strrchr(tests_arr[i], symbols_code[i]);
        printf("Test %d - %d\n", i + 1, res);
    }
}

int main()
{
    const char tests_arr[COUNT_TESTS][MAX_LEN_STR] = { "this is a test", "TestData", "" };
    const char delims[COUNT_TESTS][MAX_LEN_STR] = { "th", "kj", "qw" };
    const char symbols_code[COUNT_TESTS] = { 116, 0, 36 };

    strbrk_test(tests_arr, delims);
    strspn_test(tests_arr, delims);
    strcspn_test(tests_arr, delims);
    strchr_test(tests_arr, symbols_code);
    strrchr_test(tests_arr, symbols_code);

    return 0;
}