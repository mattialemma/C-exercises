#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int dim = 3, lung = 10;
	char **parole = (char**)malloc(dim*sizeof(char*));
	if(parole==NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);
	}
	for(int i=0; i<dim; i++){
		parole[i] = (char*)malloc(lung*sizeof(char));
		if(parole==NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);
		}
	}
	
	strcpy(parole[0], "ugo");
	strcpy(parole[1], "forchetta");
	strcpy(parole[2], "patate");
	int dima = strlen(parole[1]);
	printf("%d", dima);
	
	for(int i=0; i<dim; i++){
		printf("\n %s", parole[i]);
	}
	
	for(int i=0; i<dim; i++){
		free(parole[i]);
	}
	free(parole);
	
	
	return 0;
}