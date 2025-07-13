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
    node* temp= head;
    if (!head) return NULL;
    node* new = new_node();
    while(head->next!=NULL){
        head = head->next;
    }
    head->next=new;
    return temp;
}

/**
 * @brief elimina il nodo in testa
 * 
 * @param head 
 * @return head 
 */
node* delete_head(node* head){
    if (!head) return NULL;
    node* temp = head->next;
    free(head);
    head = temp;
    return head;
}

/**
 * @brief elimina l'elemento in coda
 * 
 * @param head 
 * @return head
 */
node* delete_tail(node* head){
    if (!head) return NULL;
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    node* temp=head;
    while(head->next->next!=NULL){
        head=head->next;
    }
    free(head->next);
    head->next=NULL;
    return temp;
}
/**
 * @brief stampiamo la lista
 * 
 * @param head 
 */
void print_list(node* head){
    if (!head){printf("La lista è vuota.");}
    while(head != NULL){
        printf("%s\n", head->data);
        head=head->next;
    }
}

int main(){
}