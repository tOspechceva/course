//
// Created by 123 on 31.01.2022.
//

#include "vector.h"

void checkingForSize (vector v ){
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}
vector createVector(size_t n) {
    vector v = {malloc(sizeof(int) * n), 0, n};
    checkingForSize(v);
    return v;
}

void reserve(vector *v, size_t newCapacity){
    if(newCapacity==0)
        v->data=NULL;
    else {
        realloc(v->data, sizeof(int) * newCapacity);
        checkingForSize(*v);
    }
}

void clear(vector *v){
   v->size=0;
}

void shrinkToFit(vector *v){
    realloc(v->data, sizeof(int) * v->size);
}

void deleteVector(vector *v) {
    free(v);
}
