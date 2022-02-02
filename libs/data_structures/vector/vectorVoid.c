//
// Created by 123 on 02.02.2022.
//

#include "vectorVoid.h"

void checkingForSize(vectorVoid *v) {
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid v = {malloc(baseTypeSize * n), 0, n,baseTypeSize};
    checkingForSize(&v);

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (newCapacity == 0)
        v->data = NULL;
    else {
        realloc(v->data, v->baseTypeSize * newCapacity);
        checkingForSize(v);
        v->capacity = newCapacity;
    }
}

void shrinkToFitV(vectorVoid *v){
    v->capacity = v->size;
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v);
}



