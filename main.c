# include <assert.h>
# include <stdbool.h>
# include <stdio.h >
# include <stdint.h >

# include "c:/course/libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(3);
    pushBack(&v, 9);
    assert(v.data[0] == 9);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    v.size = 2;
    pushBack(&v, 8);
    assert(v.data[2] == 8);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

main() {
    test();
    vector v = createVector(0);

    if (isEmpty(&v))
        printf("Yes");

    return 0;
}