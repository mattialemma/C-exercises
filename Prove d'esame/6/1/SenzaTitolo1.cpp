#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	
	Lista *tmp = testa;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
		
	tmp->next = nodo;
	return testa;
}

void stampaLista(Lista *testa){
	if(testa == NULL)
		return;
	printf(" %d -", testa->dato);
	return stampaLista(testa->next);
}

int presente(Lista *testa, int x, int counter){
	if(testa == NULL)
		return 0;
	
	if(testa->dato == x)
		return counter;
	
	presente(testa->next, x, counter+1);	
}

int main (){
	int n = 0, dato = 0, x=0;
	Lista *testa = NULL;
	srand(time(NULL));
	
	printf("\ Inserisci n -> ");
	scanf("%d", &n);
	
	for(int i=0; i<n;i++){
		dato = rand() % 100 + 1;
		testa = inCoda(testa, dato);
	}
	
	stampaLista(testa);
	printf("\n Inserire X -> ");
	scanf("%d", &x);
	
	int counter = presente(testa, x, 1);
	
	if( counter == 0)
		printf("\n Elemento non presente! ");
	else
		printf("\n L'elemento si trova nella cella %d! ", counter);	
	
	return 0;
}

