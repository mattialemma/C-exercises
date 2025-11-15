#include "funzioni.h"

void inizializza(Coda *c) {
    c->indice = -1;
}

int push(Coda *c, Post elemento) {
    if (c->indice >= MAX - 1)
        return -1;

    c->indice++;
    c->array[c->indice] = elemento;

    return 0;
}

int pop(Coda *c, Post *post) {
    if (c->indice == -1)
        return -1;

    *post = c->array[0];
    for (int i = 0; i < c->indice; i++) {
        c->array[i] = c->array[i + 1];
    }
    c->indice--;
    return 0;
}

int lunghezza(Coda *c) {
    return c->indice + 1;
}

void vuoto(Coda *c) {
    if (c->indice == -1)
        printf("\nCoda vuota!");
    else
        printf("\nLa coda contiene %d post! ", lunghezza(c));
}

void leggiFile(Coda *c, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\nErrore apertura file!");
        exit(1);
    }
    Post p;
    while (fscanf(file, "%[^\n]%d", p.msg, &p.nLike) == 2) {
        fgetc(file);
        if (push(c, p) == -1)
            printf("\nCoda piena!");
        else
            printf("\nInserito!");
    }
    fclose(file);
}

void stampaFile(Post p, const char *filename) {
    FILE *file = fopen(filename, "a+");
    if (!file) {
        printf("\nErrore creazione file!");
        exit(1);
    }
    fprintf(file, " %s\n %d", p.msg, p.nLike);
    fclose(file);
}
