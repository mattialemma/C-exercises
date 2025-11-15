#include <stdio.h>
#include <stdlib.h>

// Divisore parte da numero e ad ogni chiamata ricorsiva viene decrementato di 1
void divisori(int numero, int divisore){
	if(divisore == 0) // Caso base
		return;
	
	if((numero%divisore)==0)
		printf("\n Il numero %d e' un divisore. ", divisore); // Stampa il divisore
	
	divisori(numero, divisore-1); // Decremento di 1
}




int main(){
	int numero = 0;
	
	printf("\n Inserisci il numero -> "); // Inserisci il dividendo
	scanf("%d", &numero);
	
	int divisore = numero; 
	divisori(numero, divisore); // Chiamata funzione
	
	
	return 0;
}