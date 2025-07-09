#include <stdio.h>
#include <stdlib.h>
void reverseArray(int *src, int *dst){
    for(int i=0; i<10;i++){
        dst[10-i]=src[i];
    }
}

int main(){
    int *src = (int *)malloc(10 * sizeof(int));
    int *dst = (int *)malloc(10 * sizeof(int));
    for(int i=0;i<10;i++){
        src[i]=i;
    }
    reverseArray(src, dst);
    for(int i=0;i<10;i++){
        printf("il valore in posizione %d dell'array invertito è %d \n",i,dst[i]);
    }
}