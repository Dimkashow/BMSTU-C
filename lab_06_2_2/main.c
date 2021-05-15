#include <stdio.h>
#define MAX_LEN 257
#define OK 0
#define INPUT_ER 1
#define SIZE_ER 2
#define MAX_LEN_WORD 17
#define DIV_SIZE 8
#define TRUE 1
#define FALSE 0

int my_strcmp(const char *const string1, const char *const string2)
{
    int i = 0;
    while (string1[i])
    {
        if (string1[i] != string2[i])
            return FALSE;
        ++i;
    }
    if (string2[i] != '\0')
        return FALSE;

    return TRUE;
}

int input_str(char str[MAX_LEN])
{
    int i = 0;
    do
    {
        if (scanf("%c", &str[i]) != 1)
            return INPUT_ER;
        i++;
    } while (str[i - 1] != '\n' && i != MAX_LEN);

    if (i == MAX_LEN)
        return SIZE_ER;

    str[i - 1] = '\0';

    return OK;
}

int check_char(const char n)
{
    const char dividers[DIV_SIZE] = { ' ', ',', ';', ':', '.', '-', '!', '?' };
    for (int i = 0; i < DIV_SIZE; i++)
        if (dividers[i] == n)
            return TRUE;
    return FALSE;
}

int repeat_search(char word_str1[][MAX_LEN], const int counter, const char new_str[MAX_LEN])
{
    for (int i = 0; i < counter; i++)
    {
        if (my_strcmp(word_str1[i], new_str))
            return TRUE;
    }
    return FALSE;
}

int add_word(char new_str[MAX_LEN], int len, char word_str1[][MAX_LEN], int *counter)
{
    if (len != 0)
    {
        new_str[len] = '\0';
        if (!repeat_search(word_str1, *counter, new_str))
        {
            int j = 0;
            while (new_str[j])
            {
                word_str1[*counter][j] = new_str[j];
                j++;
            }
            word_str1[*counter][j] = new_str[j];
            ++(*counter);
        }

        for (int j = 0; j < 20; j++)
            new_str[j] = 0;
        len = 0;
    }
    return len;
}

int split_str(const char str[MAX_LEN], char word_str1[][MAX_LEN], int *counter, char new_str[MAX_LEN])
{
    int i = 0, len = 0;
    while (str[i])
    {
        if (check_char(str[i]))
            len = add_word(new_str, len, word_str1, counter);
        else
        {
            new_str[len] = str[i];
            len++;
            if (len == 17)
                return INPUT_ER;
        }
        i++;
    }
    add_word(new_str, len, word_str1, counter);

    if (*counter == 0)
        return INPUT_ER;

    return OK;
}

int check(const char str1[MAX_LEN], char matrix2[][MAX_LEN], const int words2)
{
    int res = 0;
    for (int i = 0; i < words2; i++)
        res += my_strcmp(str1, matrix2[i]);

    return res;
}

void find_result(char matrix1[][MAX_LEN], const int words1, char matrix2[][MAX_LEN], const int words2)
{
    for (int i = 0; i < words1; i++)
        if (check(matrix1[i], matrix2, words2))
            printf("%s yes\n", matrix1[i]);
        else
            printf("%s no\n", matrix1[i]);
}

int main()
{
    char str1[MAX_LEN] = { 0 };
    char str2[MAX_LEN] = { 0 };
    char new_str[MAX_LEN] = { 0 };
    char word_str1[MAX_LEN][MAX_LEN] = { 0 };
    char word_str2[MAX_LEN][MAX_LEN] = { 0 };
    int word_str1_count = 0;
    int word_str2_count = 0;

    int er_in_input = input_str(str1) + input_str(str2);
    if (er_in_input)
        return INPUT_ER;

    er_in_input = split_str(str1, word_str1, &word_str1_count, new_str);

    if (er_in_input)
        return INPUT_ER;

    er_in_input = split_str(str2, word_str2, &word_str2_count, new_str);

    if (er_in_input)
        return INPUT_ER;

    puts("Result: ");
    find_result(word_str1, word_str1_count, word_str2, word_str2_count);

    return 0;
}
