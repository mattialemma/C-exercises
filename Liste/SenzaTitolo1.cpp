#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 5

typedef struct Lista{
	int dato;
	struct Lista *next;
}Lista;

Lista *CreaNodo(int dato){
	Lista *nodo = (Lista*)malloc(sizeof(Lista));
	if(nodo == NULL)
		return NULL;
		
	nodo->dato = dato;
	nodo->next = NULL;
	return nodo;
}

Lista *inCoda(Lista *testa, int dato){
	Lista *nodo = CreaNodo(dato);
	
	if(testa == NULL)
		return nodo;
		
	Lista *current = testa;
	while(current->next != NULL){
		current=current->next;
	}
	current->next = nodo;
	return testa;
}

Lista *inTesta(Lista *testa, int dato){
	Lista *nodo = CreaNodo(dato);
	
	if(testa == NULL)
		return nodo;
		
	nodo->next = testa;
	return nodo;
}




void eliminaSeK(Lista *testa, int k) {
    Lista *prev = testa;
    Lista *current = testa->next;

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

void eliminaCoda(Lista *testa){
	if(testa == NULL)
		return;
	
	Lista *current = testa;
	Lista *prev = testa;
	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
}

void stampaRicorsiva(Lista *testa){
	if(testa == NULL)
		return;
	
	
	stampaRicorsiva(testa->next);
	printf(" %d ", testa->dato);
}



int main(){
	Lista *testa = NULL;
	
	for(int i=0; i<DIM; i++){
		testa = inTesta(testa, i);
	}
	
	stampaRicorsiva(testa);
	printf("\n");	
	
	eliminaSeK(testa,3);
	printf("\n");
	stampaRicorsiva(testa);	

	printf("\n");
	eliminaCoda(testa);
	stampaRicorsiva(testa);
	
	return 0;
}


