//
// Created by 123 on 21.02.2022.
//

#include "takes.h"

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

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix m3 = createMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m3.nRows; i++)
        for (int j = 0; j < m3.nCols; j++) {
            m3.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; k++)
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSquareMatrix(*m) && isSymmetricMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long b[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        b[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(b, m.nRows)) {
        transposeSquareMatrix(m);
    }
}


bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    matrix m = mulMatrices(m1, m2);

    return isEMatrix(m);
}

int max_(int a, int b) {
    return a < b ? b : a;
}

long long sumArray(int *a, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int arraySize = m.nRows + m.nCols - 2;
    int max[arraySize];
    int i = 0;
    for (int j = 1; j < m.nRows; ++j) {
        max[i] = m.values[j][0];
        for (int k = j, x = 0; k < m.nRows && x < m.nCols; ++k, ++x) {
            max[i] = max_(max[i], m.values[k][x]);
        }
        i++;
    }
    for (int j = 1; j < m.nCols; ++j) {
        max[i] = m.values[0][j];
        for (int k = 0, x = j; k < m.nRows && x < m.nCols; ++k, ++x) {
            max[i] = max_(max[i], m.values[k][x]);
        }
        i++;
    }

    return sumArray(max, arraySize);
}

int min_(int a, int b) {
    return a < b ? a : b;
}

int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int min = m.values[max.rowIndex][max.colIndex];
    for (int k = 1; k < max.rowIndex; ++k) {
        for (int i = max.rowIndex - 1; i >= 0; --i) {
            int left;
            if (max.colIndex - k < 0)
                left = 0;
            else
                left = max.colIndex - k;
            int right;
            if (max.colIndex + k >= m.nCols)
                right = m.nCols - 1;
            else
                right = max.colIndex + k;
            while (left <= right) {
                min = min_(min, m.values[i][left]);
                left++;
            }
        }
    }

    return min;
}
