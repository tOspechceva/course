//
// Created by 123 on 03.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу размером nRows на nCols.
matrix getMemMatrix (int nRows , int nCols );

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);



#endif //COURSE_MATRIX_H
