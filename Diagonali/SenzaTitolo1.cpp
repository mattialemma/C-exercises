// matrice dim NxN allocata a caso, vedere se la somma della diagonale principale = secondaria

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

ij

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44

*/


void diagPrincSec(int **matrice, int dim){
	
	int somma1 = 0, somma2 = 0;
	for(int i=0; i<dim; i++){
	for(int j=0; j<dim; j++){
		if(i+j == dim-1) // Somma diagonale secondaria
			somma2 += matrice[i][j];
		else if(i==j) // Somma diagonale primaria
			somma1 += matrice[i][j];
		}
	}
	
	if(somma2 >somma1)
		printf("\n\n La diagonale secondaria e' maggiore della primaria! ");
	else
		printf("\n\n La diagonale primaria e' maggiore della secondaria! ");		
}








int main(){
	srand(time(NULL));
	int dim = 0;
	
	printf("\n Inserire dim -> ");
	scanf("%d", &dim);
	system("cls");
	
	int **matrice = (int**)malloc(dim*sizeof(int*));
	for(int i=0; i<dim; i++)
		matrice[i] = (int*)malloc(dim*sizeof(int));
		
	
	for(int i=0; i<dim; i++){
		printf("\n");
		for(int j=0; j<dim; j++){
			matrice[i][j] = rand() % 11;
			printf(" %d ", matrice[i][j]);
		}
	}
	
	diagPrincSec(matrice, dim);
	
	return 0;
}




