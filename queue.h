#ifndef QUEUE_H
#define QUEUE_H

// A simple implementation of a dynamic queue

typedef struct Q_NODE {
    int val;
    struct Q_NODE* next;
} q_node;

typedef struct QUEUE {
    q_node* head;
} Queue;

void q_enq(Queue* Q, int val); // Enqueue
int q_deq(Queue* Q);           // Dequeue
int q_size(Queue* Q);          // Determine Q's size
#endif
