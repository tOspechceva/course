//
// Created by 123 on 14.03.2022.
//

#include "time_sort.h"

bool isOrdered(int *a, size_t size) {
    for (int i = 1; i < size; ++i) {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}

void generateRandomArray(int *a, const size_t n) {
    srand((time(0)));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % RAND_MAX;
    }
}


void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
}

void generateOrderedBackwards(int *a, size_t n) {
    for (int i = n - 1, j = 0; i >= 0 && j < 10; i--, j++) {
        a[i] = j;
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;

}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort_(int *a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

void insertionSort(int *a, const size_t size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);
        }
    }
}

void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

void shell_sort(int *array, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}

