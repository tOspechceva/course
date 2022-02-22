# include <assert.h>
# include <stdbool.h>
# include <stdio.h >
# include <stdint.h >

# include "libs/data_structures/matrix/matrix.h"
# include "libs/data_structures/matrix/matrix_tasks/takes.h"


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
    freeMemMatrix(m);
}


void test_sortColsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {3, 5, 2, 4, 3, 3,
                     2, 5, 1, 8, 2, 7,
                     6, 1, 4, 4, 8, 3
            },
            3, 6
    );
    sortColsByMinElement(m);
    assert(m.values[1][0] == 5);
    assert(m.values[2][1] == 4);
    assert(m.values[2][5] == 4);
    freeMemMatrix(m);
}

void test_getSquareOfMatrixIfSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {6, 9, 3,
                     9, 8, 7,
                     3, 7, 1
            },
            3, 3
    );
    getSquareOfMatrixIfSymmetric(&m);
    assert(m.values[1][0] == 147);
    freeMemMatrix(m);
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
    freeMemMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9,

            },
            3, 3
    );
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(m.values[1][0] == 2);
    assert(m.values[0][2] == 7);
    assert(m.values[2][1] == 6);
    freeMemMatrix(m);
}

void test_isMutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray(
            (int[]) {2, 1, -1,
                     5, 2, 4,
                     7, 3, 2
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {-8, -5, 6,
                     18, 11, -13,
                     1, 1, -1
            },
            3, 3
    );
    assert(isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray(
            (int[]) {3, 2, 5, 4,
                     1, 3, 6, 3,
                     3, 2, 1, 2
            },
            3, 4
    );
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,
                     3, 4
            },
            2, 2
    );
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 5);
    freeMemMatrix(m);
}

void test_getMinInArea() {
    matrix m = createMatrixFromArray(
            (int[]) {10, 7, 5, 6,
                     3, 11, 8, 9,
                     4, 1, 12, 2
            },
            3, 4
    );
    assert(getMinInArea(m) == 5);
    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {2, 7,
                     7, 1,
                     5, 4,
                     4, 3,
                     1, 6,
                     0, 8

            },
            6, 2
    );
    assert(countEqClassesByRowsSum(m)==3);
}

void test_tasks() {
    test_getSquareOfMatrixIfSymmetric();
    test_sortColsByMinElement();
    test_swapMinAndMaxRows();
    test_sortRowsByMinElement();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_findSumOfMaxesOfPseudoDiagonal2();
    test_getMinInArea();
    test_countEqClassesByRowsSum();
}


int main() {
    test_functions();
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
