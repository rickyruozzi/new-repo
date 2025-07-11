#ifndef RUOLI_H
#define RUOLI_H
#define MAX_LENGTH 30
typedef struct{
    int anno;
    float media;
    char nome[MAX_LENGTH];
    char cognome[MAX_LENGTH];
} studente; 
typedef struct{
    char nome[MAX_LENGTH];
    char cognome[MAX_LENGTH];
    char materia[MAX_LENGTH];
} professore;
#endif