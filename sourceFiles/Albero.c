#include "../header/albero.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <stdbool.h>


#define MAX(a,b) ((a)>(b) ? (a) : (b))
/**
 * @brief Crea un nuovo nodo dell'albero binario
 * 
 * @param value Il valore da assegnare al nodo
 * @return Puntatore al nodo appena creato
 */
node* createNode(int value) {
    node* new = (node*)malloc(sizeof(node));
    if (!new) {
        fprintf(stderr, "Errore di allocazione memoria in createNode\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->leftSon = NULL;
    new->rightSon = NULL;
    return new;
}

/**
 * @brief Inserisce un nuovo valore in un albero binario di ricerca (BST)
 * 
 * @param root Radice dell'albero
 * @param value Valore da inserire
 * @return Radice aggiornata dell'albero
 */
node* add_node(node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->leftSon = add_node(root->leftSon, value);
    } else if (value > root->value) {
        root->rightSon = add_node(root->rightSon, value);
    }

    return root;
}

/**
 * @brief Visita DFS (profondità) dell'albero
 * 
 * @param root Radice dell'albero
 */
void DFS(node* root) {
    if (root != NULL) {
        printf("%d\n", root->value);
        DFS(root->leftSon);
        DFS(root->rightSon);
    }
}

/**
 * @brief Visita BFS (ampiezza) dell'albero usando una coda
 * 
 * @param root Radice dell'albero
 */
void BFS(node* root) {
    if (root == NULL) return;

    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if (!Q) {
        fprintf(stderr, "Errore di allocazione memoria per la coda\n");
        exit(EXIT_FAILURE);
    }

    initQueue(Q);
    enqueue(Q, root);

    while (!isEmpty(Q)) {
        node* current = dequeue(Q);
        printf("%d\n", current->value);

        if (current->leftSon != NULL) {
            enqueue(Q, current->leftSon);
        }
        if (current->rightSon != NULL) {
            enqueue(Q, current->rightSon);
        }
    }

    free(Q);
}
/**
 * @brief trova l'altezza dell'albero
 * 
 * @param root 
 * @return int 
 */
int tree_height(node* root){
    if(root == NULL){
        return -1;
    }
    return 1+MAX(tree_height(root->leftSon),tree_height(root->rightSon));
} 

/**
 * @brief Funzione conta-foglie
 * 
 * @param root 
 * @return int 
 */
int countLeafs(node* root){
    if (root==NULL){return 0;}
    if(root->leftSon==NULL && root->rightSon==NULL){
        return 1;
    }
    return countLeafs(root->leftSon)+countLeafs(root->rightSon);
}

/**
 * @brief verifica se un valore è presente tramite una DFS
 * 
 * @param root 
 * @param value 
 * @return int 
 */
int search_value(node* root, int value){
    if(root == NULL){
        return false;
    }
    bool left = search_value(root->leftSon, value);
    bool right = search_value(root->rightSon, value);
    if(root->value==value){return true;}
    if(left || right){return true;}
    else{return false;}
}

/**
 * @brief Calcola la somma di tutti i nodi dell'albero
 * 
 * @param root 
 * @return int 
 */
int sum_tree(node* root){
    if(root == NULL){
        return 0;
    }
    // if(root->leftSon==NULL && root->rightSon==NULL){
    //     return root->value;
    // }
    return root->value+sum_tree(root->leftSon)+sum_tree(root->rightSon);
}

/**
 * @brief funzione per pulire la memoria
 * 
 * @param root 
 */
void clear_memory(node* root){
    if (root != NULL) {
        clear_memory(root->leftSon);
        clear_memory(root->rightSon);
        free(root);
    }
}

/**
 * @brief Funzione main per testare l'albero
 */
int main() {
    node* root = NULL;

    // Inserimento dei nodi nell'albero
    root = add_node(root, 10);
    add_node(root, 5);
    add_node(root, 15);
    add_node(root, 3);
    add_node(root, 7);

    printf("DFS:\n");
    DFS(root);

    printf("BFS:\n");
    BFS(root);

    return 0;
}
