#include "funzioni.h"

int main() {
    Coda c;
    Post p;
    int scelta = 0;

    inizializza(&c);
    vuoto(&c);
    leggiFile(&c, "testo.txt");
    vuoto(&c);

    do {
        if (pop(&c, &p) == -1) {
            printf("\nCoda vuota!");
            break;
        } else {
            printf("\n - - - \nTesto: %s\nLike: %d.", p.msg, p.nLike);
        }

        printf("\n\nVuoi vedere il prossimo post o mettere like? \n1 = PROSSIMO | 0 = STOP | 2 = LIKE | 3 = CONDIVIDI\n-> ");
        scanf("%d", &scelta);

        if (scelta == 2) {
            p.nLike++;
            printf("\nLike attuali: %d", p.nLike);
        }

        if (scelta == 3) {
            stampaFile(p, "condivisione.txt");
            printf("\nPost condiviso con successo!");
        }

    } while (scelta != -1);

    return 0;
}


