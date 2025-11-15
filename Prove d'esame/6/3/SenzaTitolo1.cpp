#include <stdlib.h>
#include <stdio.h>

typedef struct Studente{
	char nome[20];
	char cognome[20];
	int voto;
}Studente;

typedef struct Lista{
	Studente s;
	struct Lista *next;
}Lista;

Lista *CreaNodo(Studente st){
	Lista *nodo = (Lista*)malloc(sizeof(Lista));
	if(nodo == NULL)
		return NULL;
		
	nodo->s = st;
	nodo->next = NULL;
	return nodo;
}

Lista *inCoda(Lista *testa, Studente s){
	Lista *nodo = CreaNodo(s);
	
	if(testa == NULL)
		return nodo;
		
	Lista *current = testa;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = nodo;
	return testa;
}

void stampaLista(Lista *testa){
	if(testa == NULL)
		return;
		
	printf("\n\n Nome studente: %s. \n Cognome studente: %s.", testa->s.nome, testa->s.cognome);
	if(testa->s.voto != 0)
		printf("\n Voto studente: %d", testa->s.voto);
	else
		printf("\n Esame non superato! ");
	
	stampaLista(testa->next);
}

void media(int nSuperato, int nNonSuperato) {
    int totale = nSuperato + nNonSuperato;
    if (totale == 0) {
        printf("\n Nessuno studente registrato.");
        return;
    }

    float percentualeSuperata = ((float)nSuperato / totale) * 100;
    float percentualeNonSuperata = ((float)nNonSuperato / totale) * 100;

    printf("\n\n Gli studenti che hanno superato sono il %.2f%%.", percentualeSuperata);
    printf("\n Gli studenti che non hanno superato sono il %.2f%%.", percentualeNonSuperata);
}




int main(){
	Lista *testa = NULL;
	Studente s;
	int scelta = -1;
	int nSuperato = 0, nNonSuperato = 0;
	
	do{
		system("cls");
		printf("\n Inserire il nome dello studente -> ");
		scanf("%s", s.nome);
		system("cls");
		printf("\n Inserire il cognome dello studente -> ");
		scanf("%s", s.cognome);
		system("cls");		
		printf("\n Inserire il voto dello studente \n Inserire 0 se non ha superato. \n -> ");
		scanf("%d", &s.voto);
		
		if(s.voto == 0)
			++nNonSuperato;
		else
			++nSuperato;
		
		testa = inCoda(testa, s);
				
		system("cls");
		printf("\n Vuoi inserire un nuovo studente? \n 1 SI, 0 NO \n --> ");
		scanf("%d", &scelta);
	}while(scelta == 1);
	
	stampaLista(testa);
	media(nSuperato, nNonSuperato);
	
	return 0;
}

