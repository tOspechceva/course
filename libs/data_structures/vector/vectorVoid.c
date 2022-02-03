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

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v = {malloc(baseTypeSize * n), 0, n, baseTypeSize};
    checkingForSize(&v);

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        realloc(v->data, v->baseTypeSize * newCapacity);
        checkingForSize(v);
        v->capacity = newCapacity;
    }
}

void shrinkToFitV(vectorVoid *v) {
    v->capacity = v->size;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (v->capacity == 0 || index < 0) {
        fprintf(stderr, "bad vector");
        exit(1);
    }
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source){
    if (v->capacity == 0 || index < 0) {
        fprintf(stderr, "bad vector");
        exit(1);
    }
    memcpy(&v->data[index], source, v->baseTypeSize);
}

void popBackV(vectorVoid *v){
    if (isEmptyV(v)) {
        fprintf(stderr, "bad vector ");
        exit(1);
    }
    v->size -= 1;
}

void pushBackV(vectorVoid *v, void *source){
    if (v->capacity == 0) {
        realloc(v->data, sizeof(int));
        v->capacity += 1;
    } else if (isFullV(v)) {
        reserveV(v, (v->capacity) * 2);
    }
    setVectorValueV(v,v->capacity,&v->data[v->size]);
    v->size += 1;
}


