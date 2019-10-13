#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int * vector;
    printf("size:");
    scanf("%d",&size);

    vector = (int *)calloc(size, sizeof(int));

    for (int i = 0 ; i < size ; i++) {
        printf("position %d: ", i);
        scanf("%d",&vector[i]);
    }

    for (int i = 0 ; i < size ; i++) {
        for (int j = i ; j < size ; j++) {
            if (vector[i] > vector[j]) {
                int aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }

    for (int i = 0 ; i < size ; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    free(vector);
}
