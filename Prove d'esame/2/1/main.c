#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44
*/

int **creaMatrice(int dim){
	// Alloca matrice
	int **matrice = (int**)malloc(dim*sizeof(int*));
	for(int i=0; i<dim; i++)
		matrice[i] = (int*)malloc(dim*sizeof(int));
	
	// Popola matrice
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++)
			matrice[i][j] = rand()%100;
	}
		return matrice;
}

void stampaMatrice(int **matrice, int dim){
	for(int i=0; i<dim; i++){
		printf("\n ");
		for(int j=0; j<dim; j++){
			printf(" %d ", matrice[i][j]);
		}
	}
}

int verifica(int **matrice, int dim){
	int sumSup = 0, sumInf = 0;
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			if(i<j)
				sumSup+=matrice[i][j];
			else if(i>j)
				sumInf+=matrice[i][j];
		}
	}
	if(sumSup>sumInf)
		return 1;
	else
		return 0;
}

void liberaMatrice(int **matrice, int dim){
	for(int i=0; i<dim; i++){
		free(matrice[i]);
	}
	free(matrice);
}

int main() {
	srand(time(NULL));
	int dim = 0;
	int **matrice;
	
	printf("\n Inserire la dimensione della matrice -> ");
	scanf("%d", &dim);
	matrice = creaMatrice(dim);
	stampaMatrice(matrice, dim);
	
	if(verifica(matrice, dim))
		printf("\n\n La somma dei numeri superiori alla diagonale principale e' maggiore rispetto a quella inferiore! ");
	else
		printf("\n\n La somma dei numeri inferiori alla diagonale principale e' minore rispetto a quella superiore! ");
		
	liberaMatrice(matrice, dim);	
		
	return 0;
}