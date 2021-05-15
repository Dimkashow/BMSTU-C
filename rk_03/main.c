#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct list {
    char **str;
    int size;
    int aloc_size;
} word_list;

typedef struct sentence {
    char **str;
    int size;
    int aloc_size;
    int w[100];
} sentence;

typedef struct text {
    struct sentence *sentence;
    int size;
    int aloc_size;
} text;

char *input_string(FILE* f, size_t size, int *end) {
    int ch = 0;
    size_t len = 0;
    (*end) = 0;
    char *str = malloc(sizeof(char) * size);
    if (!str) return str;
    for (;;) {
        if (EOF == (ch = fgetc(f))) {
            (*end) = 2;
            break;
        }
        if (ch == '\n') {
            (*end) = 1;
            break;
        }
        if (ch == ' ')
            break;
        str[len++] = ch;
        if (len == size) {
            char *new_str = realloc(str, sizeof(char) * (size += size));
            if (!new_str) return str;
            str = new_str;
        }
    }

    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

int check_unique(word_list *list, char *str) {
    for (int i = 0; i < list->size; i++) {
        if (!strcmp(list->str[i], str))
            return 0;
    }
    return 1;
}

int comparator(const void *element1, const void *element2)
{
    return strcmp((char *)element1, (char *)element2);
}

void input_text(FILE *f, text *text, word_list *list)
{
    int end = 0;
    int len_sen = 0;
    int n_sen = 0;
    for (;;) {
        if (end == 2) {
            ++(text->size);
            break;
        }
        if (end == 1) {
            ++(text->size);
            len_sen++;
            n_sen = 0;
        }

        char *str = input_string(f, 128, &end);
        text->sentence[len_sen].str[n_sen] = str;
        ++(text->sentence[len_sen].size);
        n_sen++;

        int len = strlen(str);
        for (int i = 0; i < len; i++)
            str[i] = tolower(str[i]);

        if (list->size == list->aloc_size) {
            list->str = realloc(list->str, sizeof(char **) * (list->aloc_size + 16));
            list->aloc_size += 16;
        }
        if (!check_unique(list, str)) {
            continue;
        }
        list->str[list->size] = str;
        ++(list->size);
    }
}

void init(text *text, word_list *list)
{
    list->str = malloc(sizeof(char **) * 16);
    list->aloc_size = 16;
    list->size = 0;

    text->size = 0;
    text->sentence = malloc(sizeof(sentence) * 16);
    text->aloc_size = 16;
    for (int i = 0; i < 16; i++) {
        text->sentence[i].str = malloc(sizeof(char **) * 16);
        text->sentence[i].aloc_size = 16;
        //text->sentence[i].w = 0;
    }
}

void print_unique_word(word_list *list)
{
    for (int i = 0; i < list->size; i++)
        printf("%s ", list->str[i]);
}

void  print_all_text(text *text) {
    for (int i = 0; i < text->size; i++) {
        for (int j = 0; j < text->sentence[i].size; j++) {
            printf("%s ", text->sentence[i].str[j]);
        }
        puts("");
    }
}

void print_matrix_word(text *text, word_list *list) {
    for (int i = 0; i < text->size; i++) {
        //text->sentence[i].w = malloc(list->size);
        for (int j = 0; j < list->size; j++)
            text->sentence[i].w[j] = 0;
        for (int j = 0; j < text->sentence[i].size; j++) {
            for (int z = 0; z < list->size; z++) {
                //printf("%s %s\n", list->str[z], text->sentence[i].str[j]);
                if (!strcmp(list->str[z], text->sentence[i].str[j]))
                    text->sentence[i].w[z] = 1;
            }
        }
        for (int j = 0; j < list->size; j++)
            printf("%d ", text->sentence[i].w[j]);
        puts("");
    }
}

int main(int argc, char *argv[]) {
    //printf("%s", argv[1]);
    FILE *f = fopen("test.txt", "r");
    word_list *list = malloc(sizeof(word_list));
    text *text = malloc(sizeof(struct text));

    init(text, list);

    input_text(f, text, list);

    qsort(list->str, list->size, sizeof(char *), comparator);

    print_unique_word(list);
    puts("");
    print_all_text(text);
    puts("");
    print_matrix_word(text, list);

    return 0;
}