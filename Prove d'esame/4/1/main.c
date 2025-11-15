#include <stdio.h>
#include <stdlib.h>

struct Numero{
	int intero;
	float decimale;
};

void stampaArray(struct Numero *array, int dim){
	
	int maxInt = array[0].intero, pInt = 0, pDec = 0;
	float maxDec = array[0].decimale;
	
	for(int i=0;i<dim;i++){
		printf("\n\n Intero: %d. \n Decimale: %.3f. ", array[i].intero, array[i].decimale);
		
		if(array[i].intero > maxInt){
			maxInt = array[i].intero;
			pInt = i;
		}
		if(array[i].decimale > maxDec){
			maxDec = array[i].decimale;
			pDec = i;
		}
	}
	printf("\n Il massimo intero e' l'elemento %d nella posizione %d. ", maxInt, pInt+1);
	printf("\n Il massimo decimale e' l'elemento %f nella posizione %d. ", maxDec, pInt+1);	
}

int main() {
	int n = 0;
	float num = 0.0;
	
	printf("\n Quanti numeri vuoi inserire? \n -> ");
	scanf("%d", &n);
	
	struct Numero *array = (struct Numero*)malloc(n*sizeof(struct Numero));
	
	for(int i=0; i<n;i++){
		printf("\n Inserire il numero %d -> ", i+1);
		scanf("%f", &num);
		
		array[i].intero = (int)num;
		array[i].decimale = num-(int)num;
	}
	stampaArray(array, n);
	
	return 0;
}