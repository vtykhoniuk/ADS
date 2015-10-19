#include "linkedlist.h"

#include <stdlib.h>
#include <stdio.h>

void free_int(void *);

int main()
{
    LinkedList list = allocte_linked_list();

    for (int i = 0; i < 10; ++i) {
        int *v = malloc(sizeof(int));
        *v = i;
        append_node_to_linked_list(list, v);
    }

    printf("List size: %ld\n", list->size);

    while (list->size) {
        void *val = remove_head_node_from_linked_list(list);
        printf("%d\n", *((int *) val));
        free(val);
    }

    destroy_linked_list(list);

    exit(EXIT_SUCCESS);
}

void free_int(void *v)
{
    free((int *) v);
}
