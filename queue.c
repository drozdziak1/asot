#include <stdlib.h> // malloc()
#include <stdbool.h>

#include "queue.h" // q_node, Q
#include "die.h"   // die()

void q_enq(Queue* Q, int val)
{
    // Exit gracefully on error
    if (Q == NULL)
        die("q_enq: Q is NULL");
    if ((Q->head == NULL) != (Q->tail == NULL))
        die("q_deq: Q's emptiness is ambigious "
            "(head or tail is exclusively NULL)");

    q_node* new_tail = malloc(sizeof(q_node));
    new_tail->val = val;
    new_tail->next = NULL;

    // Resolve Q's emptiness
    if (Q->tail != NULL)
        Q->tail->next = new_tail;
    else
        Q->head = new_tail;

    Q->tail = new_tail;
}

int q_deq(Queue* Q)
{
    // Exit gracefully on error
    if (Q == NULL)
        die("q_deq: Q is NULL");
    if (Q->head == NULL)
        die("q_deq: Nothing to dequeue");
    if ((Q->head == NULL) != (Q->tail == NULL))
        die("q_deq: Q's emptiness is ambigious "
            "(head or tail is exclusively NULL)");

    q_node* dead_head = Q->head;
    int ret;

    if (Q->head == Q->tail)
        Q->tail = NULL;

    Q->head = dead_head->next; // Pop the old head,
    ret = dead_head->val;      // save its val
    free(dead_head);           // and free its node

    return ret;
}

int q_size(Queue* Q)
{
    // Exit gracefully on error
    if (Q == NULL)
        die("q_size: Q is NULL");
    if ((Q->head == NULL) != (Q->tail == NULL))
        die("q_size: Q's emptiness is ambigious "
            "(head or tail is exclusively NULL)");

    int size;
    q_node* cur_node = Q->head;

    for (size = 0; cur_node != NULL; size++)
        cur_node = cur_node->next;

    return size;
}
