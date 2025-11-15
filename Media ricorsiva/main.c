#include <stdio.h>
#include <stdlib.h>
#define DIM 5

// Media ricorsiva di un array
float media(int array[], int dim, int counter, int somma){
    if(counter == dim)
        return ((float)somma / dim); // Assicurati di fare una divisione in virgola mobile
    
    somma += array[counter];
    return media(array, dim, counter + 1, somma); // Usa counter + 1 per incrementare
}



int main() {
    int array[DIM] = {1, 2, 3, 4, 5};
    
    // Chiamata alla funzione ricorsiva per calcolare la media
    float result = media(array, DIM, 0, 0);
    
    // Stampa del risultato
    printf("\nMedia: %.3f\n", result);
    
    return 0;
}
