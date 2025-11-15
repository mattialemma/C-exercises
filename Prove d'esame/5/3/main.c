#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *stringa = (char*)malloc(40 * sizeof(char));
    if (stringa == NULL) {
        printf("\nErrore allocazione!\n");
        return 1;
    }
	
	printf("\n Inserire la stringa -> ");
    scanf("%s", stringa);
    printf("\n%s\n", stringa);

    int max = 1, lungCorr = 1;
	
    // Iterazione attraverso la stringa per trovare la lunghezza della sottosequenza più lunga
    for (int i = 0; stringa[i] != '\0'; i++) {
        // Confronta l'elemento corrente con il successivo, ma evita l'overflow
        if (stringa[i] == stringa[i + 1]) {
            lungCorr++;
        } else {
            if (lungCorr > max) {
                max = lungCorr;
            }
            lungCorr = 1;  // Resetta la lunghezza corrente
        }
    }

    // Dopo il ciclo, verifica l'ultima sottosequenza
    if (lungCorr > max)
        max = lungCorr;

    printf("\nLa lunghezza massima della sottosequenza di caratteri uguali consecutivi è: %d.\n", max);

    free(stringa);  // Liberazione della memoria allocata dinamicamente

    return 0;
}
