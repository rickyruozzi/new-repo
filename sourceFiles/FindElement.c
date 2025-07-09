#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int findIndex(int *arr, int element){
    for(int i=0;i<10;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int main(){
    srand(time(NULL));
    int *arr=(int* )malloc(10*sizeof(int));
    for(int i=0; i<10; i++){
        int r = 0 + rand() % (20 - 0 + 1);
        arr[i]=r;
    }
    int elem;
    printf("Quale elemento vuoi cercare?\n"); 
    fflush(stdout); 
    scanf("%d",&elem);
    int index=findIndex(arr,elem);
    if(index==-1){
        printf("valore non presente");
    }
    else{
        printf("prima ricorrenza del valore all'indice %d",index);
    }
}