// Merge sort
#include <stdio.h>
#define MAX_LEN 100

// Funzione per fondere due array ordinati in un array ordinato di output
void fondi(int v1[], int n1, int v2[], int n2, int v_out[], int* n_out) {
    int idx_v1 = 0;
    int idx_v2 = 0;
    int idx_v_out = 0;

    // Fondere i due array finché ci sono elementi in entrambi
    while (idx_v1 < n1 && idx_v2 < n2) {
        if (v1[idx_v1] < v2[idx_v2]) {
            v_out[idx_v_out] = v1[idx_v1];
            idx_v1++;
        } else {
            v_out[idx_v_out] = v2[idx_v2];
            idx_v2++;
        }
        idx_v_out++;
    }

    // Copiare gli elementi rimanenti di v1 (se presenti)
    if (idx_v1 < n1) {
        for (int i = idx_v1; i < n1; i++) {
            v_out[idx_v_out] = v1[i];
            idx_v_out++;
        }
    }

    // Copiare gli elementi rimanenti di v2 (se presenti)
    if (idx_v2 < n2) {
        for (int i = idx_v2; i < n2; i++) {
            v_out[idx_v_out] = v2[i];
            idx_v_out++;
        }
    }

    // Aggiornare la dimensione dell'array di output
    *n_out = idx_v_out;
}

// Funzione per copiare un array
void array_copy(int v[], int n, int out[]) {
    for (int i = 0; i < n; i++) {
        out[i] = v[i];
    }
}

// Funzione di ordinamento Merge Sort
void merge_sort(int v[], int n) {
    if (n <= 1) {
        return;
    }

    // Dividere l'array in due metà
    int mid = n / 2;

    // Ordinare ricorsivamente le due metà
    merge_sort(v, mid);
    merge_sort(v + mid, n - mid);

    // Fondere le due metà ordinate
    int out[MAX_LEN];
    int n_out;
    fondi(v, mid, v + mid, n - mid, out, &n_out);

    // Copiare l'array ordinato nella posizione originale
    array_copy(out, n_out, v);
}

// Funzione principale per testare l'algoritmo
int main() {
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Array originale:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    merge_sort(v, n);

    printf("Array ordinato:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
