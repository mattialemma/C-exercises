#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Lista{
	char carattere;
	struct Lista *next;
};

struct Lista *creaNodo(char dato){
	struct Lista *nodo = (struct Lista*)malloc(sizeof(struct Lista));
	
	if(nodo == NULL)
		return NULL;
	
	nodo->carattere = dato;
	nodo->next = NULL;
	return nodo;
}

struct Lista *inCoda(struct Lista *testa, char dato){
	struct Lista *nodo = creaNodo(dato);
	if(testa == NULL)
		return nodo;
	
	struct Lista *tmp = testa;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = nodo;
	return testa;
}

void stampaLista(struct Lista *testa, int posizione){
	if(testa == NULL)
		return;
	
	printf("\n %c pz. %d ", testa->carattere, posizione);
	stampaLista(testa->next, ++posizione);
}


int main() {
	srand(time(NULL));
	char dato;
	int dim = 0;
	struct Lista *testa = NULL;
	
	printf("\n Inserire dim -> ");
	scanf("%d", &dim);
	
	for(int i=0; i<dim; i++){
		dato = 'A' + rand() % 26;
		testa = inCoda(testa, dato);
	}
	
	stampaLista(testa, 1);
	
	return 0;
}