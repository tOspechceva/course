//
// Created by 123 on 28.02.2022.
//

#include "tasks_string.h"

char *getEndOfString(char *s) {
    char *end = s;
    while (*end != '\0')
        end++;
    return end;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

char *countExtraSpaces(char *begin, char *end) {
    while (begin != end && isspace(*begin)) {
        begin++;
    }
    return begin;
}

void removeExtraSpaces(char *s) {
    char *iRead = s;
    char *iWrite = s;

    while (*iRead != '\0' && !isspace(*iRead)) {
        iRead++;
        iWrite++;
    }
    while (*iRead != '\0') {
        if (!isspace(*iRead) && isspace(*(iRead - 1))) {
            *iWrite = *(iRead - 1);
            iWrite++;
            *iWrite = *iRead;
            iWrite++;
        } else if(isspace(*iRead) && *(iRead+1)=='\0'){
            *iWrite = *iRead;
            iWrite++;
        }
        iRead++;

    }
    *iWrite = '\0';
}

git add .
 git commit -m " 2  "
 git push origin master