#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocaMatrice(int n, int m){
	int **matrice = (int**)malloc(n*sizeof(int*));
	
	if(matrice == NULL){
		printf("\n Errore allocazione memoria! ");
		exit(1);
	}
	
	for(int i=0; i<n; i++){
		matrice[i] = (int*)malloc(n*sizeof(int));
		if(matrice[i] == NULL){
			printf("\n Errore allocazione memoria! ");
			exit(1);
		}
	}
	
	for(int i=0; i<n; i++){
		printf("\n ");
		for(int j=0; j<m;j++){
			matrice[i][j] = rand() % 101;
			printf(" %d ", matrice[i][j]);
		}
	}
	
	return matrice;
}

/*
Matrice: 4x5

	    n-1 m
n m-1   n m	   n m+1
	    n+1 m

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
*/

void massimoLocale(int **matrice, int n, int m){
	int flag = 0;
	for(int i=1; i<n-1; i++){
		for(int j=1; j<m-1; j++){
			if(matrice[i][j] > matrice[i-1][j] && matrice[i][j] > matrice[i+1][j] && matrice[i][j] > matrice[i][j-1] && matrice[i][j] > matrice[i][j+1]){
				printf("\n L'elemento %d e' un massimo locale! ", matrice[i][j]);
				flag = 1;
			}
		}	
	}
	if(flag == 0)
		printf("\n Non ci sono massimi locali! ");	
}


int main() {
	srand(time(NULL));
	int n=0, m=0;
	
	printf("\n Inserire n -> ");
	scanf("%d", &n);
	printf("\n Inserire m -> ");
	scanf("%d", &m);
	
	int **matrice = allocaMatrice(n, m);
	massimoLocale(matrice, n, m);
	
	return 0;
}