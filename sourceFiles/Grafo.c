#include "../header/Grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/**
 * @brief funzione crea nodo
 * 
 * @param destinazione 
 * @param peso 
 * @return Nodo* 
 */
Nodo* creaNodo(int destinazione, int peso){
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if(!nuovo){
        printf("Errore di memoria\n");
        exit(EXIT_FAILURE);
    }
    nuovo->destinazione = destinazione;
    nuovo->peso = peso;
    nuovo->prossimo = NULL;
    return nuovo;
}

/**
 * @brief crea un nuovo grafo
 * 
 * @param numero_vertici 
 * @return Grafo* 
 */
Grafo* creaGrafo(int numero_vertici){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if(!grafo){
        printf("Errore di memoria\n");
        exit(EXIT_FAILURE);
    }
    grafo->numVertici=numero_vertici;
    grafo->arrayListe= (Lista*)malloc(sizeof(Lista)*numero_vertici);
       if (!grafo->arrayListe) {
        perror("Errore allocazione liste");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<numero_vertici;i++){
        grafo->arrayListe[i].testa=NULL;
    }
    return grafo;
}

/**
 * @brief aggiungi un grafo
 * 
 * @param grafo 
 * @param sorgente 
 * @param destinazione 
 * @param peso 
 */
void aggiungiArco(Grafo* grafo, int sorgente, int destinazione, int peso){
    Nodo* nuovo = creaNodo(destinazione, peso);
    nuovo->prossimo = grafo->arrayListe[sorgente].testa;
    grafo->arrayListe[sorgente].testa=nuovo;
}

/**
 * @brief stampa il grafo
 * 
 * @param grafo 
 */
void stampaGrafo(const Grafo* grafo){
    for(int i=0;i<grafo->numVertici; i++){
        printf("Nodo corrente: %d\n",i);
        Nodo* testa = grafo->arrayListe[i].testa;
        printf("Nodi adiacenti: \n");
        while(testa){
            printf(" -> %d (peso: %d)\n", testa->destinazione, testa->peso);
            testa=testa->prossimo;
        }
    }
}

/**
 * @brief distrugge il grafo
 * 
 * @param grafo 
 */
void distruggiGrafo(Grafo* grafo){
    for(int i=0; i<grafo->numVertici; i++){
        Nodo* testa = grafo->arrayListe[i].testa;
        while(testa){
            Nodo* prossimo = testa->prossimo;
            free(testa);
            testa=prossimo;
        }
    }
    free(grafo->arrayListe);
    free(grafo);
}

/**
 * @brief stampa i vicini di un determinato nodo
 * 
 * @param grafo 
 * @param sorgente 
 */
void stampaVicini(const Grafo* grafo, int sorgente){
    Nodo* testa = grafo->arrayListe[sorgente].testa;
    while(testa){
        printf("Nodo vicino: %d (peso: %d)\n", testa->destinazione, testa->peso);
        testa=testa->prossimo;
    }
}


/**
 * @brief verifica l'esistenza di un arco
 * 
 * @param grafo 
 * @param u 
 * @param v 
 * @return true 
 * @return false 
 */
bool esisteArco(const Grafo* grafo, int u, int v){
    Nodo* testa = grafo->arrayListe[u].testa;
    bool Trovato=false;
    while(testa){
        if(testa->destinazione==v){
            Trovato=true;
        }
        testa=testa->prossimo;
    }
    return Trovato;
}

int main(){}