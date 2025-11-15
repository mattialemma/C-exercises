#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocaMatrice(int N, int M){
	int **matrice = (int**)malloc(N*sizeof(int*));
	if(matrice == NULL){
		printf("\n Bro la memoria non e' allocata bene per le righe! ");
		exit(1);
	}
	
	for(int i=0; i<M; i++){
		matrice[i] = (int*)malloc(M*sizeof(int));
		if(matrice[i] == NULL){
			printf("\n Bro la memoria non e' allocata bene per le colonne! ");
			exit(1);
		}		
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			matrice[i][j] = rand()%256; // Da 0 a 255 -> %255+1 + 255-0;
		}
	}
	
	return matrice;
}

void stampaMatrice(int N, int M, int **matrice){
	for(int i=0; i<N; i++){
		printf("\n");
		for(int j=0; j<M; j++){
			printf(" %d", matrice[i][j]);
		}
	}
}

int max(int N, int M, int **matrice){
	int max=matrice[0][0];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(matrice[i][j] > max){
				max = matrice[i][j];
			}
		}
	}
	return max;
}


int main(){
	srand(time(NULL));
	int N=0, M=0;
	
	do{	
	system("cls");
	printf("\n Inserire righe -> ");
	scanf("%d", &N);
	
	printf("\n Inserire colonne -> ");
	scanf("%d", &M);	
	}while(N<=0 || M<=0);
	
	int **matrice = allocaMatrice(N,M);
	stampaMatrice(N,M, matrice);
	
	printf("\n\n Ora ti dico subito l'elemento massimo carissimo... ");
	int massimo = max(N,M,matrice);
	printf("\n L'elemento massimo e'%d! ", massimo);
	
	return 0;
}