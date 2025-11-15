#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	char cognome[20];
	int matricola;
	int salario;
}Persona;


int main() {
	FILE *file = fopen("salario.txt", "r");
	if(!file){
		printf("\n Errore apertura file! ");
		exit(EXIT_FAILURE);
	}
		
		
	Persona pMax = {"", "", 0, 0};
	Persona pCorrente;
	
    while (fscanf(file, "%s %s %d %d", pCorrente.nome, pCorrente.cognome, &pCorrente.matricola, &pCorrente.salario) == 4) {
        printf("%s %s %d %d\n", pCorrente.nome, pCorrente.cognome, pCorrente.matricola, pCorrente.salario);

        if (pCorrente.salario > pMax.salario) {
            pMax = pCorrente;
        }
    }
	fclose(file);
	
	printf("\n\n - - - - - \n Persona con salario massimo: ");
	printf("\n Nome e Cognome: %s %s \n Matricola: %d \n Salario: %d Euro. ", pMax.nome, pMax.cognome, pMax.matricola, pMax.salario);
	
	return 0;
}