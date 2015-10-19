#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "linkedlist.h"

#define LinkedStack LinkedList
#define allocte_linked_stack allocte_linked_list
#define destroy_linked_stack destroy_linked_list
#define destroy_linked_stack_force destroy_linked_list_force
#define linked_stack_push prepend_node_to_linked_list
#define linked_stack_pop remove_head_node_from_linked_list

#endif // LINKEDSTACK_H
