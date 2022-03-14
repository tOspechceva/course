//
// Created by 123 on 14.03.2022.
//

#ifndef COURSE_TIME_SORT_H
#define COURSE_TIME_SORT_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                       // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64];                           // имя генератора,
    // используемое при выводе
} GeneratingFunc;

# define TIME_TEST( testCode , time ) { \
 clock_t start_time = clock () ; \
 testCode \
 clock_t end_time = clock () ;\
 clock_t sort_time = end_time - start_time ; \
 time = ( double ) sort_time / CLOCKS_PER_SEC ; \
 }
# define ARRAY_SIZE(a) sizeof( a ) / sizeof( a[0])

//проверяет, является ли массив упорядоченным по неубыванию
bool isOrdered(int *a, size_t size);

//генерирует массив рандомно.
void generateRandomArray(int *a, const size_t n);

//генерируется массив 0, 1, 2, ..., n - 1
void generateOrderedArray(int *a, size_t n);

// генерируется массив n - 1, n - 2, ..., 0
void generateOrderedBackwards(int *a,  size_t n);

//сортировка пузырьком.
void bubbleSort(int *a, size_t size);

//сортировка выбором
void selectionSort_(int *a, const int size);

//сортировка вставками
void insertionSort (int *a , const size_t size );

//сортировка расческой
void combsort(int *a, const size_t size);

//сортировка Шелла
void shell_sort(int *array, int size);

#endif //COURSE_TIME_SORT_H
