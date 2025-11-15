#include <stdio.h>

// Funzione per stampare il vettore con eventuali indici evidenziati
void stampa_vett(int v[], int n, int idx, int idx2) {
    printf("Indici: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("]\nValori: ( ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf(")\n");

    if (idx >= 0) {
        printf("Idx_store: ");
        for (int i = 0; i < idx; i++) {
            printf("  ");
        }
        printf("^\n");
    }

    if (idx2 >= 0) {
        printf("Idx_iter: ");
        for (int i = 0; i < idx2; i++) {
            printf("  ");
        }
        printf("*\n");
    }
}

// Funzione per scambiare due valori
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Funzione per effettuare la partizione (versione di Lomuto)
void partition(int v[], int n, int idx_k) {
    printf("Stato iniziale:\n");
    stampa_vett(v, n, -1, -1);

    printf("Inizio partizione rispetto a: %d (posizione %d)\n", v[idx_k], idx_k);
    printf("Preparazione: scambio posizione %d con posizione %d\n", idx_k, n - 1);

    // Scambio l'ultimo elemento con quello in posizione idx_k
    swap(&v[idx_k], &v[n - 1]);
    stampa_vett(v, n, -1, -1);

    int idx_store = 0; // Indice del primo elemento >= pivot

    for (int i = 0; i < n - 1; i++) {
        printf("Iterazione: %d\n", i + 1);
        stampa_vett(v, n, idx_store, i);

        if (v[i] < v[n - 1]) { // Se v[i] < pivot
            printf("%d < %d! ", v[i], v[n - 1]);
            printf("Scambio %d con %d.\n", v[i], v[idx_store]);
            swap(&v[i], &v[idx_store]);
            idx_store++; // Avanza l'indice di memorizzazione
            printf("Dopo lo scambio:\n");
            stampa_vett(v, n, idx_store, i);
        }
    }

    printf("Ciclo terminato! Prima dell'ultimo scambio:\n");
    stampa_vett(v, n, idx_store, n - 1);

    // Metto il pivot nella posizione corretta
    swap(&v[n - 1], &v[idx_store]);

    printf("Dopo ultimo scambio: stato finale:\n");
    stampa_vett(v, n, -1, -1);
    printf("Fine partizione.\n");
}

// Funzione principale per testare il codice
int main() {
    int v[] = {1, 4, 5, 2, 6, 3, 8};
    int n = sizeof(v) / sizeof(v[0]);
    int idx_val = 2;

    partition(v, n, idx_val);

    return 0;
}
