#include "linkedstack.h"

#include <stdlib.h>
#include <stdio.h>

void free_int(void *);

int main()
{
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();

    for (int i = 0; i < 10; ++i) {
        int *v = malloc(sizeof(int));
        *v = i;
        ADS_LinkedStack_push(stack, v);
    }

    printf("Stack size: %ld\n", stack->size);

    while (stack->size) {
        void *val = ADS_LinkedStack_pop(stack);
        printf("%d\n", *((int *) val));
        free(val);
    }

    ADS_LinkedStack_destroy(stack);

    exit(EXIT_SUCCESS);
}

void free_int(void *v)
{
    free((int *) v);
}
