#include "linkedlist.h"

#include <stdlib.h>

LinkedList allocte_linked_list()
{
    LinkedList list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void destroy_linked_list(LinkedList list)
{
    ListNode node = list->head;

    while (node) {
        ListNode tmp = node->next;
        free(node);
        node = tmp;
    }

    free(list);
}

void destroy_linked_list_force(LinkedList list, free_linked_node_value f)
{
    ListNode current = list->head;

    while (current) {
        ListNode next = current->next;
        f(current->value);
        free(current);
        current = next;
    }

    free(list);
}

void append_node_to_linked_list(LinkedList list, void *value)
{
    ListNode node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->value = value;

    if (list->tail) {
        list->tail->next = node;
        list->tail = node;
    } else
        list->head = list->tail = node;

    list->size++;
}

void prepend_node_to_linked_list(LinkedList list, void *value)
{
    ListNode node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->value = value;

    if (list->size) {
        node->next = list->head;
        list->head = node;
    } else
        list->head = list->tail = node;

    list->size++;
}

void* remove_head_node_from_linked_list(LinkedList list)
{
    if (!list->head)
        return NULL;

    ListNode next = list->head->next;
    void *val = list->head->value;
    free(list->head);
    list->head = next;

    list->size--;

    return val;
}
