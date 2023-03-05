#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

int main()
{
    IntVector *ve = NULL;

    IntVector *v = NULL;

    ve = malloc(sizeof(*ve));

    ve->capacity = 10;

    ve->size = 8;

    // ve->data = (int *)malloc(ve->capacity * sizeof(int));

    // for(int n = 0;n < ve->size;n++){
    //     ve->data[n] = n + 1;
    // }

    v = int_vector_copy(ve);

    printf("%ld %ld\n",v->capacity,v->size);

    // for(int n = 0;n < v->capacity;n++){
    //     printf("%d ",v->data[n]);
    // }

    // printf("\n");    
    
    // int_vector_free(ve);
}