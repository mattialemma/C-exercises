#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int **allocaMat(int righe, int colonne){
	int **matrice = (int**)malloc(righe*sizeof(int*));
	if(matrice == NULL){
		printf("\n Errore");
		exit(1);
	}
	for(int i=0; i<colonne; i++){
		matrice[i] = (int*)malloc(colonne*sizeof(int));
		if(matrice[i] == NULL){
			printf("\n Errore");
			exit(1);
			}
		}
		return matrice;	
		
		
		/*
		MEMORIA ALLOCATA IN MANIERA CONTIGUA
		
		int **matrice = (int**)malloc(righe*sizeof(int*));
		matrice[0] = (int*)malloc((righe*colone)*sizeof(int));
		
		*/
}






int main(){
	char *stringa = (char*)malloc(41*sizeof(char));
	int max = 0, lungCorr = 0;
	
	printf("\n Inserire una stringa di max 40 parole -> ");
	scanf("%s", stringa);
	
	for(int i=0; stringa[i] != '\0'; i++){
		if(stringa[i] == stringa[i+1])
			lungCorr++;
		else if(lungCorr > max){
			max = lungCorr;
		lungCorr = 1;
		}
	}	
	
	if(lungCorr > max)
		max = lungCorr;
		
	 printf("\nLa lunghezza massima della sottosequenza di caratteri uguali consecutivi e': %d.\n", max);

    free(stringa);  // Liberazione della memoria allocata dinamicamente
	
	return 0;
}



