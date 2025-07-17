#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/FileFunctions.h"

int carica_studenti(const char* filename, Studente studenti[], int max){
    FILE* file = fopen('../studenti.txt', "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
        return 0;
    }
    int riga[50];
    int count=0;
    while(fgets(riga, sizeof(riga), file && count<max)){
        char nome[MAX_L];
        int età;
        if(sscanf(riga, "%49[^,],%d", nome, età)){
            strcpy(studenti[count].nome, nome);
            studenti[count].età = età;
            count++;
        }
    }
    fclose(file);
}

int main(){}