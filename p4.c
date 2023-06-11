#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct {
    char nr_inmat[10];
    char marca[30];
    char culoare[10];
    int combustibil;
} masini;

void insertQueue(Queue Q) {
    masini* m = malloc(sizeof(masini));
    printf("Introduceti numarul de inmatriculare:");
    scanf("%s", m->nr_inmat);
    printf("Introduceti marca:");
    scanf("%s", m->marca);
    printf("Introduceti culoarea:");
    scanf("%s", m->culoare);
    printf("Introduceti tipul de combustibil (1 pentru benzina, 2 pentru motorina):");
    scanf("%d", &m->combustibil);
    enq(Q, m);
}

void extractQueue(Queue* Q) {
    masini* m = deq(Q);
    printf("Masina stearsa din coada are numarul de inmatriculare: %s\n", m->nr_inmat);
    printf("Masina stearsa din coada are marca: %s\n", m->marca);
    printf("Masina stearsa din coada are culoarea: %s\n", m->culoare);
    printf("Masina stearsa din coada are combustibilul: %d\n", m->combustibil);
    free(m);
}

void displayQueue(Queue* Q) {
    Queue aux = newQueue2();
    while (!isEmptyQueue(Q)) {
        masini* m = (masini*) front(Q);
        printf("%s %s %s %d\n", m->nr_inmat, m->marca, m->culoare, m->combustibil);
        enq(aux, m);
        deq(Q);
    }
    while (!isEmptyQueue(aux)) {
        enq(Q, deq(aux));
    }
    deleteQueue(aux);
}

void displayMasinipeBenzina(Queue Q) {
    Queue aux = newQueue2();
    while (!isEmptyQueue(Q)) {
        masini* m = (masini*) front(Q);
        if (m->combustibil == 1) {
            printf("%s %s %s %d\n", m->nr_inmat, m->marca, m->culoare, m->combustibil);
        }
        enq(aux, m);
        deq(Q);
    }
    while (!isEmptyQueue(aux)) {
        enq(Q, deq(aux));
    }
    deleteQueue(aux);
}

void displayMasinipeMotorina(Queue Q) {
    Queue aux = newQueue2();
    while (!isEmptyQueue(Q)) {
        masini* m = (masini*) front(Q);
        if (m->combustibil == 2) {
            printf("%s %s %s %d\n", m->nr_inmat, m->marca, m->culoare, m->combustibil);
        }
        enq(aux, m);
        deq(Q);
    }
    while (!isEmptyQueue(aux)) {
        enq(Q, deq(aux));
    }
    deleteQueue(aux);
}

int main() {
    Queue Q = newQueue2();
    int optiune = 0;
    int n;
    printf("Introduceti numarul de masini din coada:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        insertQueue(Q);
        printf("Masina adaugata in coada.\n");
    }
    do {
        printf("\nMenu:\n");
        printf("1. Adauga o masina la coada\n");
        printf("2. Elimina o masina din coada\n");
        printf("3. Afiseaza toate masinile din coada\n");
        printf("4. Afiseaza doar masinile pe benzina\n");
        printf("5. Afiseaza doar masinile pe motorina\n");
        printf("6. Afiseaza lungimea cozii\n");
        printf("7. Termina programul\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);
        switch (optiune) {
        case 1:
            insertQueue(Q);
            printf("Masina adaugata in coada.\n");
            break;
        case 2:
            extractQueue(Q);
            break;
        case 3:
            displayQueue(Q);
            break;
        case 4:
            displayMasinipeBenzina(Q);
            break;
        case 5:
            displayMasinipeMotorina(Q);
            break;
        case 6:
            printf("Lungimea cozii este: %d\n", sizeQueue(Q));
            break;
        case 7:
            printf("Terminat.\n");
            break;
        default:
            printf("Optiune gresita. Reincercati.\n");
        }
    } while (optiune != 7);

    deleteQueue(Q);

    return 0;
}
