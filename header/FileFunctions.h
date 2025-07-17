#ifndef FILE_H
#define FILE_H
#define MAX_L 50
typedef struct {
    char nome[MAX_L];
    int età;
} Studente;

int carica_studenti(const char* filename, Studente studenti[], int max);
void stampa_studenti(const Studente studenti[], int n);
void aggiungi_studente(Studente studenti[], int* n);
int salva_studenti(const char* filename, Studente studenti[], int n);

#endif