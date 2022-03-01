//
// Created by 123 on 28.02.2022.
//

#ifndef COURSE_TASKS_STRING_H
#define COURSE_TASKS_STRING_H

#include "../string_.h"


typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;
typedef struct ElementDescriptor {
    char begin;
} ElementDescriptor;
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20
#define MAX_STRING_SIZE 100
char _stringBuffer[MAX_STRING_SIZE + 1];


// Возвращает указатель на последний элемент строки.
char *getEndOfString(char *s);

//удалит из строки все пробельные символы.
void removeNonLetters(char *s);

//Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

//Преобразовывает строку, обратив каждое слово этой строки.
void reverseWorld(char *s);

//
void spaceInsteadOfNumber(char *s);

//
void replace(char *source, char *w1, char *w2);


int strcmpWord(WordDescriptor w1, WordDescriptor w2);

int orderedAlphabetically(char *s);

#endif //COURSE_TASKS_STRING_H
