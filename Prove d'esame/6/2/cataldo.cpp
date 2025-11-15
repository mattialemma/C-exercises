#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
	int red;
	int green;
	int blue; 
}Colori;

Colori **allocaMatrice(int dim){
	Colori **matrice = (Colori**)malloc(dim*sizeof(Colori*));
	if(matrice == NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);
	}
	for(int i=0; i<dim; i++){
		matrice[i] = (Colori*)malloc(dim*sizeof(Colori));
		if(matrice[i] == NULL){
			printf("\n Errore allocazione memoria! ");
			exit(1);		
		}
	}
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			matrice[i][j].red = rand() % 256;
			matrice[i][j].green = rand() % 256;
			matrice[i][j].blue = rand() % 256;
		}
	}
	return matrice;
}

void stampaMatrice(Colori **matrice, int dim){
	for(int i=0; i<dim; i++){
		printf("\n");
		for(int j=0; j<dim; j++){
			printf(" %d", matrice[i][j].red);
			printf(" %d", matrice[i][j].green);
			printf(" %d", matrice[i][j].blue);
			printf(" |");
		}
	}	
}

int main(){
	int n = 0;
	Colori **matrice;
	srand(time(NULL));
	
	printf("\n Dammi n -> ");
	scanf("%d", &n);
	
	matrice = allocaMatrice(n);
	stampaMatrice(matrice, n);
	
	return 0;
}

