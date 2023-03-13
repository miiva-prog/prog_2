#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

int main()
{
    IntVector *v = NULL;

    v = int_vector_new(10);
    v->size = 5;

    for(int n = 0;n < v->size;n++){
        v->data[n] = n + 1;
    }

    IntVector *ve = NULL;

    ve = int_vector_copy(v);

    int_vector_set_item(v,1,100);

    printf("int_vector_get_item - %d\n",int_vector_get_item(v,1));

    int_vector_push_back(v,20);

    printf("int_vector_push_back\n");
    for(int n = 0;n < v->capacity;n++){
        printf("%d ",v->data[n]);
    }
    printf("\n");

    printf("int_vector_pop_back\n");
    int_vector_pop_back(v);
    for(int n = 0;n < v->capacity;n++){
        printf("%d ",v->data[n]);
    }
    printf("\n");

    int_vector_shrink_to_fit(v);
    printf("int_vector_shrink_to_fit\n");
    for(int n = 0;n < v->capacity;n++){
        printf("%d ",v->data[n]);
    }
    printf("\n");
    
    int_vector_resize(v,7);
    printf("int_vector_resize\n");
    for(int n = 0;n < v->size;n++){
        printf("%d ",v->data[n]);
    }
    printf("\n");

    printf("int_vector_reserve\n");
    int_vector_reserve(v,12);
    for(int n = 0;n < v->capacity;n++){
        printf("%d ",v->data[n]);
    }
    printf("\n");

    int_vector_free(v);
    int_vector_free(ve);
}