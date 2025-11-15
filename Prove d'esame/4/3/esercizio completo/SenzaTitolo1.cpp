#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Cliente{
	char nome[30];
	int nPratica;
}Cliente;

typedef struct Dipendente{
	char nome[30];
	int n;
	Cliente *nPratiche;
	struct Dipendente *next;
}Dipendente;

Dipendente *creaNodo(Cliente *nPratiche, int dim, char *nomeImpiegato){
	Dipendente *nodo = (Dipendente*)malloc(sizeof(Dipendente));
	if(nodo == NULL)
		return NULL;
		
	nodo->nPratiche = (Cliente*)malloc(dim*sizeof(Cliente));
	if(nodo->nPratiche == NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);	
	}
	
	strcpy(nodo->nome, nomeImpiegato);
	nodo->nPratiche = nPratiche;
	nodo->n = dim;
	nodo->next = NULL;
	
	return nodo;
}

Dipendente *inCoda(Dipendente *testa, Cliente *nPratiche, int dim, char *nomeImpiegato){
	Dipendente *nodo = creaNodo(nPratiche, dim, nomeImpiegato);
	
	if(testa == NULL)
		return nodo;
	
	Dipendente *current = testa;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = nodo;
	return testa;
}

void stampaFile(Dipendente *testa, const char *filename){
	FILE *file = fopen(filename, "w");
	if(!file){
		printf("\n Errore apertura file!");
		exit(1);
	}
	
	Dipendente *current = testa;
	while(current != NULL){
		fprintf(file, "\n - - - - - - \n");
		fprintf(file,"\n Nome dipendente: %s.", current->nome);
		fprintf(file,"\n Numero clienti: %d. ", current->n);
		for(int i=0; i<current->n; i++){
			fprintf(file,"\n Nome cliente: %s.", current->nPratiche[i].nome);
			fprintf(file,"\n Numero pratica cliente: %d.", current->nPratiche[i].nPratica);
		}
		current = current->next;
	}
}



int main(){
	srand(time(NULL));
	Dipendente *testa = NULL;
	char nomeDipendente[30];
	int dim = 0;
	
	FILE *file = fopen("dipendenti.txt", "r");
	if(!file){
		printf("\n File non aperto! ");
		exit(1);
	}
	
	while(fscanf(file,"%[^\n]", nomeDipendente)==1){
		getc(file);
		printf("\n Nome: %s", nomeDipendente);
		printf("\n Quante pratiche vuoi inserire per il dipendente %s? \n -> ", nomeDipendente);
		scanf("%d", &dim);
		
		Cliente *arrayCliente = (Cliente*)malloc(dim*sizeof(Cliente));
		if(arrayCliente == NULL){
			printf("\n Errore allocazione memoria! ");
			exit(1);
		}
		
		for(int i=0; i<dim; i++){
			printf("\n %d) Inserire nome cliente -> ", i+1);
			scanf("%s", arrayCliente[i].nome);
			printf("\n %d) Inserire numero pratica cliente -> ", i+1);
			scanf("%d", &arrayCliente[i].nPratica);
		}
		
		testa = inCoda(testa, arrayCliente, dim, nomeDipendente);
	}
	
	stampaFile(testa, "nuovo.txt");
	
	
	
	return 0;
}
