#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char titolo[150];
    char regista[150];
    int durata_quantita;
    char durata_unita_misura[20];
    int postiLiberi[4][5];
}Film;

typedef struct Lista{
    Film f;
    struct Lista *next;
}Lista;

Lista *creaNodo(Film f){
    Lista *nodo = (Lista*)malloc(sizeof(Lista));
    
    if(nodo == NULL){
        printf("\n Errore allocazione nodo");
        return NULL;
    }
    
    nodo->f = f;
    nodo->next = NULL;
    return nodo;
}

Lista *inCoda(Lista *testa, Film f){
    Lista *nodo = creaNodo(f);
    if(testa == NULL)
        return nodo;
        
    Lista* tmp = testa;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = nodo;
    return testa;
}

int convertiRiga(char riga){
	if(riga == 'A')
		return 0;
	else if(riga == 'B')
		return 1;
	else if(riga == 'C')
		return 2;
	else if(riga == 'D')
		return 3;
	return -1;
}

void inizializzaMat(int mat[4][5]){
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			mat[i][j] = 0;
		}
	}
}

int convertiamoci(int valore, char *tipo){
	if(strcmp(tipo,"min")==0)
		return valore;
	else if(strcmp(tipo,"ore")==0)
		return (valore*60);	
	else if(strcmp(tipo,"bobine")==0)
		return (valore*11);
	else if(strcmp(tipo,"tempi")==0)
		return (valore*45);
	return -1;
}


Lista *load(Lista *testa, const char *filename){
    FILE *file = fopen(filename, "r");
    if(!file){
    	printf("\n Error. ");
    	exit(1);
	}
	
	Film f; char riga; int colonna, dim;
	while(fscanf(file,"%[^\n]\n %[^\n]\n %d %s", f.titolo, f.regista, &f.durata_quantita, f.durata_unita_misura)==4){
		inizializzaMat(f.postiLiberi);
		
		while(fscanf(file," %c %d", &riga, &colonna)==2){
				dim = convertiRiga(riga);
				if(dim>=0 && dim<4 && colonna-1 >= 0 && colonna-1 <5)
					f.postiLiberi[dim][colonna-1] = 1;
		}
		testa = inCoda(testa, f);
		fgetc(file);
	}
	return testa;
}

int pieno(Lista *testa){
	int counter = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			if(testa->f.postiLiberi[i][j] == 1)
				counter++;
		}
	}
	if(counter==20)
		return -1; // Pieno
}

int modificaMatrice(Lista *testa, char fila, int posiz){
	int riga = convertiRiga(fila);
	if(testa->f.postiLiberi[riga][posiz-1] == 0){
		testa->f.postiLiberi[riga][posiz-1] = 1;
		return 0; // Buon fine
	}		
	return 1; // Occupato
}

void stampaLista(Lista *testa){
	if(testa == NULL)
		return;
	
	printf("\n - - - - \n Titolo: %s. \n Regia: %s. \n Minutaggio: %d Min.", testa->f.titolo, testa->f.regista, convertiamoci(testa->f.durata_quantita, testa->f.durata_unita_misura));
	printf("\n Posti a sedere: ");
	
	for(int i=0; i<4; i++){
		printf("\n");
		for(int j=0; j<5; j++){
			if(testa->f.postiLiberi[i][j] == 0)
				printf(" L");
			else
				printf(" P");
		}
	}
	
    // -1 = pieno | 0 = buon fine |1 = occupato	
	int scelta = -1, posiz, check=-1; char fila;
	if(pieno(testa)!=-1){
	printf("\n Vuoi prenotare un posto? \n 1 si | 0 no \n -> ");
	scanf("%d", &scelta);
	
	if(scelta == 1){
		do{
			printf("\n Inserire fila ->");
			scanf(" %c", &fila); 
			printf("\n Inserire posizione -> ");
			scanf("%d", &posiz);
		
			check = modificaMatrice(testa, fila, posiz);
			if(check == 0)
				printf("\n Inserito!");
			else
				printf("\n Posto occupato.");
		}while(check != 0);
	}
	}else
		printf("\n SOLD OUT! ");
	stampaLista(testa->next);
}

Lista *eliminaSold(Lista *testa){
    while(testa && pieno(testa) == -1){
        Lista *tmp = testa;
        testa = testa->next;
        free(tmp);
    }
    if(!testa) return NULL;
    
    Lista *prev = testa;
    Lista *current = testa->next;
    while(current){
        if(pieno(current) == -1){
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return testa;
}


int main()
{
   Lista *testa = NULL;
   Film f;
   testa = load(testa, "film.txt");
   stampaLista(testa);
   printf("\n");
   system("pause");
   system("cls");
   eliminaSold(testa);
   stampaLista(testa);

    return 0;
}