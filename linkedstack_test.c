#include "ADS/linkedstack.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void free_int(void *);
void push_to_empty_stack();
void push_two_elements_on_stack();
void pop_from_empty_stack();
void pop_from_one_element_stack();
void pop_from_two_elements_stack();
void pop_from_two_elements_stack_deep();

int main()
{
    push_to_empty_stack();
    push_two_elements_on_stack();
    pop_from_empty_stack();
    pop_from_one_element_stack();
    pop_from_two_elements_stack();
    pop_from_two_elements_stack_deep();

    exit(EXIT_SUCCESS);
}

void free_int(void *v)
{
    free((int *) v);
}

void push_to_empty_stack()
{
    printf("%s\n", __func__);
    char c = 'c';
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();

    ADS_LinkedStack_push(stack, &c);
    assert(stack->head == stack->tail);
    assert(stack->size == 1);
    assert(stack->head->value == &c);

    ADS_LinkedStack_destroy(stack);
}

void push_two_elements_on_stack()
{
    printf("%s\n", __func__);
    char a = 'a', b = 'b';
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();

    ADS_LinkedStack_push(stack, &a);
    ADS_LinkedStack_push(stack, &b);

    assert(stack->size == 2);
    assert(stack->head->value == &b);
    assert(stack->tail->value == &a);

    ADS_LinkedStack_destroy(stack);
}

void pop_from_empty_stack()
{
    printf("%s\n", __func__);
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();

    void *v = ADS_LinkedStack_pop(stack);
    assert(stack->size == 0);
    assert(v == NULL);

    ADS_LinkedStack_destroy(stack);
}

void pop_from_one_element_stack()
{
    printf("%s\n", __func__);
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();
    char a = 'a';

    ADS_LinkedStack_push(stack, &a);
    void *v = ADS_LinkedStack_pop(stack);
    assert(stack->size == 0);
    assert(stack->head == stack->tail);
    assert(stack->head == NULL);
    assert(v == &a);

    ADS_LinkedStack_destroy(stack);
}

void pop_from_two_elements_stack()
{
    printf("%s\n", __func__);
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();
    char a = 'a', b = 'b';

    ADS_LinkedStack_push(stack, &a);
    ADS_LinkedStack_push(stack, &b);

    void *v = ADS_LinkedStack_pop(stack);
    assert(stack->size == 1);
    assert(v == &b);

    v = ADS_LinkedStack_pop(stack);
    assert(stack->size == 0);
    assert(v == &a);

    ADS_LinkedStack_destroy(stack);
}

void pop_from_two_elements_stack_deep()
{
    printf("%s\n", __func__);
    ADS_LinkedStack stack = ADS_LinkedStack_allocate();
    int *i = malloc(sizeof(int));
    int *j = malloc(sizeof(int));

    ADS_LinkedStack_push(stack, i);
    ADS_LinkedStack_push(stack, j);

    ADS_LinkedStack_pop_deep(stack, free_int);
    ADS_LinkedStack_pop_deep(stack, free_int);

    ADS_LinkedStack_destroy(stack);
}
