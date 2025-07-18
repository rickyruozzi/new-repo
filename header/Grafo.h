#ifndef GRAFO_H
#define GRAFO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Nodo del grafo
 * 
 */
typedef struct Nodo {
    int destinazione;
    int peso;
    struct Nodo* prossimo;
} Nodo;

/**
 * @brief lista dei nodi che confinano con il grafo, ne esisteranno in numerouguale al numero dei nodi
 * 
 */
typedef struct Lista {
    Nodo* testa;
} Lista;

/**
 * @brief struttura rappresentante il grafo
 * 
 */
typedef struct Grafo {
    int numVertici;
    Lista* arrayListe;
} Grafo;

Nodo* creaNodo(int destinazione, int peso);

// Crea un grafo con n vertici
Grafo* creaGrafo(int numVertici);

// Aggiunge un arco diretto pesato
void aggiungiArco(Grafo* grafo, int sorgente, int destinazione, int peso);

// Stampa il grafo
void stampaGrafo(const Grafo* grafo);

// Libera la memoria del grafo
void distruggiGrafo(Grafo* grafo);

void stampaVicini(const Grafo* grafo, int sorgente);

bool esisteArco(const Grafo* grafo, int u, int v);

#endif