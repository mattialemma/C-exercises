#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int n = 0, max = 0, min = 0;
	srand(time(NULL));
	
	printf("\n Inserire n -> ");
	scanf("%d", &n);
	
	int **matrice = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++){
		matrice[i] = (int*)malloc(n*sizeof(int));
	}	
	
	for(int i=0; i<n; i++){
		printf("\n");
		for(int j=0; j<n; j++){
			matrice[i][j] = rand() % 101;
			printf(" %d ", matrice[i][j]);
		}
	}
	
	max = 0;
	min = matrice[0][0];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				if(matrice[i][j] > max)
					max = matrice[i][j];
				if(matrice[i][j] < min)
					min = matrice[i][j];
			}
		}
	}
	printf("\n\n Massimo diagonale principale: %d. \n Minimo diagonale principale: %d. ", max, min);
	

	max = 0; 
	min = matrice[0][0];	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i+j==n-1){
				if(matrice[i][j] > max)
					max = matrice[i][j];
				if(matrice[i][j] < min)
					min = matrice[i][j];
			}
		}
	}	
	
	printf("\n\n Massimo diagonale secondaria: %d. \n Minimo diagonale secondaria: %d. ", max, min);
	
	return 0;
}