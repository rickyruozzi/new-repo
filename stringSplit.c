#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int stringSplit(char *s, int *array){
    char sep=' ';
    char *str=malloc(100*sizeof(char));
    int count=0;
    while(sep!='\0'){
        scanf("%s%c",str,&sep);
        int elemento=atoi(str);
        count=count+1;
        int* temp=realloc(array, (count)*sizeof(int));
        temp[count-1]=elemento;
        array=temp;
    }
}
int main(){
    char Stringa[]="1,2,3,4,5,-6,-7";
    int *array=malloc(sizeof(int));
    stringSplit(Stringa,array);
    int dimensione=sizeof(array)/sizeof(int);
    for(int i=0; i<dimensione; i++){
        printf("Elemento: %d",array[i]);
    }
    return 0;
}