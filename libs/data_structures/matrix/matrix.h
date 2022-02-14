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
    int rowIndex;// ряд
    int colIndex;//столб
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

//обмен строк с порядковыми
//номерами i1 и i2 в матрице m. Помните, что для этого достаточно обменять указатели соответствующих строк
void swapRows(matrix m, int i1, int i2);

// обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2);

//возвращает значение ’истина’, если
//матрица m является квадратной, ложь – в противном случае.
bool isSquareMatrix(matrix m);

//возвращает значение ’истина’, если
//матрицы m1 и m2 имеют одинаковые размеры, ложь – в противном случае.
bool sameSizeMatrices(matrix m1, matrix m2);

// возвращает значение
//’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool twoMatricesEqual(matrix m1, matrix m2);

//возвращает значение ’истина’, если матрица
//m является единичной, ложь – в противном случае
bool isEMatrix(matrix m);

// возвращает значение ’истина’, если
//матрица m является симметричной, ложь – в противном случае.
bool isSymmetricMatrix(matrix m);

// транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m);

//возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m);

// возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m);

#endif //COURSE_MATRIX_H
