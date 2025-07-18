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

void stampa_studenti(const Studente studenti[], int n){
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", studenti[i].nome, studenti[i].età);
    }
}

void aggiungi_studente(Studente studenti[], int* n) {
    if (*n >= 25) {
        printf("Numero massimo di studenti raggiunto.\n");
        return;
    }

    Studente nuovo;
    printf("Nome completo: ");
    fgets(nuovo.nome, MAX_L, stdin);
    nuovo.nome[strcspn(nuovo.nome, "\n")] = 0; // Rimuove newline

    printf("Età: ");
    scanf("%d", &nuovo.età);
    getchar(); // pulizia newline
    studenti[*n] = nuovo;
    (*n)++;

    printf("Studente aggiunto con successo.\n");
}

int salva_studenti(const char* filename, Studente studenti[], int n){
    FILE* file = fopen('../studenti.txt', "r");
    if (!file) {
        printf("Errore nell'apertura del file per scrittura.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%d\n", studenti[i].nome, studenti[i].età);
    }
    fclose(file);
    return 1;
}

int main(){}