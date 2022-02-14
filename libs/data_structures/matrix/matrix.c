//
// Created by 123 on 03.02.2022.
//


#include "matrix.h"


matrix createMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = createMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        free(m.values[i]);
    }

    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(ms[i]);
    }
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert(m.nRows > i1);
    assert(m.nRows > i2);

    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    assert(m.nCols > j1);
    assert(m.nCols > j2);

    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

bool isSquareMatrix(matrix m){
    if (m.nRows==m.nCols)
        return true;
    return false;
}
bool sameSizeMatrices(matrix m1, matrix m2){
    if (m1.nRows==m2.nRows && m1.nCols==m2.nCols)
        return true;
    return false;
}

bool twoMatricesEqual(matrix m1, matrix m2){
    if (sameSizeMatrices(m1,m2)) {
        for (int i = 0; i < m1.nRows; i++) {
            for (int j = 0; j < m1.nCols; j++) {
                if (m2.values[i][j]!=m1.values[i][j])
                    return false;
            }
        }
        return true;
    }
    return false;
}

bool isEMatrix(matrix m){
    if (m.nRows==1 && m.nCols==1)
        return true;
    return false;
}

bool isSymmetricMatrix(matrix m){
    if (isSquareMatrix(m)){
        int i=0;
        int j=0;
        while (i<m.nRows && j<m.nCols){
            while (i!=j){
                if (m.values[i][j]!=m.values[j][i])
                    return false;
                i++;
            }
            j++;
        }
        return true;
    }
    return false;
}

