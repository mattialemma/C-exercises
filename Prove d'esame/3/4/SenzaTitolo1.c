#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100  // Dimensione massima della matrice

// Funzione per verificare se una cella è adiacente a un'altra cella con valore 1
int has_adjacent_one(int matrix[MAX_N][MAX_N], int N, int i, int j) {
    // Controlla le celle adiacenti (8 direzioni)
    int directions[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // Su, giù, sinistra, destra
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // Diagonali
    };

    for (int d = 0; d < 8; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];

        // Verifica che l'indice sia valido
        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
            if (matrix[ni][nj] == 1) {
                return 1;  // C'è un adiacente con valore 1
            }
        }
    }

    return 0;  // Nessun adiacente con valore 1
}

int main() {
    int N;

    // Richiesta della dimensione della matrice
    printf("Inserisci la dimensione della matrice NxN: ");
    scanf("%d", &N);

    // Verifica che la dimensione sia valida
    if (N <= 0 || N > MAX_N) {
        printf("Dimensione non valida. Deve essere tra 1 e %d.\n", MAX_N);
        return -1;
    }

    // Creazione della matrice booleana
    int matrix[MAX_N][MAX_N];

    // Inizializzazione della matrice con valori casuali 0 o 1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 2;  // Valore 0 o 1
        }
    }

    // Salvataggio della matrice in un file binario
    FILE *file = fopen("matrice.bin", "wb");
    if (file == NULL) {
        printf("Errore nell'aprire il file.\n");
        return -1;
    }

    fwrite(&N, sizeof(int), 1, file);  // Scrive la dimensione della matrice
    fwrite(matrix, sizeof(int), N * N, file);  // Scrive i dati della matrice
    fclose(file);

    printf("Matrice salvata nel file 'matrice.bin'.\n");

    // Caricamento della matrice dal file
    file = fopen("matrice.bin", "rb");
    if (file == NULL) {
        printf("Errore nell'aprire il file.\n");
        return -1;
    }

    fread(&N, sizeof(int), 1, file);  // Legge la dimensione della matrice
    fread(matrix, sizeof(int), N * N, file);  // Legge i dati della matrice
    fclose(file);

    // Verifica delle celle che contengono 1 e non hanno adiacenti con valore 1
    printf("Celle che contengono 1 senza celle adiacenti con valore 1:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1 && !has_adjacent_one(matrix, N, i, j)) {
                printf("Matrice[%d][%d] = 1\n", i, j);
            }
        }
    }

    return 0;
}
