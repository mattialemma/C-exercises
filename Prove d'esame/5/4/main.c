#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
	char nome[30];
	struct Lista *next;
}Lista;

Lista *creaNodo(char *nome){
	Lista *nodo = (Lista*)malloc(sizeof(Lista));
	if(nodo == NULL)
		return NULL;
	strcpy(nodo->nome, nome);
	nodo->next = NULL;
	return nodo;
}

Lista *inCoda(Lista *testa, char *nome){
	Lista *nodo = creaNodo(nome);
	Lista *current = testa;
	
	if(testa == NULL)
		return nodo;
	
	while(current->next != NULL){
		current = current->next;
	}
	current->next = nodo;
	return testa;
}

void stampaLista(Lista *testa){
	if(testa == NULL)
		return;
	printf("\n Nome: %s. ", testa->nome);
	return stampaLista(testa->next);
}

Lista *load(Lista *testa, const char *filename){
	FILE *file = fopen(filename, "r");
	if(!file){
		printf("\n Errore apertura file! ");
		exit(1);
	}
	
	char nome[30];
	while(fscanf(file, "%[^\n]", nome)==1){
		testa = inCoda(testa,nome);
		fgetc(file);		
	}
	
	return testa;
}

Lista *nodoScelto(Lista *testa, int indice){
	int counter = 0;
	Lista *tmp = testa;
	
	while(tmp != NULL && counter < indice){
		tmp = tmp->next;
		counter++;
	}
	return tmp;
}

Lista *ordina(Lista *testa, int array[]){
	Lista *ordinata = NULL;
	
	for(int i=0; i<5; i++){
		Lista *sel = nodoScelto(testa, array[i]-1);
		if(sel==NULL){
			printf("\n Errore lista vuota! ");
			exit(1);
		}
			ordinata = inCoda(ordinata, sel->nome);
	}
	return ordinata;
}

int main() {
	Lista *testa = NULL;
	Lista *ordinata = NULL;
	int array[5];
	
	testa = load(testa, "testo.txt");
	stampaLista(testa);
	
	printf("\n");
	for(int i=0; i<5; i++){
		printf("\n Inserire n.%d -> ", i+1);
		scanf("%d", &array[i]);
	}
	
	ordinata = ordina(testa, array);
	stampaLista(ordinata);
	
	return 0;
}