#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char msg[256];
    int nLike;
} Post;

typedef struct {
    Post array[MAX];
    int indice;
} Coda;

void inizializza(Coda *c);
int push(Coda *c, Post elemento);
int pop(Coda *c, Post *post);
int lunghezza(Coda *c);
void vuoto(Coda *c);
void leggiFile(Coda *c, const char *filename);
void stampaFile(Post p, const char *filename);

#endif
