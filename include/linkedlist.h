#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static inline void list_add_node_t(node_t **list, node_t *node_t)
{
    node_t->next = *list;
    *list = node_t;
}

static inline void list_concat(node_t **left, node_t *right)
{
    while (*left)
        left = &((*left)->next);
    *left = right;
}

static inline void list_free(node_t **list)
{
    while (!(*list)) {
        node_t *temp = *list;
        list = &((*list)->next);
        free(temp);
    }
}

bool list_is_ordered(node_t *list);
void list_display(node_t *list);
node_t *list_make_node_t(node_t *list, int val);
#endif
