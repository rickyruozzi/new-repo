#ifndef HEAP_H
#define HEAP_H
#define MAX_CAPACITY 20
typedef struct MinHeap{
    int array[MAX_CAPACITY];
    int size;
} MinHeap;
void initHeap(MinHeap* heap);
void insert(MinHeap* heap, int value);
int extractMin(MinHeap* heap);
int getMin(MinHeap* heap);
void printHeapDFS(MinHeap* heap, int i);
void printHeapBFS(MinHeap* heap);
#endif