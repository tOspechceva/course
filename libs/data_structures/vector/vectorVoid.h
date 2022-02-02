//
// Created by 123 on 02.02.2022.
//

#ifndef COURSE_VECTORVOID_H
#define COURSE_VECTORVOID_H


# include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора

    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

//возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//изменяет количество
//памяти, выделенное под хранение элементов вектора.
void reserveV(vectorVoid *v, size_t newCapacity);

//  освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v);

#endif //COURSE_VECTORVOID_H
