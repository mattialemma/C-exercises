#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 

void stampa_ricorsiva(int arr[], int index, int size, int *duplicato) {
    if (index == size) {
        return;  // Caso base: raggiunta la fine della sequenza
    }

    // Controllo se l'elemento corrente è un duplicato
    for (int i = 0; i < index; i++) {
        if (arr[i] == arr[index]) {
            *duplicato = 1;  // Se trova un duplicato, setta la variabile
            break;
        }
    }

    // Stampa l'elemento al contrario
    
    stampa_ricorsiva(arr, index + 1, size, duplicato);
    printf("%d ", arr[index]);
    return 0;
}

int main(){
	srand(time(NULL));
	int array[N];
	int duplicato = 0;
	
	for(int i=0; i<N; i++)
		array[i] = (rand()%11)+10;
	
	printf("\n Array di partenza: ");
	for(int i=0; i<N; i++)
		printf(" %d", array[i]);
	
	printf("\n Array al contrario: ");
	stampa_ricorsiva(array, 0, N, &duplicato);
	
	if(duplicato)
		printf("\n Ci sono duplicati! ");
	else
		printf("\n Non ci sono duplicati! ");
	
	
	return 0;
}
