# include <assert.h>
# include <stdbool.h>
# include <stdio.h >
# include <stdint.h >

# include "libs/data_structures/matrix/matrix.h"

void test_swapRows_firstLines() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     6, 0, 0,
                     0, 0, 1,
                     0, 0, 0,
                     0, 1, 1,
            },
            5, 3
    );
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 6);
    freeMemMatrix(m);
}

void test_swapRows() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
                     0, 0, 0,
                     0, 1, 1,
            },
            5, 3
    );
    swapRows(m, 1, 2);
    assert(m.values[1][2] == 1);
    freeMemMatrix(m);
}

void test_swapRows_lastLines() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
                     9, 8, 0,
                     0, 1, 1,
            },
            5, 3
    );
    swapRows(m, 4, 3);
    assert(m.values[4][1] == 8);
    freeMemMatrix(m);
}

void test_swapColumns_lastColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
                     9, 8, 0,
                     0, 1, 1,
            },
            5, 3
    );
    swapColumns(m, 2, 1);
    assert(m.values[3][1] == 0);
    freeMemMatrix(m);
}

void test_swapColumns_firstColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
                     9, 8, 0,
                     0, 1, 1,
            },
            5, 3
    );
    swapColumns(m, 0, 1);
    assert(m.values[3][1] == 9);
    freeMemMatrix(m);
}

void test_isSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
                     9, 8, 0,
                     0, 1, 1,
            },
            5, 3
    );
    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
            },
            3, 3
    );
    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_sameSizeMatrices() {
    matrix m = createMatrix(3, 3);
    matrix m2 = createMatrix(3, 3);
    assert(sameSizeMatrices(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
            },
            3, 3
    );
    assert(twoMatricesEqual(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     0, 0, 0,
                     0, 0, 1,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {1, 1, 0,
                     8, 0, 0,
                     0, 0, 1,
            },
            3, 3
    );
    assert(!twoMatricesEqual(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_isEMatrix() {
    matrix m2 = createMatrixFromArray(
            (int[]) {1},
            1, 1
    );
    assert(isEMatrix(m2));
    freeMemMatrix(m2);
}

void test_isEMatrix1() {
    matrix m2 = createMatrixFromArray(
            (int[]) {1, 2},
            1, 2
    );
    assert(!isEMatrix(m2));
    freeMemMatrix(m2);
}

void test_isSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 0, 0,
                     0, 1, 0,
                     0, 0, 1,

            },
            3, 3
    );
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 0, 0,
                     0, 1, 1,
                     0, 0, 1,

            },
            3, 3
    );
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9,

            },
            3, 3
    );
    transposeSquareMatrix(m);
    assert(m.values[1][0] == 2);
    assert(m.values[0][2] == 7);
    assert(m.values[2][1] == 6);
    freeMemMatrix(m);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9,

            },
            3, 3
    );
    position p = getMinValuePos(m);
    assert(p.rowIndex == 0);
    assert(p.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMinValuePos1() {
    matrix m = createMatrixFromArray(
            (int[]) {9, 2, 3,
                     4, 5, 6,
                     7, 8, 1,

            },
            3, 3
    );
    position p = getMinValuePos(m);
    assert(p.rowIndex == 2);
    assert(p.colIndex == 2);
    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9,

            },
            3, 3
    );
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 2);
    assert(p.colIndex == 2);
    freeMemMatrix(m);
}

int criteria(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

void test_insertionSortRowsMatrixByRowCriteria_sum() {
    matrix m = createMatrixFromArray(
            (int[]) {9, 8, 7,
                     6, 5, 4,
                     3, 2, 1
            },
            3, 3
    );
    insertionSortRowsMatrixByRowCriteria(m, criteria);

    assert(m.values[0][0] == 3);
    assert(m.values[2][0] == 9);
    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {6, 5, 4,
                     9, 8, 7,
                     3, 2, 1
            },
            3, 3
    );
    insertionSortRowsMatrixByRowCriteria(m, criteria);

    assert(m.values[0][0] == 3);
    assert(m.values[2][0] == 9);
    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {6, 5, 4,
                     9, 8, 7,
                     3, 2, 1
            },
            3, 3
    );
    insertionSortColsMatrixByColCriteria(m, criteria);
    assert(m.values[0][0] == 4);
    assert(m.values[2][2] == 3);
    freeMemMatrix(m);

}

void test_functions() {
    test_swapRows();
    test_swapRows_firstLines();
    test_swapRows_lastLines();
    test_swapColumns_lastColumns();
    test_swapColumns_firstColumns();
    test_isSquareMatrix();
    test_isSquareMatrix2();
    test_sameSizeMatrices();
    test_twoMatricesEqual();
    test_twoMatricesEqual2();
    test_isEMatrix();
    test_isEMatrix1();
    test_isSymmetricMatrix();
    test_isSymmetricMatrix2();
    test_transposeSquareMatrix();
    test_getMinValuePos1();
    test_getMaxValuePos();
    test_insertionSortRowsMatrixByRowCriteria_sum();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
}

void swapMinAndMaxRows(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {7, 1, 2,
                     1, 8, 1,
                     3, 2, 3
            },
            3, 3
    );
    sortRowsByMinElement(m);
    assert(m.values[1][0] == 7);
    assert(m.values[2][1] == 8);
}

void test_swapMinAndMaxRows() {
    matrix m = createMatrixFromArray(
            (int[]) {6, 5, 4,
                     9, 8, 7,
                     3, 2, 1
            },
            3, 3
    );
    swapMinAndMaxRows(m);
    assert(m.values[1][0] == 3);
    assert(m.values[2][1] == 8);
}

void test_tasks() {
    test_swapMinAndMaxRows();
    test_sortRowsByMinElement();
}

int main() {
    //test_functions();
    test_tasks();

    //matrix ms[3] = {
    //        createMatrix(2, 2),
    //        createMatrix(1, 1),
    //        createMatrix(1, 1),
//
    //};
    //inputMatrices(ms,3);
    //outputMatrices(ms,3);

    //matrix m1 = createMatrix(3, 2);
    //matrix m2= createMatrix(2,3);
    //inputMatrix(&m1);
    //inputMatrix(&m2);
    //if (isSymmetricMatrix(m1))
    //    printf("Yes");
    //else
    //    printf("No");

    //position p = getMaxValuePos(m1);
    //printf("%d %d %d", p.rowIndex, p.colIndex, m1.values[p.rowIndex][p.colIndex]);
    //outputMatrix(m1);
    //outputMatrix(m2);
    return 0;
}
