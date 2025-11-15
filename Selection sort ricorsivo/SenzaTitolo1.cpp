// Selection sort ricorsivo
#include <stdio.h>
#define MAX_LEN 15

// Funzione per trovare l'indice del minimo elemento in un array
int idx_min(int v[], int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[idx]) {
            idx = i;
        }
    }
    return idx;
}

// Funzione per scambiare due valori
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Funzione ricorsiva per ordinare l'array usando il selection sort
void selection_sort(int v[], int n) {
    if (n <= 1) {
        return;
    }
    int idx = idx_min(v, n);
    swap(&v[0], &v[idx]);
    selection_sort(v + 1, n - 1);
}

// Funzione principale per testare l'ordinamento
int main() {
    int v[MAX_LEN] = {64, 25, 12, 22, 11, 90, 44, 23, 10, 50, 7, 3, 5, 2, 1};
    int n = 15;

    printf("Array originale:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    selection_sort(v, n);

    printf("Array ordinato:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
