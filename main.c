# include <assert.h>
# include <stdbool.h>
# include <stdio.h >
# include <stdint.h >

# include "c:/course/libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(3);
    pushBack(&v, 9);
    assert(v.data[0] == 9);
    assert(v.size == 1);
    assert(v.capacity == 3);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    v.size = 2;
    pushBack(&v, 8);
    assert(v.data[2] == 8);
    assert(v.capacity == 4);
    assert(v.size == 3);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_specificCase() {
    vector v = createVector(3);
    int index = 1;
    v.data[1] = 10;
    v.size = 3;
    assert(atVector(&v, index) == &v.data[1]);

    deleteVector(&v);
}

void test_isEmpty() {
    vector v = createVector(3);
    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isFull() {
    vector v = createVector(3);
    v.size = 3;
    assert(isFull(&v));

    deleteVector(&v);
}

void test_shrinkToFit() {
    vector v = createVector(5);
    v.size = 3;
    shrinkToFit(&v);
    assert(v.size == v.capacity);

    deleteVector(&v);
}

void test_createVector() {
    vector v = createVector(5);
    assert(v.size == 0);
    assert(v.capacity == 5);

    deleteVector(&v);
}

void test_reserve() {
    vector v = createVector(5);
    v.size = 2;
    reserve(&v, 3);
    assert(v.capacity == 3);
    assert(v.size == 2);

    deleteVector(&v);
}

void test_getVectorValue() {
    vector v = createVector(5);
    v.data[3] = 9;
    assert(getVectorValue(&v, 3) == v.data[3]);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    v.size = 2;
    assert(atVector(&v, 1) == &v.data[1]);

    deleteVector(&v);
}


void test_atVector_requestToLastElement() {
    vector v = createVector(3);

    assert(atVector(&v, 2) == &v.data[2]);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);

    assert(back(&v) == &v.data[0]);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    assert(front(&v) == &v.data[0]);

    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_specificCase();
    test_shrinkToFit();
    test_isEmpty();
    test_isFull();
    test_createVector();
    test_reserve();
    test_getVectorValue();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

main() {
    test();

    return 0;
}