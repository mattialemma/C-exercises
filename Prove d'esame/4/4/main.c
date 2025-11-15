#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Stampare 
void stampaArray(char **array, int dim, int selezionato){
	for(int i=0; i<dim; i++){
		printf("\n %s ", array[i]);
		
		if(selezionato-1 == i){
			int size = strlen(array[i]);
	
			for(int j=0; j<size; j++){
				if(j==size-1)
					printf("\n SELEZIONATO: %c ", array[i][j]);
			}
		}
		}	
	}



int main() {
	srand(time(NULL));
	int n = 0, selezionato = 0, dimCas = 0;
	
	printf("\n Inserire n -> ");
	scanf("%d", &n);
	
	char **array = (char**)malloc(n*sizeof(char*));
	
	for(int i=0; i<n; i++){
		dimCas = rand() % 10 + 1;
		char *parola = (char*)malloc(dimCas+1*sizeof(char));
		for(int j=0; j<dimCas; j++){
			parola[j] = 'a' + rand() % 26;
		}
		parola[dimCas] = '\0';
		array[i] = parola;
	}
	
	printf("\n Seleziona -> ");
	scanf("%d", &selezionato);
	
	stampaArray(array, n, selezionato);
	
	return 0;
}