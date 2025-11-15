#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int **CreaMatrice(int dim){
	srand(time(NULL));
	int **matrice = (int**)malloc(dim*sizeof(int*));
	for(int i=0; i<dim; i++)
		matrice[i] = (int*)malloc(dim*sizeof(int));
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++)
			matrice[i][j] = rand()%100;
	}
	return matrice;
}

void StampaMatrice(int **matrice, int dim){
	printf("\n  MATRICE: ");
	for(int i=0; i<dim; i++){
		printf("\n ");
		for(int j=0; j<dim; j++)
			printf(" %d ", matrice[i][j]);
	}
}

void sommaMatrice(int **matrice, int dim){
	printf("\n PARI O DISPARI ");
	int somma = 0;
	
	for(int i=0; i<dim; i++){
		somma = 0;
		for(int j=0; j<dim; j++){
			somma+=matrice[i][j];
		}
		if(somma%2 == 0)
			printf("\n La somma della riga %d e' pari! ", i+1);
		else
			printf("\n La somma della riga %d e' dispari! ", i+1);
	}
	
	
}

int main(){
	int dim = 0;
	int **matrice;
	
	printf("\n Inserire la dimensione della matrice -> ");
	scanf("%d", &dim);
	
	matrice = CreaMatrice(dim);
	StampaMatrice(matrice, dim);
	sommaMatrice(matrice, dim);
	
	return 0;
}