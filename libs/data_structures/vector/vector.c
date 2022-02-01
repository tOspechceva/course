//
// Created by 123 on 31.01.2022.
//

#include <assert.h>
#include "vector.h"

void checkingForSize(vector *v) {
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector createVector(size_t n) {
    vector v = {malloc(sizeof(int) * n), 0, n};
    checkingForSize(&v);
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        realloc(v->data, sizeof(int) * newCapacity);
        checkingForSize(v);
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        realloc(v->data, sizeof(int));
        v->capacity += 1;
    } else if (isFull(v)) {
        reserve(v, (v->capacity) * 2);
    }
    v->data[v->size] = x;
    v->size += 1;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad vector ");
        exit(1);
    }
    v->size -= 1;
}

int *atVector(vector *v, size_t index) {
    if (index >= v->capacity) {
        fprintf(stderr, "IndexError: a[ %d ] is not exists", index);
    } else if (v->capacity == 0 && index < 0) {
        fprintf(stderr, "bad vector");
        exit(1);
    }
    return (int *) &v->data[index];
}

int *back(vector *v) {
    return atVector(v, v->capacity - 1);
}

int *front(vector *v) {
    return atVector(v, v->size - 1);
}
