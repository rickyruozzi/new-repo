#ifndef QUEUE_H
#define QUEUE_H

typedef struct node node;  // forward declaration

typedef struct QueueNode {
    node* value;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, node* value);
node* dequeue(Queue* q);

#endif
