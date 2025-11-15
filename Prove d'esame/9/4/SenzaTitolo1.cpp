#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *allocaArray(int *array, int num, int *dim){
	int *tmp = (int*)realloc(array, (*dim+1)*sizeof(int));
	if(tmp == NULL){
		printf("\n Error! ");
		exit(1);
	}
	array = tmp;
	++*dim;
	array[*dim-1] = num;
	return array;
}

int main(){
	int num = 0, dim = 0;
	int *array = NULL;
	
	do{
		printf("\n Inserire elemento o premere -1 per stoppare. \n -> ");
		scanf("%d", &num);
		if(num!=-1)
			array = allocaArray(array, num, &dim);
	}while(num != -1);
	
	for(int i=0; i<dim; i++){
		printf("| %d", array[i]);
	}
	
	return 0;
}