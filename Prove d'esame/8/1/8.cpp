#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct giocatore{
	int ngiocatore;
	int punti;	
};

int lancioDado(){
	int numero = rand() % 6 +1;
	return numero;
}





int main(){
	srand(time(NULL));
	int p=0, n=0, punteggio=0, dado=0;
	
	printf("\n Inserisci il numero di giocatori -> ");
	scanf("%d", &p);
	
	printf("\n Inserisci il numero di caselle -> ");
	scanf("%d", &n);
	
	giocatore *array = (giocatore*)malloc(p*sizeof(giocatore));
	
	 for(int i=0; i<p; i++)
	 	array[i].ngiocatore = i+1;
	
	int i=0, turno=0, winner=0;
	while(punteggio < n){
		turno++;
		printf("\n\n Turno numero %d", turno);
		
		dado = lancioDado();
		printf("\n Il numero uscito e': %d. ", dado);
		
		array[i].punti += dado;
		punteggio = array[i].punti;
		
		printf("\n Il giocatore %d ha un punteggio di %d. ", array[i].ngiocatore, punteggio);
		winner = array[i].ngiocatore;
		
		if(i==p-1)
			i=0;	
		else
			i++;
	}
	
	printf("\n\n Il giocatore %d ha vinto con %d punti! ", winner, punteggio);
	
	
	return 0;
}