#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int RInput(char *str, int op) {
    char *str1 = str;
    bool f = 1;
    while (*str) {
        if (*str < '0' || *str >'9')
            f = 0;
        if (*str == '-')
            f = 1;
        str++;
    }
    if (f)
        return atoi(str1);
    else {
        if (op == 0) {
            printf("Wrong input, try again\n");
            printf("Enter option: ");
        }
        else {
            printf("Wrong input, try again\n");
            printf("Enter value: ");
        }
        return -1;
    }
}


iterator Next(iterator *i) {
    iterator j = {i->node->next};
    return j;
}

iterator Prev(iterator *i) {
    iterator j = {i->node->prev};
    return j;
}

iterator First(list *l) {
    iterator i = {l->head};
    return i;
}

iterator Last(list *l) {
    iterator temp;
    iterator i = {l->head};
    for (int j = 0; j < l->size; j++) {
        temp = i;
        i = Next(&i);
    }
    return temp;
}

list *Create() {
    list * l = (list *) malloc(sizeof(list));
    l->head = NULL;
    l->size = 0;
    return l;
}

iterator Insert(list * l, iterator * i, char * t) {
    iterator new = {(struct item *)malloc(sizeof(struct item))};
    strcpy(new.node->data, t);
    l->size++;
    i->node->next->prev = new.node;
    new.node->next = i->node->next;
    new.node->prev = i->node;
    i->node->next = new.node;
    First(l).node->prev = Last(l).node;
    return new;
}

iterator Delete(list *l, iterator *i) {
    if (i->node == l->head) {
        struct item *tmp = l->head->next;
        free(i->node);
        l->head = tmp;
        Last(l).node->next = tmp;
        l->head->prev = Last(l).node;
        iterator res = {l->head};
        l->size--;
        return res;
    }
    iterator p = Prev(i);
    p.node->next = i->node->next;
    Next(i).node->prev = p.node->next;
    free(i->node);
    l->size--;
    return p;
}

void PrintList(list *l) {
    iterator i = First(l);
    for(int j = 0; j < l->size; j++) {
        if (j != l->size - 1)
            printf("%s <-> ", i.node->data);
        else
            printf("%s\n", i.node->data);
        i = Next(&i);
    }
}

iterator AddFirstElement(list * l, char *t) {
    iterator new = {(struct item *)malloc(sizeof(struct item))};
    strcpy(new.node->data, t);
    l->size++;
    l->head = new.node;
    new.node->next = new.node;
    new.node->prev = new.node;
    return new;
}

iterator Find(list * l, char * t) {
    iterator res = {NULL};
    iterator i = First(l);
    for (int j = 0; j < l->size; j++) {
        if (strcmp(i.node->data, t) == 0) {
            res = i;
            break;
        }
        i = Next(&i);
    }
    return res;
}

iterator Swap(list * l, int k) {
    iterator j = First(l);
    iterator midElement;
    for (int i = 0; i < l->size; i++) {
        if (i == k)
            midElement = j;
        j = Next(&j);
    }
    iterator p = Prev(&midElement);
    iterator n = Next(&midElement);
    if (n.node == Last(l).node && p.node == l->head){
        midElement.node->next = p.node;
        midElement.node->prev = n.node;
        n.node->next = midElement.node;
        n.node->prev = p.node->prev;
        p.node->next = n.node;
        p.node->prev = midElement.node;
        l->head = n.node;
        return midElement;
    }
    if (p.node == l->head) {
        struct item * tmpNext = n.node->next;
        midElement.node->next = p.node;
        midElement.node->prev = n.node;
        n.node->next = midElement.node;
        n.node->prev = Last(l).node;
        Last(l).node->next = p.node;
        p.node->next = tmpNext;
        p.node->prev = midElement.node;
        l->head = n.node;
        return midElement;
    }
    if (n.node == Last(l).node) {
        struct item * tmpPrev = Prev(&p).node;
        midElement.node->next = p.node;
        midElement.node->prev = n.node;
        n.node->next = midElement.node;
        n.node->prev = tmpPrev;
        tmpPrev->next = n.node;
        p.node->next = l->head;
        l->head->prev = p.node;
        p.node->prev = midElement.node;
        return midElement;
    }
    struct item * tmpPrev = Prev(&p).node;
    struct item * tmpNext = n.node->next;
    midElement.node->next = p.node;
    midElement.node->prev = n.node;
    n.node->next = midElement.node;
    n.node->prev = tmpPrev;
    tmpPrev->next = n.node;
    p.node->next = tmpNext;
    p.node->prev = midElement.node;
    tmpNext->prev = p.node;
    return midElement;
}

