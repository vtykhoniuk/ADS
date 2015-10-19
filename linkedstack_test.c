#include "linkedstack.h"

#include <stdlib.h>
#include <stdio.h>

void free_int(void *);

int main()
{
    LinkedStack stack = allocte_linked_stack();

    for (int i = 0; i < 10; ++i) {
        int *v = malloc(sizeof(int));
        *v = i;
        linked_stack_push(stack, v);
    }

    printf("Stack size: %ld\n", stack->size);

    while (stack->size) {
        void *val = linked_stack_pop(stack);
        printf("%d\n", *((int *) val));
        free(val);
    }

    destroy_linked_stack(stack);

    exit(EXIT_SUCCESS);
}

void free_int(void *v)
{
    free((int *) v);
}
