#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

int main()
{
    IntVector *ve = NULL;

    ve = malloc(sizeof(*ve));

    ve->capacity = 10;

    ve->size = 8;

    ve->data = (int *)malloc(ve->capacity * sizeof(int));

    for(int n = 0;n < ve->size;n++){
        ve->data[n] = n + 1;
    }

    int_vector_reserve(ve,15);

    for(int n = 0;n < ve->capacity;n++){
        printf("%d ",ve->data[n]);
    }

    printf("\n");

    int_vector_free(ve);
}