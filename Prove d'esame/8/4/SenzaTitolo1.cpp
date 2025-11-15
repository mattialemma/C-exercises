#include <stdio.h>
#include <stdlib.h>
#define N 20

void leggiScriviFile(const char *filename, const char *filename2){
	
	FILE *file = fopen(filename, "r"); // Apertura file 1
	if(!file){
		printf("\n Errore apertura file!");
		exit(1);
	}
	
	int dim = 0;
	while(fscanf(file,"%d",&dim)==1){}; // Lettura dimensione (quanti nomi e cognomi sono presenti nel file) per allocazione di array nome e cognome
	printf("\n Ho letto %d nomi! ", dim);
	
	// Array nome
	char **nome = (char**)malloc(dim*sizeof(char*));
	if(nome == NULL){
		printf("\n Error");
		exit(1);
	}
	for(int i=0; i<N; i++){
		nome[i] = (char*)malloc(N*sizeof(char));
		if(nome[i] == NULL){
			printf("\n Error");
			exit(1);
		}
	}
	
	// Array cognome
	char **cognome = (char**)malloc(dim*sizeof(char*));
	if(cognome == NULL){
		printf("\n Error");
		exit(1);
	}
	for(int i=0; i<N; i++){
		cognome[i] = (char*)malloc(N*sizeof(char));
		if(cognome[i] == NULL){
			printf("\n Error");
			exit(1);
		}
	}
	
	int a=0; // Lettura nome e cognome da file e popolamento dei due array
	while(fscanf(file,"%s %s", nome[a], cognome[a])==2){
		printf("\n Nome: %s. \n Cognome: %s. ", nome[a], cognome[a]);
		a++;
	}
		
	fclose(file); // Chiusura file 1
	
	FILE *file2 = fopen(filename2, "w"); // Apertura file 2
	if(!file){
		printf("\n Error");
		exit(1);
	}
	
	for(int i=0; i<dim; i++){ // Stampa su file 2
		for(int j=0; j<dim; j++){
			fprintf(file2,"\n %s %s", nome[i], cognome[j]);
		}
	}
	fclose(file); // Chiusura file 2
}



int main(){
	
	leggiScriviFile("nomi.txt", "nuovo.txt"); // Richiamo la funzione
	

	return 0;
}