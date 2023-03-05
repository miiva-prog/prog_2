#include "IntVector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

IntVector* int_vector_new(size_t initial_capacity)
{
    IntVector *vec = NULL;

    vec = malloc(sizeof(*vec));

    if(vec == NULL)
        return NULL;
    
    vec->data = (int *)malloc(initial_capacity * sizeof(int));

    if(vec->data == NULL)
        return NULL;

    return vec;
}

IntVector* int_vector_copy(const IntVector *v)
{
    IntVector *ve = NULL;

    ve = malloc(sizeof(*ve));

    if(ve == NULL)
        return NULL;

    ve->capacity = v->capacity;
    ve->size = v->size;

    if(v->data != NULL){
        ve->data = (int *)malloc(ve->capacity * sizeof(int));

        for(int n = 0;n < ve->size;n++){
            ve->data[n] = v->data[n];
        }
    }
    return ve;
}

void int_vector_free(IntVector *v)
{
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    return v->data[index]; 
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    v->data[index] = item;
}

size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
    if(v->capacity > v->size){
        v->data[v->size] = item;
        v->size++;
        return 0;
    }else{
        v->capacity *= 2;
        v->data = (int *)realloc(v->data,v->capacity * sizeof(int));
        if(v->data == NULL){
            return -1;
        }else{
            v->data[v->size] = item;
            v->size++;
            return 0;
        }
    }
}

void int_vector_pop_back(IntVector *v)
{
    if(v->size != 0){
        v->data[v->size - 1] = 0;
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector *v)
{
    if(v->capacity < v->size){
        return -1;
    }else if(v->capacity == v->size){
        return 0;
    }else{
        v->capacity = v->size;
        v->data = (int *)realloc(v->data,v->capacity * sizeof(int));
        if(v->data != NULL){
            return 0;
        }else{
            return -1;
        }
    }
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if(v->capacity < new_size){
        v->capacity = new_size;
        v->data = (int *)realloc(v->data,v->capacity * sizeof(int));
        if(v->data == NULL)
            return -1;
    }

    if(new_size > v->size){
        while(new_size > v->size){
            v->data[v->size] = 0;
            v->size++;
        }
        return 0;
    }else{
        int_vector_shrink_to_fit(v);
        return 0;
    }
    return -1;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if(v->capacity < new_capacity){
        v->capacity = new_capacity;
        v->data = (int *)realloc(v->data,v->capacity * sizeof(int));
        if(v->data == NULL){
            return -1;
        }else{
            return 0;
        }
    }
    return -1;
}