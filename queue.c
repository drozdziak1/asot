#include <stdlib.h> // malloc()

#include "queue.h" // q_node, Q
#include "die.h"   // die()

void q_enq(Queue* Q, int val)
{
    // Exit gracefully on error
    if (Q == NULL)
        die("q_enq: Q is null");

    q_node *cur_node, *prev;

    // malloc the new node and give it val value
    q_node* new_tail = malloc(sizeof(q_node));

    new_tail->val = val;
    new_tail->next = NULL;

    if (Q->head == NULL)
        Q->head = new_tail;
    else {

        cur_node = Q->head;

        // Reach Q's tail and append new_tail
        while (cur_node != NULL) {
            prev = cur_node;
            cur_node = cur_node->next;
        }
        prev->next = new_tail;
    }
}

int q_deq(Queue* Q)
{
    // Exit gracefully on error
    if (Q == NULL)
        die("q_enq: Q is null");
    if (Q->head == NULL)
        die("q_deq: Nothing to dequeue");

    q_node* dead_head = Q->head;

    Q->head = dead_head->next; // Pop the old head,
    int ret = dead_head->val;  // save its val
    free(dead_head);           // and free its node

    return ret;
}

int q_size(Queue* Q)
{
    int size = 0;

    q_node* cur_node = Q->head;

    while (cur_node != NULL) {
        cur_node = cur_node->next;
        size++;
    }

    return size;
}
