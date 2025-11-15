// Partition
#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void partition(int v[], int n, int idx_k) {
    // Scambio l'ultimo elemento con quello in posizione idx_k
    swap(&v[idx_k], &v[n-1]); // adesso l'ultimo elemento conterrà il valore k
    int idx_store = 0; // indice del primo elemento >= di k. Ipotizzo sia 0

    // Partizione dell'array in due sezioni: valori < v[n-1] e >= v[n-1]
    for (int i = 0; i < n-1; i++) {
        if (v[i] < v[n-1]) {
            swap(&v[i], &v[idx_store]);
            idx_store++; // dopo lo scambio, v[idx_store] sarà < di v[n-1],
                         // quindi si ipotizza che il successivo sia >= v[n-1]
        }
    }

    // Infine, metto il valore v[n-1] nella posizione corretta
    swap(&v[n-1], &v[idx_store]);
}

int main() {
    int v[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(v)/sizeof(v[0]);
    int idx_k = 4; // scelta arbitraria dell'indice di k (per esempio v[4] == 12)

    partition(v, n, idx_k);

    // Stampa l'array dopo la partizione
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
