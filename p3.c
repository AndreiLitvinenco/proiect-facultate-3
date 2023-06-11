#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define N 16

/* Pentru a testa mai rapid programul
 * schimbati N 16 cu N 3
*/

struct Student {
    char nume[31];
    char prenume[31];
    int note[5];
};

float media(List* list) {
    float media_grupa = 0;
    int nr_studenti = 0;
    Iterator p = first(list);
    while (p != NULL) {
        float media_student = 0;
        struct Student* s = (struct Student*)get(list, p);
        for (int i = 0; i < 5; i++) {
            media_student += s->note[i];
        }
        media_student /= 5;
        printf("%s %s: %.2f\n", s->nume, s->prenume, media_student);
        media_grupa += media_student;
        nr_studenti++;
        p = next(list, p);
    }
    media_grupa /= nr_studenti;
    return media_grupa;
}

int main() {
    List* list = newList();

    /*
    int n = 0;
    printf("Introduceti numarul zilei din data dvs. de nastere: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) { */

    for (int i = 1; i <= N; i++) {
        printf("Introduceti datele pentru studentul %d:\n", i);
        struct Student* s = (struct Student*)malloc(sizeof(struct Student));
        printf("Nume: ");
        scanf("%s", s->nume);
        printf("Prenume: ");
        scanf("%s", s->prenume);
        printf("Note (5): ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s->note[j]);
        }
        insert(list, last(list), s);
    }

    float media_grupa = media(list);
    printf("Media grupei: %.2f\n", media_grupa);

    int nr_promovati = 0;
    int nr_nepromovati = 0;
    Iterator p = first(list);
    while (p != NULL) {
        struct Student* s = (struct Student*)get(list, p);
        float media_student = 0;
        for (int i = 0; i < 5; i++) {
            media_student += s->note[i];
        }
        media_student /= 5;
        if (media_student >= 5) {
            nr_promovati++;
        }
        else {
            nr_nepromovati++;
        }
        p = next(list, p);
    }

    printf("Numar studenti promovati: %d\n", nr_promovati);
    printf("Numar studenti nepromovati: %d\n", nr_nepromovati);

    deleteList(list);

    return 0;
}
