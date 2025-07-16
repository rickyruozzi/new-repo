#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, node* value) {
    if (value == NULL) return;  // evita di inserire NULL

    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        fprintf(stderr, "Errore di allocazione in enqueue\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }

    QueueNode* temp = q->front;
    node* value = temp->value;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}
