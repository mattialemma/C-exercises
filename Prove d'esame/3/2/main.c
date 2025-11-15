// 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *allocaArray(int dim){
	int *array = (int*)malloc(dim*sizeof(int));
	
	for(int i=0; i<dim; i++)
		array[i] = rand() % 21 + 60;
		
	return array;
}

int stampaRicorsivaOrdinata(int *array, int dim, int offset){
	if(dim == offset)
		return 0;
	
	printf(" %d ", array[offset]);
	stampaRicorsivaOrdinata(array, dim, offset+1);
	return 0;
}

int stampaRicorsivaInversa(int *array, int dim, int offset){
	if(dim == offset)
		return 0;
	

	stampaRicorsivaInversa(array, dim, offset+1);
	printf(" %d ", array[offset]);
	return 0;
}

void insert(int *array, int elemento, int posizione){
				array[posizione] = elemento;
}


int main() {
	srand(time(NULL));
	int dim = 0, elemento = 0, posizione = 0;
	
	printf("\n Inserire la dimensione -> ");
	scanf("%d", &dim);
	
	int *array = allocaArray(dim);
	
	printf("\n Ordinato: ");
	stampaRicorsivaOrdinata(array, dim, 0);
	printf("\n Inverso: ");
	stampaRicorsivaInversa(array, dim, 0);	
	
	printf("\n Inserire elemento -> ");
	scanf("%d", &elemento);
	
	do{
	printf("\n Inserire posizione -> ");
	scanf("%d", &posizione);
	}while(posizione<1 || posizione>dim);
	
 	insert(array, elemento, posizione-1);
 	printf("\n Nuovo array: ");
	stampaRicorsivaOrdinata(array, dim, 0);	
	
	return 0;
}