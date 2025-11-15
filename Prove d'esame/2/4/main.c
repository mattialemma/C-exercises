#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int puntiG1 = 0, puntiG2 = 0, totPuntiG1 = 0, totPuntiG2 = 0;
    int numero = 0;
    float probabilitaErrore = 0.05; // Probabilità iniziale di errore (5%)

    for (int i = 0; i < 3; i++) { // 3 GAMES
        printf("\nGAME %d:\n", i + 1);
        puntiG1 = 0; // Reset punteggio per ogni game
        puntiG2 = 0; // Reset punteggio per ogni game
        probabilitaErrore = 0.05; // Reset probabilità di errore per ogni game

        while (puntiG1 < 11 && puntiG2 < 11) { // La partita finisce quando uno dei due arriva a 11
            for (int j = 0; j < 2; j++) { // Ogni giocatore tira una volta
                numero = (rand() % 11 + 1); // Genera un numero tra 1 e 11
               // float errore = (rand() % 100) / 100.0; // Genera un numero casuale tra 0 e 1 per simulare l'errore
               float errore = (rand()/RAND_MAX)*(1+0)-0; 

                if (errore > probabilitaErrore) { // Se errore è maggiore della probabilità di errore, il giocatore colpisce
                    if (numero % 2 == 0) // Se il numero è pari, vince G1
                        puntiG1++;
                    else // Se il numero è dispari, vince G2
                        puntiG2++;
                } else { // Se errore è minore della probabilità, il giocatore sbaglia
                    if (numero % 2 == 0) // Se G1 sbaglia, G2 guadagna il punto
                        puntiG2++;
                    else // Se G2 sbaglia, G1 guadagna il punto
                        puntiG1++;
                }

                probabilitaErrore += 0.05; // Aumenta la probabilità di errore del 5% dopo ogni scambio
            }
        }

        // Aggiornamento dei totali per ogni partita
        totPuntiG1 += puntiG1;
        totPuntiG2 += puntiG2;

        // Risultato del game
        printf("I punti di G1 sono %d, quelli di G2 sono %d.\n", puntiG1, puntiG2);
        if (puntiG1 > puntiG2)
            printf("Ha vinto G1 questo game.\n");
        else
            printf("Ha vinto G2 questo game.\n");
    }

    // Risultati totali dopo 3 games
    printf("\nTotale punti G1: %d, Totale punti G2: %d.\n", totPuntiG1, totPuntiG2);
    if (totPuntiG1 > totPuntiG2)
        printf("G1 ha vinto il torneo!\n");
    else
        printf("G2 ha vinto il torneo!\n");

    return 0;
}
