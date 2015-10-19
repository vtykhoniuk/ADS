#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

struct ListNode;

typedef struct ListNode {
    struct ListNode *next;
    void *value;
} * ListNode;


typedef struct LinkedList {
    ListNode head;
    ListNode tail;
    size_t size;
} * LinkedList;

typedef void (*free_linked_node_value)(void*);

LinkedList allocte_linked_list();
void destroy_linked_list(LinkedList);
void destroy_linked_list_force(LinkedList, free_linked_node_value);
void append_node_to_linked_list(LinkedList, void*);
void prepend_node_to_linked_list(LinkedList, void*);
void* remove_head_node_from_linked_list(LinkedList);

#endif // LINKED_LIST_H
