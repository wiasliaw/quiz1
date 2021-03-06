#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

bool list_is_ordered(node_t *list)
{
    bool first = true;
    int value;
    while (list) {
        if (first) {
            value = list->value;
            first = false;
        } else {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}

void list_display(node_t *list)
{
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

node_t *list_make_node_t(node_t *list, int val)
{
    node_t *n = (node_t*)malloc(sizeof(node_t));
    n->value = val;
    n->next = NULL;
    list_add_node_t(&list, n);
    return list;
}
