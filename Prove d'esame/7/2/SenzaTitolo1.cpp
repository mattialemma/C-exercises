#include <stdio.h>
#include <stdlib.h>

typedef struct Persona {
    int matricola;
    int eta;
    char istruzione[30];
} Persona;

typedef struct Lista {
    Persona p;
    struct Lista *next;
} Lista;

Lista *creaNodo(Persona p) {
    Lista *nodo = (Lista *)malloc(sizeof(Lista));
    if (nodo == NULL)
        return NULL;
    nodo->p = p;
    nodo->next = NULL;
    return nodo;
}

Lista *inCoda(Lista *testa, Persona p) {
    Lista *nodo = creaNodo(p);
    if (testa == NULL)
        return nodo;
    Lista *current = testa;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = nodo;
    return testa;
}

void scriviFile(Lista *testa, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("\n Errore apertura file! ");
        exit(1);
    }
    Lista *current = testa;
    while (current != NULL) {
        fprintf(file, "%d\n%d\n%s\n", current->p.matricola, current->p.eta, current->p.istruzione);
        current = current->next;
    }
    fclose(file);
    printf("\n File scritto correttamente! ");
}

void leggiFile(const char *filename) {
    Persona p;
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\n Errore apertura file! ");
        exit(1);
    }
    printf("\n Lettura dal file: ");
    while (fscanf(file, "%d\n%d\n%s\n", &p.matricola, &p.eta, p.istruzione) == 3) {
        printf("\n\n Matricola: %d. \n Eta': %d. \n Istruzione: %s. ", p.matricola, p.eta, p.istruzione);
    }
    fclose(file);
    printf("\n Fine file. \n File letto correttamente! ");
}

int main() {
    Lista *testa = NULL;
    Persona p;
    int n = 0;

    printf("\n Quante persone vuoi inserire? \n -> ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n Inserimento persona %d. ", i + 1);
        printf("\n Inserire matricola -> ");
        scanf("%d", &p.matricola);
        printf("\n Inserire eta' -> ");
        scanf("%d", &p.eta);
        printf("\n Inserire istruzione -> ");
        scanf("%s", p.istruzione);
        testa = inCoda(testa, p);
    }

    scriviFile(testa, "nuovo.txt");
    leggiFile("nuovo.txt");

    return 0;
}

