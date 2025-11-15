#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pratica{
	char nomeImpiegato[20];
	char nomeCliente[20];
	int numeroPratica;
};

struct Lista{
	struct Pratica impiegato;
	struct Lista *next;
};

struct Lista *creaNodo(struct Pratica p){
	struct Lista *nodo = (struct Lista*)malloc(sizeof(struct Lista));
	if(nodo == NULL)
		return NULL;
	nodo->impiegato = p;
	nodo->next = NULL;
	return nodo;
}

struct Lista *inTesta(struct Lista *testa, struct Pratica p){
	struct Lista *nodo = creaNodo(p);
	if(testa == NULL)
		return nodo;
	nodo->next = testa;
	return nodo;
}

void stampaLista(struct Lista *testa){
	if(testa == NULL)
		return;
	printf("\n\n Impiegato: %s. \n Cliente: %s. \n Numero pratica: %d. ", testa->impiegato.nomeImpiegato, testa->impiegato.nomeCliente, testa->impiegato.numeroPratica);
	return stampaLista(testa->next);
}

void inFile(struct Lista *testa){
	FILE *file = fopen("nuovo.txt","w");
	if(!file)
		printf("\n Errore creazione file! ");
	
	while(testa != NULL){
		fprintf(file, "\n\n Nome impiegato: %s. \n Nome cliente: %s. \n Numero pratica: %d. ", testa->impiegato.nomeImpiegato, testa->impiegato.nomeCliente, testa->impiegato.numeroPratica);
		testa = testa->next;
	}
}


int main() {
	srand(time(NULL));
	struct Lista *testa = NULL;
	struct Pratica p;
	
	FILE *file = fopen("impiegati.txt","r");
	if(!file)
		printf("\n Errore apertura file! ");
	
	// Leggo nomeImpiegato dal file e cliente e pratica in input
	while(fscanf(file, " %[^\n]", p.nomeImpiegato)==1){
		printf("\n Nome cliente -> ");
		scanf("%s", p.nomeCliente);
		printf("\n Numero pratica -> ");
		scanf("%d", &p.numeroPratica);		
		testa = inTesta(testa, p);
	}

	stampaLista(testa);
	inFile(testa);
	fclose(file);
	
	return 0;
}