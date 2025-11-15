#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// Questo programma fa anche il massimo oltre al minimo

void minMax(const char *stringa) {
    int len = strlen(stringa);
    int min = len + 1, max = 0, counter;
    char carattereMin, carattereMax;

    for (int i = 0; i < len; i++) {
        counter = 0;

        // Conta le occorrenze del carattere attuale
        for (int j = 0; j < len; j++) {
            if (stringa[i] == stringa[j])
                counter++;
        }

        // Aggiorniamo il minimo e il massimo correttamente
        if (counter < min) {
            min = counter;
            carattereMin = stringa[i];
        }
        if (counter > max) {
            max = counter;
            carattereMax = stringa[i];
        }
    }

    printf("\n Il carattere con frequenza minima: '%c' (ripetuto %d volte)", carattereMin, min);
    printf("\n Il carattere con frequenza massima: '%c' (ripetuto %d volte)", carattereMax, max);
}

int main() {
    // Inizializzazione variabili
    int dim = 0;
    srand(time(NULL));

    // Inserimento della dimensione
    printf("\n Inserisci la dimensione -> ");
    scanf("%d", &dim);

    // Creazione e analisi della stringa
    for (int i = 0; i < dim; i++) {
        int dimA = rand() % 10 + 1; // Lunghezza casuale tra 1 e 10
        char *stringa = (char*)malloc((dimA + 1) * sizeof(char));

        if (stringa == NULL) {
            printf("Errore di allocazione della memoria\n");
            return 1; // Termina il programma in caso di errore
        }

        for (int j = 0; j < dimA; j++) {
            stringa[j] = 'A' + rand() % 26; // Genera lettere casuali
        }
        stringa[dimA] = '\0';

        printf("\n Stringa generata: %s", stringa);

        // Trova il minimo e massimo
        minMax(stringa);

        // Libera la memoria allocata
        free(stringa);
    }

    return 0;
}


