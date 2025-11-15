#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Lista{
	int dato;
	struct Lista *next;
};

struct Lista *CreaNodo(int dato){
	struct Lista *nodo = (struct Lista*)malloc(sizeof(struct Lista));
	if(nodo == NULL)
		return NULL;
	
	nodo->dato = dato;
	nodo->next = NULL;
	return nodo;
}

struct Lista *inCoda(struct Lista *testa, int dato){
	struct Lista *nodo = CreaNodo(dato);
	if(testa == NULL)
		return nodo;
	struct Lista *tmp = testa;
	while(tmp->next!=NULL){
		tmp = tmp->next;
	}	
	tmp->next = nodo;
	return testa;
}

int ordinata(struct Lista *testa){
	if(testa->next == NULL)
		return 1;
	if(testa->dato < testa->next->dato)
		return 0;
	ordinata(testa->next);
}

void stampaLista(struct Lista *testa){
	if(testa == NULL)
		return;
	printf(" %d ", testa->dato);
	stampaLista(testa->next);
}


int main(){
	struct Lista *testa = NULL;
	int dato = 0;
	srand(time(NULL));
	
	for(int i=0; i<10; i++){
		dato = rand()%10+1;
		testa = inCoda(testa, dato);
	}
	
	printf("\n Lista: ");
	stampaLista(testa);
	
	if(ordinata(testa)){
		printf("\n La lista e' ordinata! ");
	}else
	printf("\n La lista non e' ordinata! ");
	
	
	
	
	
	
	return 0;
}

