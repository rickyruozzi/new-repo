#include "../header/ruoli.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
int highestAVG(studente*, int);
int lowestAVG(studente*, int);
int main(){
    int sizeOfClass;
    printf("Inserire il numero di studenti nella classe:\n");
    fflush(stdout);  
    scanf("%d",&sizeOfClass);
    studente *classe=(studente *)malloc(sizeof(studente)*sizeOfClass);
    int i=0;
    while(i<sizeOfClass){
        printf("inserisci il nome dello studente: \n");
        fflush(stdout); 
        scanf("%s",classe[i].nome);
        printf("inserisci il cognome dello studente: \n");
        fflush(stdout); 
        scanf("%s",classe[i].cognome);
        printf("inserisci l'anno di appartenenza dello studente: \n");
        fflush(stdout); 
        scanf("%d",&classe[i].anno);
        printf("inserisci la media dello studente: \n");
        fflush(stdout); 
        scanf("%f",&classe[i].media);
        i=i+1;
    }
    for(int i=0;i<sizeOfClass;i++){
        printf("nome: %s\n",classe[i].nome);
        printf("cognome: %s\n",classe[i].cognome);
        printf("anno: %d\n",classe[i].anno);
        printf("media: %f\n",classe[i].media);
    }
    int IndHighestAverage=highestAVG(classe, sizeOfClass);
    printf("La media più alta è quella di %s che ha una media di %f\n",classe[IndHighestAverage].nome, classe[IndHighestAverage].media);
    int IndLowestAverage=lowestAVG(classe, sizeOfClass);
    printf("La media più bassa è quella di %s che ha una media di %f\n",classe[IndLowestAverage].nome, classe[IndLowestAverage].media);
    free(classe);
    return 0;
}
int highestAVG(studente* classe, int size){
    float max=0;
    int index=-1;
    for(int i=0; i<size;i++){
        if(classe[i].media>max){
            max=classe[i].media;
            index=i;
        }
    }
    return index;
}

int lowestAVG(studente* classe, int size){
    float min=FLT_MAX;
    int index=-1;
    for(int i=0; i<size;i++){
        if(classe[i].media<min){
            min=classe[i].media;
            index=i;
        }
    }
    return index;
}