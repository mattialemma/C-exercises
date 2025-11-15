// Selection sort iterativo
#include <stdio.h>

// Funzione per trovare l'indice del minimo elemento in un array a partire da una posizione
int idx_min_array(float v[], int n, int start) {
    int idx_min = start;
    float min = v[start];
    for (int i = start + 1; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
            idx_min = i;
        }
    }
    return idx_min;
}

// Funzione per ordinare un array usando l'algoritmo Selection Sort
void selection_sort(float v[], int n) {
    int idx_min;
    for (int i = 0; i < n - 1; i++) { // n-1, perché l'ultimo elemento sarà già ordinato
        idx_min = idx_min_array(v, n, i);
        float tmp = v[i];
        v[i] = v[idx_min];
        v[idx_min] = tmp;
    }
}

// Funzione principale per testare l'algoritmo
int main() {
    float v[] = {29.5, 10.2, 14.7, 37.3, 13.4, 25.1, 7.8, 3.6, 20.9, 50.0};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Array originale:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    selection_sort(v, n);

    printf("Array ordinato:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    return 0;
}
