#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocaMatrice(int dim){
	int **matrice = (int**)malloc(dim*sizeof(int*));
	for(int i=0; i<dim; i++){
		matrice[i] = (int*)malloc(dim*sizeof(int));
	}
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++)
			matrice[i][j] = rand()%101+1;
	}
	
	return matrice;
}

void stampaMatrice(int **matrice, int dim){
	for(int i=0; i<dim; i++){
		printf("\n ");
		for(int j=0; j<dim; j++){
			printf(" %d", matrice[i][j]);
		}
	}
}

void somma(int **matrice, int dim){
	int somma = 0;
	for(int i=0; i<dim; i++){
		
		if(i%2 == 0){
		for(int j=0; j<dim; j++){
			somma+= matrice[i][j];
			}
		}
	}
	printf("\n\n La somma e' %d. ", somma);
}

int main() {
	srand(time(NULL));
	int dim = 0;
	
	printf("\n Inserire dim -> ");
	scanf("%d", &dim);
	
	int **matrice = allocaMatrice(dim);
	stampaMatrice(matrice, dim); // Test
	somma(matrice, dim);
	
	
	return 0;
}