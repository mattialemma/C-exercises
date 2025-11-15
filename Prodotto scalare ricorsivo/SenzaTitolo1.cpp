#include <stdio.h>
#include <stdlib.h>

#define DIM 3

// 0 1 2
// 0 1 2
// 0*0 + 1*1 + 2*2


int funzione(int *arr1, int *arr2, int dim, int prodotto){
	if(dim == 0)
		return prodotto;
	
	prodotto += arr1[dim-1]*arr2[dim-1];
	
	return funzione(arr1, arr2, dim-1, prodotto);
}

int main(){
	int array1[DIM] = {1,2,3}, array2[DIM] = {1,0,3};
	int prodotto = 0;
	
	prodotto = funzione(array1, array2, DIM, 0);
	
	printf("\n %d. ", prodotto);
	
	return 0;
}


