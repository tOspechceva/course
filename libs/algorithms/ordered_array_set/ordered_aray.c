//
// Created by 123 on 19.12.2021.
//
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <malloc.h>

#include "ordered_aray.h"

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create ( size_t capacity ) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}
static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}


// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array ( const int *a ,size_t size ) {
    ordered_array_set set = ordered_array_set_create(size);

    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);

    return set;
}