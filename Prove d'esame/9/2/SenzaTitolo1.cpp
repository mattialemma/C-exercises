#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista{
	int dato;
	struct Lista *next;
}Lista;

Lista *creaNodo(int dato){
	Lista *nodo = (Lista*)malloc(sizeof(Lista));
	if(nodo == NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);
	}
	nodo->dato = dato;
	nodo->next = NULL;
	return nodo;
}

Lista *inTesta(Lista *testa, int dato){
	Lista *nodo = creaNodo(dato);
	if(testa == NULL)
		return nodo;
		
	nodo->next = testa;
	return nodo;
}

void stampa(Lista *testa, int m){
	if(testa == NULL)
		return;
	if(testa->dato>m){
		printf("| %d", testa->dato);
	}
	stampa(testa->next, m);
}



int main(){
	srand(time(NULL));
	int dim = 0, dato = 0, m=0;
	Lista *testa = NULL;
	
	printf("\n Inserire dimensione -> ");
	scanf("%d", &dim);
	
	for(int i=0; i<dim; i++){
		dato = rand() % 100 + 1;
		testa = inTesta(testa, dato);
	}
	
	printf("\n Inserisci M -> ");
	scanf("%d", &m);
	
	stampa(testa, m);
	
	return 0;
}
