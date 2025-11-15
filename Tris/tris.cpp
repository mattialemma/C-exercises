#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char matrice[3][3];
    char vincitore;
    int punteggio;
} Tris;

typedef struct Lista {
    Tris t;
    struct Lista *next;
} Lista;

// Funzione per creare un nuovo nodo
Lista *creaNodo(Tris t) {
    Lista *nodo = (Lista *)malloc(sizeof(Lista));
    if (nodo == NULL)
        return NULL;

    nodo->t = t;
    nodo->next = NULL;
    return nodo;
}

// Funzione per aggiungere un nodo alla fine della lista
Lista *inCoda(Lista *testa, Tris t) {
    Lista *nodo = creaNodo(t);
    if (testa == NULL)
        return nodo;

    Lista *current = testa;
    while (current->next != NULL)
        current = current->next;
    current->next = nodo;
    return testa;
}

// Funzione per contare le posizioni libere ('@') nella matrice
int free_position(char campo[3][3]){
    int pos = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (campo[i][j] == '@')
                pos++;
        }
    }
    return pos;
}

// Funzione per calcolare il punteggio di una partita
int match_score(char campo[3][3], char vincitore) {
    if (vincitore == 'N')
        return 0;
    
    int pos = free_position(campo);
    return 3 + pos;
}

// Funzione per determinare il vincitore della partita
char determinaVincitore(char campo[3][3]) {
    // Controlla righe e colonne
    for (int i = 0; i < 3; i++) {
        if (campo[i][0] == campo[i][1] && campo[i][1] == campo[i][2] && campo[i][0] != '@')
            return campo[i][0]; // Riga vincente
        if (campo[0][i] == campo[1][i] && campo[1][i] == campo[2][i] && campo[0][i] != '@')
            return campo[0][i]; // Colonna vincente
    }

    // Controlla diagonali
    if (campo[0][0] == campo[1][1] && campo[1][1] == campo[2][2] && campo[0][0] != '@')
        return campo[0][0]; // Diagonale principale
    if (campo[0][2] == campo[1][1] && campo[1][1] == campo[2][0] && campo[0][2] != '@')
        return campo[0][2]; // Diagonale secondaria

    // Nessun vincitore
    return 'N';
}

// Funzione per caricare le partite da un file
Lista *load_matches_from_file(Lista *testa, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\nErrore apertura file!\n");
        exit(1);
    }

    Tris t;
    int partita = 1;
    char riga[10]; // Per leggere una riga di 9 caratteri + terminatore di stringa

    while (fscanf(file, "%9s", riga) == 1) {
        // Riempie la matrice 3x3
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                t.matrice[i][j] = riga[k++];
            }
        }

        // Calcola il vincitore
        t.vincitore = determinaVincitore(t.matrice);

        // Imposta il punteggio (ad esempio: 1 per vittoria, 0 per nessun vincitore)
        t.punteggio = match_score(t.matrice, t.vincitore);

        // Aggiungi alla lista
        testa = inCoda(testa, t);

        // Stampa il vincitore (debug)
        printf("Partita %d: ", partita++);
        if (t.vincitore == 'N') {
            printf("Nessun vincitore\n");
        } else {
            printf("Vincitore: %c\n", t.vincitore);
        }
    }

    fclose(file);
    return testa;
}

// Funzione per stampare una partita
void printMatch(Tris t) {
    printf("\nMatrice:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c", t.matrice[i][j]);
        }
        printf("\n");
    }

    printf("Vincitore: %c\n", t.vincitore);
    printf("Punteggio: %d\n", t.punteggio);
}

// Funzione ricorsiva per stampare tutte le partite
void stampaRicorsiva(Lista *testa) {
    if (testa == NULL)
        return;

    printMatch(testa->t);
    stampaRicorsiva(testa->next);
}

// Funzione per rimuovere le partite senza vincitore
Lista *rimuoviSenzaVincitore(Lista *testa) {
    Lista *current = testa;
    Lista *prev = NULL;

    while (current != NULL) {
        if (current->t.vincitore == 'N') {
            // Nodo da eliminare
            if (prev == NULL) {
                // Nodo da eliminare è la testa
                testa = current->next;
                free(current);
                current = testa;
            } else {
                // Nodo intermedio o finale
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            // Passa al prossimo nodo
            prev = current;
            current = current->next;
        }
    }
    return testa;
}

// Funzione per scrivere le partite vinte da un giocatore nel file
void write_winners_on_file(Lista *testa, const char *filename, char c) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Errore creazione file");
        exit(EXIT_FAILURE);  // Usa EXIT_FAILURE per indicare un errore nell'uscita del programma
    }

    fprintf(file, "\nEcco le partite dove vince %c:\n", c);  // Messaggio introduttivo
    Lista *current = testa;

    // Scorri la lista per trovare le partite vinte da 'c'
    while (current != NULL) {
        if (current->t.vincitore == c) {
            // Stampa la matrice della partita nel file
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    fprintf(file, "%c ", current->t.matrice[i][j]);  // Stampa ogni carattere separato da uno spazio
                }
                fprintf(file, "\n");
            }
            fprintf(file, "\n");
        }
        current = current->next;  // Avanza al nodo successivo
    }

    fclose(file);  // Chiudi il file
}

int main() {
    Lista *testa = NULL;

    // Carica le partite da file
    testa = load_matches_from_file(testa, "tris.txt");

    // Stampa tutte le partite
    printf("\nTutte le partite:\n");
    stampaRicorsiva(testa);

    // Rimuovi le partite senza vincitore
    testa = rimuoviSenzaVincitore(testa);

    // Stampa tutte le partite rimanenti
    printf("\nPartite rimanenti:\n");
    stampaRicorsiva(testa);

    // Scrivi le partite vinte da '0' e da 'X' nei rispettivi file
    write_winners_on_file(testa, "zwin.txt", '0');
    write_winners_on_file(testa, "xwin.txt", 'X');

    return 0;
}
