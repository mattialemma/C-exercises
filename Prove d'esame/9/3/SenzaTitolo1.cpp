#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char titolo[30];
	int voto;
}Materia;

typedef struct{
	char nome[30];
	char cognome[30];
	int matricola;
	int nEsami;
	Materia *materia;
}Studente;

typedef struct Lista{
	Studente s;
	Lista *next;
}Lista;

Lista *creaNodo(Studente s){
	Lista *nodo = (Lista*)malloc(sizeof(Lista));
	if(nodo == NULL){
		printf("\n Errore memoria! ");
		exit(1);
	}
	nodo->s = s;
	nodo->next = NULL;
	return nodo;
}

Lista *inTesta(Lista *testa, Studente s){
	Lista *nodo = creaNodo(s);
	
	if(testa == NULL)
		return nodo;
	nodo->next = testa;
	return nodo;
}

void mediaPiuAlta(Lista *testa){
	if(testa == NULL)
		return;
	
	float media = 0.0, max = 0.0;
	int somma = 0; char nomeMax[30];
	Lista *current = testa;
	while(current != NULL){
		for(int i=0; i<current->s.nEsami; i++){
			somma += current->s.materia[i].voto;
		}
		media = (float)somma/current->s.nEsami;
		
		if(media > max){
			max = media;
			strcpy(nomeMax,current->s.nome);
		}
		somma = 0; media = 0.0;
		current = current->next;
	}	
	printf("\n Lo studente con la media maggiore e' %s ed ha media %.2f! ", nomeMax, max);
}


int main(){
	Studente s;
	s.materia = NULL;
	Lista *testa = NULL;
	int scelta = -1, scelta2 = -1;
	
	do{
		printf("\n Inserire il nome studente -> ");
		scanf("%s", s.nome);
		printf("\n Inserire il cognome studente -> ");
		scanf("%s", s.cognome);
		printf("\n Inserire matricola studente -> ");
		scanf("%d", &s.matricola);
		s.nEsami = 1;
		
		do{
		printf("\n Nome materia -> ");
		
		Materia *tmp = (Materia*)realloc(s.materia, s.nEsami*sizeof(Materia));
		if(tmp == NULL){
			printf("\n Errore allocazione memoria! ");
			exit(1);
		}
		s.materia = tmp;
		scanf("%s", s.materia[s.nEsami-1].titolo);	
		
		printf("\n Inserire voto -> ");
		scanf("%d", &s.materia[s.nEsami-1].voto);
		
		testa = inTesta(testa, s);
			
		printf("\n Vuoi continuare l'inserimento delle materie? \n 1 SI | 0 NO \n -> ");
		scanf("%d", &scelta2);
		if(scelta2 != 0)
			s.nEsami+=1;	
		}while(scelta2 != 0);


		printf("\n Vuoi continuare l'inserimento? \n 1 SI | 0 NO \n -> ");
		scanf("%d", &scelta);
	}while(scelta != 0);
	
	mediaPiuAlta(testa);
	
	return 0;
}