#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <malloc.h>
#include "algorithm.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create_from_array(const int *a, const size_t size) {
    unordered_array_set set = unordered_array_set_create(size);

    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);

    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}


void qsort(void *ptr, size_t count, size_t size, int (*comp )(const void *, const void *));

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert (set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    *set = unordered_array_set_create(set->size + 1);
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size, value);
}

unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set sum = unordered_array_set_create(set1.size + set2.size);
    sum.size = set1.size;
    memcpy(sum.data, set1.data, set1.size * sizeof(int));

    for (int i = 0; i < set2.size; i++) {
        int value = set2.data[i];
        size_t pos = linearSearch_(sum.data, sum.size, value);

        if (pos == sum.size)
            append_(sum.data, &sum.size, value);
    }

    return sum;
}


unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersections = unordered_array_set_create(set2.size);

    for (int i = 0; i < set2.size; i++) {
        int value = set2.data[i];
        size_t pos = linearSearch_(set1.data, set1.size, value);

        if (pos < set1.size)
            append_(intersections.data, &intersections.size, value);
    }

    return intersections;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set difference = unordered_array_set_create(set1.size + set2.size);

    for (int i = 0; i < set1.size; i++) {
        int value = set1.data[i];
        size_t pos = linearSearch_(set2.data, set2.size, value);

        if (pos == set2.size)
            append_(difference.data, &difference.size, value);
    }

    return difference;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set symmetricDifference1 = unordered_array_set_create(set1.size);
    symmetricDifference1 = unordered_array_set_difference(set1, set2);

    unordered_array_set symmetricDifference2 = unordered_array_set_create(set2.size);
    symmetricDifference2 = unordered_array_set_difference(set2, set1);

    unordered_array_set symmetricDifference = unordered_array_set_create(set1.size + set2.size);
    symmetricDifference = unordered_array_set_union(symmetricDifference1, symmetricDifference2);

    return symmetricDifference;
}


unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_difference(universumSet, set);
}

void unordered_array_set_print(unordered_array_set set) {
    outputArray_(set.data, set.size);
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}