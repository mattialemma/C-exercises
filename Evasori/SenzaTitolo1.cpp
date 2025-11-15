#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char CF[20];
    int *introiti;
    int num_introiti;
} Contribuente;

typedef struct Lista {
    Contribuente c;
    struct Lista *next;
} Lista;

Lista *creaNodo(Contribuente c) {
    Lista *nodo = (Lista*)malloc(sizeof(Lista));
    if (nodo == NULL)
        return NULL;
    
    nodo->c = c;
    nodo->next = NULL;
    return nodo;
}

Lista *push(Lista *testa, Contribuente c) {
    Lista *nodo = creaNodo(c);
    if (nodo == NULL)
        return testa;

    if (testa == NULL)
        return nodo;

    Lista *current = testa;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = nodo;
    return testa;
}

Lista *pop(Lista *testa, Contribuente *c) {
    if (testa == NULL)
        return NULL;

    Lista *tmp = testa;
    *c = tmp->c;

    testa = tmp->next;

    free(tmp->c.introiti);  
    free(tmp);

    return testa;
}

int verifica(Lista *testa, const char *cf) {
    if (testa == NULL)
        return 0;

    Lista *current = testa;
    while (current != NULL) {
        if (strcmp(cf, current->c.CF) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

Lista *load(Lista *testa, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\nErrore apertura file!\n");
        exit(1);
    }

    Contribuente c;
    int introitoTMP = 0;

    while (fscanf(file, "%s%d", c.CF, &introitoTMP) == 2) {
        if (verifica(testa, c.CF) == 0) {  // Nuovo contribuente
            c.introiti = (int*)malloc(sizeof(int));
            if (c.introiti == NULL) {
                printf("\nErrore allocazione memoria!\n");
                exit(1);
            }
            c.introiti[0] = introitoTMP;
            c.num_introiti = 1;
            testa = push(testa, c);
        } else {  // Riallocazione per contribuente esistente
            Lista *current = testa;
            while (current != NULL && strcmp(current->c.CF, c.CF) != 0) {
                current = current->next;
            }

            if (current != NULL) {  // Se trovato, rialloco
                int newSize = current->c.num_introiti + 1;
                current->c.introiti = (int*)realloc(current->c.introiti, newSize * sizeof(int));
                if (current->c.introiti == NULL) {
                    printf("\nErrore riallocazione memoria!\n");
                    exit(1);
                }
                current->c.introiti[newSize - 1] = introitoTMP;
                current->c.num_introiti = newSize;
            }
        }
    }
    fclose(file);
    return testa;
}

void stampaRicorsiva(Lista *testa) {
    if (testa == NULL)
        return;

    printf("\nCodice Fiscale: %s", testa->c.CF);
    printf("\nIntroiti: ");
    for (int i = 0; i < testa->c.num_introiti; i++) {
        printf("%d ", testa->c.introiti[i]);
    }
    printf("\n");

    stampaRicorsiva(testa->next);
}

void separaEvasori(Lista **testa, Lista **evasori, Lista **contribuenti) {
	int somma = 0;
    while (*testa != NULL) {
        Contribuente c;

	*testa = pop(*testa, &c);
        for (int i = 0; i < c.num_introiti; i++) {
            somma += c.introiti[i];
        }
        printf("somma %d", somma);
        if (somma >= 5000) {
            *evasori = push(*evasori, c);
        } else {
            *contribuenti = push(*contribuenti, c);
        }
        somma = 0;
    }
}

void stampaEvasoriSuFile(Lista *evasori, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("\nErrore apertura file!\n");
        return;
    }

    while (evasori != NULL) {
        int totale = 0;
        fprintf(file, "Codice Fiscale: %s\n", evasori->c.CF);
        fprintf(file, "Introiti: ");

        for (int i = 0; i < evasori->c.num_introiti; i++) {
            fprintf(file, "%d ", evasori->c.introiti[i]);
            totale += evasori->c.introiti[i];
        }

        fprintf(file, "\nTotale: %d\n\n", totale);
        evasori = evasori->next;
    }

    fclose(file);
    printf("\nLista evasori salvata su %s\n", filename);
}


void liberaLista(Lista *testa) {
    while (testa != NULL) {
        Lista *tmp = testa;
        free(testa->c.introiti);  // Libera l'array
        testa = testa->next;
        free(tmp);  // Libera il nodo
    }
}

int main() {
    Lista *testa = NULL;
    Lista *evasori = NULL, *contribuenti = NULL;

    testa = load(testa, "file.txt");
    stampaRicorsiva(testa);
    separaEvasori(&testa, &evasori, &contribuenti);

    printf("\n--- Lista contribuenti ---\n");
    stampaRicorsiva(contribuenti);
    printf("\n--- Lista evasori ---\n");
    stampaRicorsiva(evasori);
    stampaEvasoriSuFile(evasori, "evasori.txt");

    // Libera la memoria
    liberaLista(contribuenti);
    liberaLista(evasori);

    return 0;
}