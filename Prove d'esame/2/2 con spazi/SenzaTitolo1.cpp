#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	int matricola;
	int salario;
}Persona;

int main(){
	FILE *file = fopen("salario.txt", "r");
	if(!file){
		printf("\n Errore apertura file!");
		return 1;
	}
	
	Persona p;
	Persona pMax = {"", 0, 0};
	
	while(fscanf(file, "%[^\n] %d %d", p.nome, &p.matricola, &p.salario)==3){
		printf("\n\n Nome e Cognome: %s. \n Matricola: %d. \n Salario: %d. ", p.nome, p.matricola, p.salario);
		fgetc(file);
		
		if(p.salario > pMax.salario)
			pMax = p;
	}
	fclose(file);
	
	printf("\n\n - - - - - \n Persona con salario massimo: ");
	printf("\n Nome e Cognome: %s \n Matricola: %d \n Salario: %d Euro. ", pMax.nome, pMax.matricola, pMax.salario);		
	
	return 0;
}


