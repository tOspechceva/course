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
matrix createMatrix(int nRows, int nCols);

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols);

// освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

//ввод матрицы m.
void inputMatrix(matrix *m);

//ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

// вывод матрицы m.
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices);

#endif //COURSE_MATRIX_H
