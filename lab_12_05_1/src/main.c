#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_PART 4

typedef struct node
{
    char chunk[LEN_PART];
    struct node *next_node;
} node_t;

int read_list(node_t *head)
{
    char buff[LEN_PART] = { '\0' };
    char c;
    int now_str_size = 0;
    int start = 1;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        start = 0;
        if (now_str_size == LEN_PART)
        {
            node_t *next = malloc(sizeof(node_t));
            next->next_node = NULL;

            strncpy(head->chunk, buff, LEN_PART);
            head->next_node = next;

            head = next;
            now_str_size = 0;
        }
        buff[now_str_size] = c;
        now_str_size++;
    }
    for (int i = now_str_size; i < LEN_PART; i++)
        buff[now_str_size] = '\0';
    strncpy(head->chunk, buff, LEN_PART);
    return start;
}

void print_list(node_t *node)
{
    while (node->next_node != NULL)
    {
        for (int i = 0; i < LEN_PART; i++)
            if (node->chunk[i] != '\0')
                fprintf(stdout, "%c", node->chunk[i]);
        node = node->next_node;
    }
    for (int i = 0; i < LEN_PART; i++)
        if (node->chunk[i] != '\0')
            fprintf(stdout, "%c", node->chunk[i]);
}

void without_space(node_t *node)
{
    int c = '\0';
    while (node->next_node != NULL)
    {
        for (int i = 0; i < LEN_PART; i++)
        {
            if (!(c == ' ' && node->chunk[i] == ' ') && node->chunk[i] != '\0')
            {
                fprintf(stdout, "%c", node->chunk[i]);
            }
            c = node->chunk[i];
        }
        node = node->next_node;
    }
    for (int i = 0; i < LEN_PART; i++)
    {
        if (!(c == ' ' && node->chunk[i] == ' ') && node->chunk[i] != '\0')
        {
            fprintf(stdout, "%c", node->chunk[i]);
        }
        c = node->chunk[i];
    }
}

void free_list(node_t *node)
{
    while (node->next_node != NULL)
    {
        node_t *next = node;
        node = node->next_node;
        free(next);
    }
    free(node);
}

int check_sub(node_t *node, int j, char find[100])
{
    int need = strlen(find);
    int count = 0;
    for (int i = j; i < LEN_PART; i++)
    {
        if (count == need)
            return 1;
        else if (find[count] == node->chunk[i])
            count++;
        else
            return 0;
    }
    if (count == need)
        return 1;
    if (node->next_node == NULL)
        return 0;
    node = node->next_node;
    while (node->next_node != NULL)
    {
        for (int i = 0; i < LEN_PART; i++)
        {
            if (count == need)
                return 1;
            else if (find[count] == node->chunk[i])
                count++;
            else
                return 0;
        }
        node = node->next_node;
    }
    for (int i = 0; i < LEN_PART; i++)
    {
        if (count == need)
            return 1;
        else if (find[count] == node->chunk[i])
            count++;
        else
            return 0;
    }
    return 0;
}

int find_str(node_t *node, char find[100])
{
    int count = 0;
    while (node->next_node != NULL)
    {
        for (int i = 0; i < LEN_PART; i++)
        {
            if (find[0] == node->chunk[i] && check_sub(node, i, find))
                return count;
            count++;
        }
        node = node->next_node;
    }
    for (int i = 0; i < LEN_PART; i++)
    {
        if (find[0] == node->chunk[i] && check_sub(node, i, find))
            return count;
        count++;
    }

    return -1;
}

int main()
{
    node_t *list = malloc(sizeof(node_t));
    for (int i = 0; i < LEN_PART; i++)
        list->chunk[i] = '\0';
    list->next_node = NULL;

    char choose[LEN_PART];

    if (fscanf(stdin, "%s", choose) != 1)
    {
        free_list(list);
        return 1;
    }

    getchar();

    if (read_list(list))
    {
        free_list(list);
        return 1;
    }

    if (!strcmp(choose, "out"))
        print_list(list);
    else if (!strcmp(choose, "cat"))
    {
        node_t *new_list = malloc(sizeof(node_t));
        for (int i = 0; i < LEN_PART; i++)
            new_list->chunk[i] = '\0';
        new_list->next_node = NULL;
        if (read_list(new_list))
        {
            free_list(new_list);
            free_list(list);
            return 1;
        }
        print_list(list);
        print_list(new_list);
        free_list(new_list);
    }
    else if (!strcmp(choose, "sps"))
    {
        without_space(list);
    }
    else if (!strcmp(choose, "pos"))
    {
        char find[100] = { '\0' };
        if (fscanf(stdin, "%s", find) != 1)
        {
            free_list(list);
            return 1;
        }
        fprintf(stdout, "%d", find_str(list, find));
    }
    else
    {
        free_list(list);
        return 1;
    }

    free_list(list);
    return 0;
}
