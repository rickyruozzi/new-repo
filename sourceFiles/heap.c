#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../header/heap.h"
/**
 * @brief inizializzazione dell'array
 * 
 * @param heap 
 */
void initHeap(MinHeap* heap) {
    heap->size = 0;
}
/**
 * @brief trova padre
 * 
 * @param index 
 * @return int 
 */
int father(int index){
    return (index - 1) / 2;
}

/**
 * @brief trova figlio sinistro
 * 
 * @param index 
 * @return int 
 */
int leftson(int index){return 2*index+1;}

/**
 * @brief trova figlio destro
 * 
 * @param index 
 * @return int 
 */
int rightson(int index){return 2*index+2;}

/**
 * @brief inverti elementi tramite puntatori
 * 
 * @param a 
 * @param b 
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief riordiniamo l'heap dal basso
 * 
 * @param heap 
 * @param index 
 */
void heapifyUp(MinHeap* heap, int index){
    bool Bloccato=false;
    while(index>0 && Bloccato==false){
        if(heap->array[index]<heap->array[father(index)]){
            swap(&heap->array[index], &heap->array[father(index)]);
            index=father(index);
        }
        else{
            Bloccato=true;
        }
    }
}

/**
 * @brief riordiniamo l'heap dall'alto
 * 
 * @param heap 
 * @param index 
 */
void heapifyDown(MinHeap* heap, int index){
    bool Bloccato=false;
    while(index<(heap->size) && Bloccato==false){
       int minimum=index;
       int left=leftson(index);
       int right=rightson(index);
       if(left<(heap->size) && heap->array[left]<heap->array[index]){
        minimum=left;
       }
       if(right<(heap->size) && heap->array[right]<heap->array[minimum]){
        minimum=right;
       }
       if(minimum!=index){
        swap(heap->array[index],heap->array[minimum]);
        index=minimum;
       }
       else{
        Bloccato=true;
       }
    }
}

/**
 * @brief estrae e restituisce il minimum
 * 
 * @param heap 
 * @return int 
 */
int extractMin(MinHeap* heap){
    if(heap->size==0){return -1;}
    int minimum=heap->array[0];
    heap->array[0]=heap->array[heap->size-1];
    heap->size--;
    heapifyDown(heap,0);
    return minimum;
}

/**
 * @brief restituisce il valore minimo
 * 
 * @param heap 
 * @return int 
 */
int getMin(MinHeap* heap){
    return heap->array[0];
}

/**
 * @brief stampa l'heap tramite BFS
 * 
 * @param heap 
 */
void printHeapBFS(MinHeap* heap){
    for(int i=0;i<heap->size;i++){
        printf("%d ", heap->array[i]);
    }
}

/**
 * @brief stampa l'heap tramite DFS
 * 
 * @param heap 
 * @param i 
 */
void printHeapDFS(MinHeap* heap, int i){
    printf("%d ", heap->array[i]);
    if(1*2+1<heap->size){printHeapDFS(heap,leftson(i));}
    if(1*2+2<heap->size){printHeapDFS(heap,rightson(i));}
}

/**
 * @brief inserisce un elemento in fondo al'array e richiama heapify per riordinare l'heap
 * 
 * @param heap 
 * @param value 
 */
void insert(MinHeap* heap, int value){
    if(heap->size==MAX_CAPACITY){
        printf("L'arra è pieno");
    }else{
        heap->array[heap->size]=value;
        heap->size++;
        heapifyUp(heap, heap->size-1);
    }
}

/**
 * @brief heap sort
 * 
 * @param heap 
 * @return int* 
 */
int* heapSort(MinHeap* heap){
    int* sortedArray = (int*)malloc(heap->size * sizeof(int));
    int i=0;
    int dimensione=heap->size;
    while(i<dimensione){
        sortedArray[i]=extractMin(heap);
        i++;
    }
    return sortedArray;
}

int main(){}