#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct Node
{
    char value[10];
    struct Node *next;
    struct Node *prev; 
} Node;

typedef struct List
{
    size_t size;
    Node *head;
    Node *tail;
} List;

List* createList()
{
    List *tmp = (List*)malloc(sizeof(List));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}

void freeList(List **list)
{
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushFront(List *list, char data[10])
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL)
    {
        return;
    }
    strncpy(tmp->value, data, 10); 
    
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head)
    {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL)
    {
        list->tail = tmp;
    }
    list->size++;
}

Node* getNth(List *list, size_t index)
{
    Node *tmp = list->head;
    size_t i = 0;
 
    while (tmp && i < index)
    {
        tmp = tmp->next;
        i++;
    }
 
    return tmp;
}

void swap_word(List *list)
{
    Node *head = list->head;
    while (list->head)
    {
        int n = 0;
        char tmp[10] = { '\0' };
        for (int i = strlen(list->head->value) - 1; i >= 0; i--)
            tmp[n++] = list->head->value[i];
        strcpy(list->head->value, tmp);
        list->head = list->head->next;
    }
    list->head = head;
}

int main(int argc, char* argv[])
{
    FILE *from = fopen(argv[1], "r");
    if (!from)
        return 1;
    FILE *to = fopen("out.txt", "w+");
    if (!to)
    {
        fclose(from);
        return 1;
    }	
    char buff[10];
    List *list = createList();
    if (!list)
    {
        fclose(from);
        fclose(to);
        return 1;
    }
    while (fscanf(from, "%s", buff) == 1)
        pushFront(list, buff);

    Node *head = list->head;

    swap_word(list);

    for (int i =  0; i < list->size; i++)
    {
        Node *word = getNth(list, i);
        fprintf(to, "%s\n", word->value);
    }

    freeList(&list);
    fclose(from);
    fclose(to);

    return 0;
}