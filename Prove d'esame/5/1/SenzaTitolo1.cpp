#include <stdio.h>
#include <stdlib.h>


void multiplo(float *array, int dim){
	int flag = 0;
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			if(i != j && (array[i]/array[j] == (int)(array[i]/array[j]))){
				printf("\n Il numero %.3f e' multiplo di %.3f! ", array[i], array[j]);
				flag = 1;
			}
		} 
	}
	if(flag == 0)
		printf("\n Non sono presenti multipli! ");
}

int main(){
	int dim = 0;
	
	
	printf("\n Inserire la dimensione -> ");
	scanf("%d", &dim);
	float *array = (float*)malloc(dim*sizeof(float));
	if(array == NULL){
		printf("\n Errore allocazione memoria! ");
		return 1;
	}
	
	for(int i=0; i<dim; i++){
		printf("\n Elemento %d -> ", i+1);
		scanf("%f", &array[i]);
	}
	
	multiplo(array, dim);
	
	
	return 0;
}