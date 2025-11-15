#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *allocaArray(int dim){
	float *array = (float*)malloc(dim*sizeof(float));
	if(array == NULL){
		printf("\n Error.");
		exit(1);
	}
	
	for(int i=0; i<dim; i++){
		array[i] = 1.0 + ((float)rand() / RAND_MAX) * (100.0 - 1.0); // Stampa numeri reali tra 1 e 100
	}
	
	return array;
}

void stampaArray(float *array, int dim){
	for(int i=0; i<dim; i++){
		printf(" %.2f ", array[i]);
	}
}

void maxmin(float *array, int dim, float *max, float *min){

	*max = array[0];
	*min = array[0];
	
	for(int i=1; i<dim; i++){
		if(array[i]>*max)
			*max = array[i];
		if(array[i]<*min)
			*min = array[i];			
	}
}


int main(){
	srand(time(NULL));
	int dim = 0;
	float *array, max= 0.0, min = 0.0;
	
	printf("\n Inserire dim -> ");
	scanf("%d", &dim);
	
	array = allocaArray(dim);
	stampaArray(array, dim);
	maxmin(array, dim, &max, &min);
	
	printf("\n\n Elemento massimo %.2f. ", max);
	printf("\n Elemento minimo %.2f. ", min);
		
	return 0;
}