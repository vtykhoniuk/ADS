#include "linkedlist.h"

#include <stdlib.h>
#include <stdio.h>

void free_int(void *);

int main()
{
    ADS_LinkedList list = ADS_LinkedList_allocate();

    for (int i = 0; i < 10; ++i) {
        int *v = malloc(sizeof(int));
        *v = i;
        ADS_LinkedList_append_node(list, v);
    }

    printf("List size: %ld\n", list->size);

    while (list->size) {
        void *val = ADS_LinkedList_remove_head(list);
        printf("%d\n", *((int *) val));
        free(val);
    }

    ADS_LinkedList_destroy(list);

    exit(EXIT_SUCCESS);
}

void free_int(void *v)
{
    free((int *) v);
}
