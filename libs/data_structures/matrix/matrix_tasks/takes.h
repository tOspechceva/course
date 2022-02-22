//
// Created by 123 on 21.02.2022.
//

#ifndef COURSE_TAKES_H
#define COURSE_TAKES_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

#include "../matrix.h"

void swapMinAndMaxRows(matrix m);

int getMax(int *a, int n);

void sortRowsByMinElement(matrix m);

int getMin(int *a, int n);

void sortColsByMinElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

long long getSum(int *a, int n);

bool isUnique(long long *a, int n);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

void sortByDistances(matrix m);

#endif //COURSE_TAKES_H
