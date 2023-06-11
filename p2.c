#include <stdio.h>
#include <stdlib.h>
#include "list.h"


#define N 5
#define M 5

/*
#define N 19
#define M 6
*/
float readFloat() {
    float x;
    scanf("%f", &x);
    return x;
}

List concatenateLists(List L1, List L2) {
    List L3 = newList();  // a treia lista

    Iterator it;
    for (it = first(L1); it != NULL; it = next(L1, it)) {
        insert(L3, last(L3), get(L1, it));
    }
    for (it = first(L2); it != NULL; it = next(L2, it)) {
        insert(L3, last(L3), get(L2, it));
    }

    return L3;
}


float findMax(List L) {
    Iterator it;
    float max = *(float *)get(L, first(L));
    for (it = first(L); it != NULL; it = next(L, it)) {
        float value = *(float *)get(L, it);
        if (value > max) {
            max = value;
        }
    }
    return max;
}

float findMin(List L) {
    Iterator it;
    float min = *(float *)get(L, first(L));
    for (it = first(L); it != NULL; it = next(L, it)) {
        float value = *(float *)get(L, it);
        if (value < min) {
            min = value;
        }
    }
    return min;
}

int main() {
    List L1 = newList();  // prima lista
    List L2 = newList();  // a doua lista

    float nValues[N], mValues[M];
    int i;

    printf("Introduceti %d valori pentru prima lista:\n", N);
    for (i = 0; i < N; i++) {
        nValues[i] = readFloat();
        insert(L1, last(L1), &nValues[i]);
    }

    printf("Introduceti %d valori pentru a doua lista:\n", M);
    for (i = 0; i < M; i++) {
        mValues[i] = readFloat();
        insert(L2, last(L2), &mValues[i]);
    }

    // concatenarea celor doua liste intr-o singura lista
    List L3 = concatenateLists(L1, L2);

    // afisarea continutului informativ al fiecarui nod din a treia lista
    printf("Lista concatenata: ");
    Iterator it;
    for (it = next(L3, first(L3)); it != NULL; it = next(L3, it)) {
        printf("%0.2f ", *(float *)get(L3, it));
    }
    printf("\n");


    // calcularea celui mai mare si celui mai mic element din a treia lista
    float max = findMax(L3);
    float min = findMin(L3);
    printf("Maximul din lista este %0.2f\n", max);
    printf("Minimul din lista este %0.2f\n", min);

    deleteList(L1);
    deleteList(L2);
    deleteList(L3);

    return 0;
}
