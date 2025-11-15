#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int **allocaMatrice(int dim){
	int **matrice = (int**)malloc(dim*sizeof(int*));
	if(matrice == NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);
	}
	for(int i=0; i<dim; i++){
		matrice[i] = (int*)malloc(dim*sizeof(int));
		if(matrice[i]==NULL){
			printf("\n Errore allocazione memoria! ");
			free(matrice);
			exit(1);	
		}
	}
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			matrice[i][j] = rand() %100+1;
		}
	}
	return matrice;
}

void stampaMatrice(int **matrice, int dim){
	for(int i=0; i<dim; i++){
		printf("\n");
		for(int j=0; j<dim; j++){
			printf("| %d", matrice[i][j]);
		}
	}
}

int rigaMinima(int **matrice, int dim){
	int somma = 0, min = 0, indice = 0;
	
	for(int i=0; i<dim; i++)
		min+=matrice[0][i];
	
	for(int i=1; i<dim; i++){
		somma = 0;
		for(int j=0; j<dim; j++){
			somma += matrice[i][j];
			if(somma<min){
				min = somma;
				indice = i;
			}
		}
	}
	return indice;
}

int main(){
	srand(time(NULL));
	int dim = 0, indice = -1;
	int **matrice = NULL;
	
	do{
	system("cls");
	printf("\n Inserire dimensione matrice -> ");
	scanf("%d", &dim); 
	}while(dim<= 0);
	
	matrice = allocaMatrice(dim);
	stampaMatrice(matrice,dim);
	
	indice = rigaMinima(matrice, dim);
	printf("\n La riga minima e' la %d.", indice+1);
	
	return 0;
}