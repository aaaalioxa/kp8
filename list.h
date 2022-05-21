#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct item {
    struct item *next;
    struct item *prev;
    char data[100];
} item;

typedef struct Iterator {
    struct item* node;
} iterator;

typedef struct list {
    struct item* head;
    int size;
} list;

int RInput(char *str, int op);
iterator Next(iterator* i);
iterator Prev(iterator* i);
iterator First(list* l);
iterator Last(list* l);
list* Create();
iterator Insert(list* l, iterator* i, char* t);
iterator Delete(list* l, iterator* i);
iterator Find(list* l, char* t);
void PrintList(list* l);
iterator AddFirstElement(list* l, char* t);
iterator Swap (list* l, int k);

#endif