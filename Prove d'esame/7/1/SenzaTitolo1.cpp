#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocaMatrice(int dim){
	int **matrice = (int**)malloc(dim*sizeof(int*));
	if(matrice == NULL){
		printf("\n Errore allocazione. ");
		exit(1);
	}
	for(int i=0; i<dim; i++){
		matrice[i] = (int*)malloc(dim*sizeof(int));
		if(matrice[i] == NULL){
			printf("\n Errore allocazione. ");
			exit(1);
		}
	}
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			int num = rand() % 11;
			if(num<=7)
				matrice[i][j] = 1;
			else
				matrice[i][j] = 0;
		}
	}	
	return matrice;
}


int main(){
	srand(time(NULL));
	int dim = 0;
	
	printf("\n Inserire dimensione -> ");
	scanf("%d", &dim);
	
	int **matrice = allocaMatrice(dim);
	
	for(int i=0; i<dim; i++){
		printf("\n");
		for(int j=0; j<dim; j++)
			printf(" %d", matrice[i][j]);
	}
	
	
	return 0;
}

