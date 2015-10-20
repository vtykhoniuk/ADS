#include "linkedlist.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void free_int(void *);
void allocate_list();
void append_to_empty_list();
void prepend_to_empty_list();
void append_to_nonempty_list();
void prepend_to_nonempty_list();
void remove_head_from_empty_list();
void remove_head_from_onenode_list();
void remove_head_from_multinode_list();
void remove_all_elements_from_list_deep();
void remove_all_elements_from_list_deep_using_remove_head();

int main()
{
    allocate_list();
    append_to_empty_list();
    prepend_to_empty_list();
    append_to_nonempty_list();
    prepend_to_nonempty_list();
    remove_head_from_empty_list();
    remove_head_from_onenode_list();
    remove_head_from_multinode_list();
    remove_all_elements_from_list_deep();
    remove_all_elements_from_list_deep_using_remove_head();

    exit(EXIT_SUCCESS);
}

void free_int(void *v)
{
    free((int *) v);
}

void allocate_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    assert(list->size == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    ADS_LinkedList_destroy(list);
}

void append_to_empty_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int i = 1;

    ADS_LinkedList_append_node(list, &i);
    assert(list->size == 1);
    assert(list->head->value == &i);
    assert(list->head == list->tail);

    ADS_LinkedList_destroy(list);
}

void prepend_to_empty_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int i = 1;

    ADS_LinkedList_prepend_node(list, &i);
    assert(list->size == 1);
    assert(list->head->value == &i);
    assert(list->head == list->tail);

    ADS_LinkedList_destroy(list);
}

void append_to_nonempty_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int i = 1, j = 2;

    ADS_LinkedList_append_node(list, &i);
    ADS_LinkedList_append_node(list, &j);

    assert(list->size == 2);
    assert(list->head->value == &i);
    assert(list->tail->value == &j);
    assert(list->head->next == list->tail);

    ADS_LinkedList_destroy(list);
}

void prepend_to_nonempty_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int i = 1, j = 2;

    ADS_LinkedList_prepend_node(list, &i);
    ADS_LinkedList_prepend_node(list, &j);

    assert(list->size == 2);
    assert(list->head->value == &j);
    assert(list->tail->value == &i);
    assert(list->head->next == list->tail);

    ADS_LinkedList_destroy(list);
}

void remove_head_from_empty_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();

    void *v = ADS_LinkedList_remove_head(list);
    assert(v == NULL);
    assert(list->size == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    ADS_LinkedList_destroy(list);
}

void remove_head_from_onenode_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int i = 1;

    ADS_LinkedList_append_node(list, &i);
    void *v = ADS_LinkedList_remove_head(list);
    assert(list->size == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(v == &i);

    ADS_LinkedList_destroy(list);
}

void remove_head_from_multinode_list()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int i = 1, j = 2;

    ADS_LinkedList_append_node(list, &i);
    ADS_LinkedList_append_node(list, &j);

    void *v = ADS_LinkedList_remove_head(list);
    assert(v == &i);
    assert(list->size == 1);
    assert(list->head == list->tail);

    ADS_LinkedList_destroy(list);
}

void remove_all_elements_from_list_deep()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int *i = malloc(sizeof(int));
    int *j = malloc(sizeof(int));

    ADS_LinkedList_append_node(list, i);
    ADS_LinkedList_append_node(list, j);

    ADS_LinkedList_destroy_deep(list, free_int);
}

void remove_all_elements_from_list_deep_using_remove_head()
{
    printf("%s\n", __func__);
    ADS_LinkedList list = ADS_LinkedList_allocate();
    int *i = malloc(sizeof(int));
    int *j = malloc(sizeof(int));

    ADS_LinkedList_append_node(list, i);
    ADS_LinkedList_append_node(list, j);

    ADS_LinkedList_remove_head_deep(list, free_int);
    ADS_LinkedList_remove_head_deep(list, free_int);

    ADS_LinkedList_destroy(list);
}
