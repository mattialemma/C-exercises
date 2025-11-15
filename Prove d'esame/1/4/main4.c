#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct {
	int x;
	int y;
}Coordinate;

void lanciaBoccia(Coordinate *boccino){
	boccino->x = rand()%100+1;
	boccino->y = rand()%100+1;
} 

float calcolaDistanza(int x1, int y1, int x2, int y2){
	
	float distanza = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));

	return distanza;
}



int main(){
	srand(time(NULL));
	Coordinate boccino, boccia1, boccia2;
	
	float p1 = 0.0, p2 = 0.0, totP1 = 0.0, totP2 = 0.0;
	
	for(int i=0; i<3; i++){	
		lanciaBoccia(&boccino);
		printf("\n\n - - - - - - \n Manche %d. \n Coordinate boccino: \n x: %d. \n y: %d. ", i+1, &boccino.x, &boccino.y);
		
		lanciaBoccia(&boccia1);
		printf("\n\n Coordinate boccia 1: \n x: %d. \n y: %d. ", &boccia1.x, &boccia1.y);	
		
		lanciaBoccia(&boccia2);
		printf("\n\n Coordinate boccia 2: \n x: %d. \n y: %d. ", &boccia2.x, &boccia2.y);	
		
		p1 = calcolaDistanza(boccino.x, boccino.y, boccia1.x, boccia1.y);
		p2 = calcolaDistanza(boccino.x, boccino.y, boccia2.x, boccia2.y);
		totP1 += p1; 
		totP2 += p2;
		
		if(p1>p2)
			printf("\n Manche vinta da G1. ");
		else
			printf("\n Manche vinta da G2. ");
	}
		if(totP1>totP2)
			printf("\n\n - - - - - - \n Partita vinta da G1. ");
		else
			printf("\n\n - - - - - - \n Partita vinta da G2. ");
	
	return 0;
}