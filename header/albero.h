#ifndef ALBERO_H
#define ALBERO_H

#define MAX_LEN 100

typedef struct node {
    int value;
    struct node* leftSon;
    struct node* rightSon;
} node;

#endif
