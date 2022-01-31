//
// Created by 123 on 31.01.2022.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//изменяет количество
//памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);



#endif //COURSE_VECTOR_H
