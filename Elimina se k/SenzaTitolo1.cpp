#include <stdlib.h>
#include <stdio.h>

// Dichiarazione della struttura Node_SL
struct Node_SL {
    int dato;
    struct Node_SL *next;
};

// Funzione per creare un nuovo nodo
struct Node_SL *CreateNode_SL(int dato) {
    struct Node_SL *newNode = (struct Node_SL *)malloc(sizeof(struct Node_SL));
    if (newNode) {
        newNode->dato = dato;
        newNode->next = NULL;
    }
    return newNode;
}


void InCoda(struct Node_SL *testa, int dato){
    struct Node_SL *tmp = CreateNode_SL(dato);
    struct Node_SL *current = testa;
    
    if(tmp){
        if(testa->next == NULL){
            testa->next=tmp;
            return;
        }
        else{
            while(current->next != NULL){
                current = current->next;
            }
            current->next = tmp;
        }
    }
}


void EliminaElementoSeK(struct Node_SL *testa, int k) {
    struct Node_SL *prev = testa;
    struct Node_SL *current = testa->next;

    // Gestisci il caso in cui la lista è vuota
    if (current == NULL)
        return;

    // Gestisci il caso in cui l'elemento da eliminare è la testa
    if (testa->dato == k) {
        testa = current; // Aggiorna il puntatore testa
        free(prev); // Dealloca la memoria della vecchia testa
        return;
    }

    while (current != NULL) {
        if (current->dato == k) {
            prev->next = current->next;
            free(current);
            return;
        } else {
            prev = current;
            current = current->next;
        }
    }
}



// Funzione per stampare la lista
void PrintList_SL(struct Node_SL *Head) {
    printf("Lista: ");
    while (Head != NULL) {
        printf("%d -> ", Head->dato);
        Head = Head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node_SL lista;
    lista.next = NULL;
    int dato, vElimin;

    do{
        printf("\n Dato -> ");
        scanf("%d", &dato);
        
        if(dato!=0){
            InCoda(&lista, dato);
        }
    }while(dato != 0);
    
    PrintList_SL(lista.next);
    
    printf("\n Inserisci elemento da eliminare -> ");
    scanf("%d", &vElimin);
    
    EliminaElementoSeK(&lista, vElimin);
    PrintList_SL(lista.next);
    
    return 0;

}