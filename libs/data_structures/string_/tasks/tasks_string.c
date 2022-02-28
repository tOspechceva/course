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
        } else if (isspace(*iRead) && *(iRead + 1) == '\0') {
            *iWrite = *iRead;
            iWrite++;
        } else if (!isspace(*iRead)) {
            *iWrite = *iRead;
            iWrite++;
        }
        iRead++;

    }
    *iWrite = '\0';
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);

    return 1;
}

void *copyReverse(char *s, WordDescriptor word) {
    char *rBegin = s;
    char *end = word.begin;

    while (end != word.end) {
        *end = *rBegin;
        end++;
        rBegin--;
    }

}

void reverseWorld(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
        copyReverse(endStringBuffer - 1, word);
        beginSearch = word.end;
    }
}

void spaceInsteadOfNumber(char *s) {
    char *end = getEndOfString(s);
    char *iRead = s;

    char copy_[MAX_STRING_SIZE];
    char *iWrite = copy_;

    while (iRead != end) {
        if (isdigit(*iRead)) {
            char k = *iRead - '0';
            for (int i = 0; i < k; ++i) {
                *iWrite = ' ';
                iWrite++;
            }
        } else {
            *iWrite = *iRead;
            iWrite++;
        }
        iRead++;
    }

    *iWrite = '\0';
    copy(copy_, iWrite, s);
}