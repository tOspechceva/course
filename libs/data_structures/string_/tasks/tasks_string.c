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

int strcmpWord(WordDescriptor w1, WordDescriptor w2) {
    char *copyW1 = w1.begin;
    char *copyW2 = w2.begin;

    while (copyW1 != w1.end && copyW2 != w2.end && *copyW2 == *copyW1) {
        copyW1++;
        copyW2++;
    }

    if ((*copyW1 == ' ' || *copyW1 == '\0') && (*copyW2 == ' ' || *copyW2 == '\0'))
        return 1;
    else
        return 0;
}


void replace(char *source, char *w1, char *w2) {

    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr, *end;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        end = copy(source, getEndOfString(source), _stringBuffer);
        *end = '\0';
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor word;

    while (getWord(readPtr, &word) && recPtr != end) {
        if (strcmpWord(word, word1)) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(word.begin, word.end, recPtr);
        }
        *recPtr = ' ';
        recPtr++;
        readPtr = word.end;
    }
    *recPtr = '\0';
}

int orderedAlphabetically(char *s) {
    char *begin = s;
    char *beginWord1 = _stringBuffer;
    char *beginWord2;

    WordDescriptor word1;
    WordDescriptor word2;

    if (!getWord(begin, &word1))
        return 1;
    char *endWord1 = copy(word1.begin, word1.end, beginWord1);
    *endWord1 = '\0';

    while (getWord(begin, &word2)) {
        beginWord2 = endWord1 + 1;
        char *endWord2 = copy(word2.begin, word2.end, beginWord2);
        *endWord2 = '\0';
        if (strcmp(beginWord1, beginWord2) > 0)
            return 0;
        word1.end = word2.end;
        word1.begin = word2.begin;
        endWord1 = copy(word2.begin, word2.end, beginWord1);
        begin = word2.end;
    }

    return 1;
}

int isPalindromeWords(WordDescriptor w) {
    char *left = w.begin;
    char *right = w.end - 1;
    while (right - left > 0) {
        if (*(left) != *(right))
            return 0;
        right--;
        left++;
    }
    return 1;
}

char *findSpace_(char *begin) {
    char *end = begin;
    while (*end != '\0') {
        if (*end == ',')
            return end;
        end++;
    }

    return end;
}

int getWord_(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return 0;
    word->end = findSpace_(word->begin);

    return 1;
}

int numberPalindromeWords(char *s) {
    char *begin = s;
    WordDescriptor word;
    int number = 0;
    while (getWord_(begin, &word)) {
        if (isPalindromeWords(word))
            number++;
        begin = word.end + 1;
    }
    return number;
}

void getBagOfWords(BagOfWords *ws, char *s) {
    WordDescriptor w;
    ws->size = 0;
    while (getWord(s, &w)) {
        ws->words[ws->size].begin = w.begin;
        ws->words[ws->size].end = w.end;
        *(ws->words[ws->size].end) = '\0';
        ws->words[ws->size].end++;
        ws->size++;
        s = w.end + 1;
    }
}

void outputWordsReverse(char *s) {
    char *begin = s;

    BagOfWords ws;
    getBagOfWords(&ws, begin);

    for (int i = (int) ws.size - 1; i >= 0; --i) {
        printf("%s", ws.words[i].begin);
        printf("\n");
    }
}
