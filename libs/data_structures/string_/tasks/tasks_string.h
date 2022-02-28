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




// Возвращает указатель на последний элемент строки.
char *getEndOfString(char *s);

//удалит из строки все пробельные символы.
void removeNonLetters(char *s);

//Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

void reverseWorld(char *s);

#endif //COURSE_TASKS_STRING_H
