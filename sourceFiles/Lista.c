#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../header/lista.h"

/**
 * @brief funzione per creare un nuovo nodo
 * 
 * @return node* 
 */
node* new_node(){
    node* new = (node*)malloc(sizeof(node));
    if (!new) return NULL;
    new->next=NULL;
    char description[MAX_LEN];
    printf("Inserire il dato: %s\n");
    fflush(stdout);
    scanf("%99s",description);
    strcpy(new->data,description);
    return new;
}

/**
 * @brief aggiunge un elemento in testa
 * 
 * @param head
 * 
 * @return head 
 */
node* add_head(node* head){
    node* new = new_node();
    if (!new) return NULL;
    new->next=head;
    new->data[MAX_LEN - 1] = '\0';
    return new;
}

/**
 * @brief aggiunge un elemento in coda
 * 
 * @param head 
 */
node* add_tail(node* head){
    if (!head) return NULL;
    node* new = new_node();
    while(head->next!=NULL){
        head = head->next;
    }
    head->next=new;
}

int main(){
}