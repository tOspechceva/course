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
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    char *begin = _stringBuffer;
    *end = ' ';
    end++;
    *end = '\0';
    while (getWord(begin, &w)) {
        ws->words[ws->size].begin = w.begin;
        ws->words[ws->size].end = w.end;
        *(ws->words[ws->size].end) = '\0';
        ws->words[ws->size].end++;
        ws->size++;

        begin = w.end + 1;

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

bool isEmptyString(char *s) {
    while (*s != '\0') {
        if (!isspace(*s))
            return false;
    }
    return true;
}

void alternatingLines(char *s1, char *s2, char *s3) {
    if (isEmptyString(s1) && isEmptyString(s2)) {
        return;
    }
    char *beginSearch1 = s1;
    char *beginSearch2 = s2;
    char *copyS3 = s3;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            copyS3 = copy(word1.begin, word1.end, copyS3);
            beginSearch1 = word1.end;
            *copyS3 = ' ';
            copyS3++;
        }
        if (isW2Found) {
            copyS3 = copy(word2.begin, word2.end, copyS3);
            beginSearch2 = word2.end;
            *copyS3 = ' ';
            copyS3++;
        }
    }
    *(copyS3 - 1) = '\0';
}

char *findSpaceEnd(char *end) {
    char *rBegin = end;
    while (rBegin != _stringBuffer) {
        if (isspace(*rBegin))
            return rBegin;
        rBegin--;
    }

    return rBegin;
}

int getWordEnd(char *beginSearch, WordDescriptor *word) {
    word->end = findNonSpaceReverse(beginSearch, _stringBuffer);

    if (word->end == _stringBuffer)
        return 0;
    word->begin = findSpaceEnd(word->end);

    return 1;
}

void linesReverse(char *s) {
    if (isEmptyString(s)) {
        return;
    }
    char *endBuf = copy(s, getEndOfString(s), _stringBuffer + 1);

    WordDescriptor word;
    char *begin = s;
    endBuf--;
    *_stringBuffer = '\n';

    while (getWordEnd(endBuf, &word)) {
        begin = copy(word.begin + 1, word.end + 1, begin);
        *begin = ' ';
        begin++;
        endBuf = word.begin;
    }

    *(begin - 1) = '\0';
}

void *copyWordsReverse(char *s, char *s2) {
    char *begin = s;

    BagOfWords ws;
    getBagOfWords(&ws, begin);
    char *buf = _stringBuffer;

    for (int i = (int) ws.size - 1; i >= 0; --i) {
        buf = copy(ws.words[i].begin, ws.words[i].end - 1, buf);
        *buf = ' ';
        buf++;
    }

    *(buf - 1) = '\0';

    return copy(_stringBuffer, buf, s2);
}

bool isLetterA(WordDescriptor w) {
    char *begin = w.begin;

    while (begin != w.end) {
        if (*begin == 'a' || *begin == 'A') {
            return true;
        }
        begin++;
    }
    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *wordBefore) {
    WordDescriptor w1;
    char *begin = s;
    if (!getWord(begin, &w1)) {
        return EMPTY_STRING;
    } else {
        if (isLetterA(w1))
            return FIRST_WORD_WITH_A;
    }

    begin = w1.end;
    WordDescriptor w2;
    while (getWord(begin, &w2)) {
        if (isLetterA(w2)) {
            wordBefore->begin = w1.begin;
            wordBefore->end = w1.end;
            return WORD_FOUND;
        }
        w1.begin = w2.begin;
        w1.end = w2.end;
        begin = w2.end;

    }
    return NOT_FOUND_A_WORD_WITH_A;
}


void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    WordDescriptor w;
    WordBeforeFirstWordWithAReturnCode k = getWordBeforeFirstWordWithA(begin, &w);
    if (k == WORD_FOUND) {
        char *end = copy(w.begin, w.end, _stringBuffer);
        *end = '\0';
        printf("%s", _stringBuffer);
    }
}


void wordDescriptorToString(WordDescriptor w, char *destination) {
    char *end = copy(w.begin, w.end, destination);
    *end = '\0';
}

void getBagOf2Words(BagOfWords *ws, char *s, BagOfWords *ws1, char *s1) {
    WordDescriptor w1;
    ws1->size = 0;
    char *end1 = copy(s1, getEndOfString(s1), _stringBuffer);
    char *begin1 = _stringBuffer;
    *end1 = ' ';
    end1++;
    *end1 = '\0';
    while (getWord(begin1, &w1)) {
        ws1->words[ws1->size].begin = w1.begin;
        ws1->words[ws1->size].end = w1.end;
        *(ws1->words[ws1->size].end) = '\0';
        ws1->words[ws1->size].end++;
        ws1->size++;

        begin1 = w1.end + 1;

    }

    WordDescriptor w;
    ws->size = 0;
    char *end = copy(s, getEndOfString(s), end1 + 1);
    char *begin = end1 + 1;
    *end = ' ';
    end++;
    *end = '\0';
    while (getWord(begin, &w)) {
        ws->words[ws->size].begin = w.begin;
        ws->words[ws->size].end = w.end;
        *(ws->words[ws->size].end) = '\0';
        ws->words[ws->size].end++;
        ws->size++;

        begin = w.end + 1;

    }
}

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords bag1;

    BagOfWords bag2;
    getBagOf2Words(&bag1, s1, &bag2, s2);


    for (int j = bag1.size; j >= 0; j--) {
        for (int i = 0; i < bag2.size; i++) {
            if (strcmp(bag1.words[j].begin, bag2.words[i].begin) == 0) {
                return bag1.words[j];
            }
        }
    }
}

bool identicalWordsLine(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    *end = '\0';
    char *begin = _stringBuffer;

    BagOfWords ws;
    getBagOfWords(&ws, begin);
    for (int i = 0; i < ws.size; ++i) {
        for (int j = i + 1; j < ws.size; ++j) {
            if (strcmp(ws.words[i].begin, ws.words[j].begin) == 0) {
                return true;
            }
        }
    }

    return false;
}

int compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void sortLetters(WordDescriptor w) {
    int numberLettersWord = strlen_(w.begin);
    qsort(w.begin, numberLettersWord, sizeof(char), compare_char);
}

void stringArrayWords(BagOfWords ws, char *s1) {
    char *begin1 = s1;
    char *end1;
    for (int i = 0; i < ws.size; ++i) {
        end1 = copy(ws.words[i].begin, ws.words[i].end, begin1);
        *(end1 - 1) = ' ';
        begin1 = end1;
    }
    *(end1) = '\0';
}

bool wordsMadeIdenticalLetters(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    *end = '\0';
    char *begin = _stringBuffer;

    BagOfWords ws;
    getBagOfWords(&ws, begin);
    for (int i = 0; i < ws.size; ++i) {
        sortLetters(ws.words[i]);
    }
    char s1[MAX_STRING_SIZE];
    stringArrayWords(ws, s1);
    return identicalWordsLine(s1);
}

void allExceptLastOne(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    *end = '\0';
    char *begin = _stringBuffer;

    BagOfWords ws;
    getBagOfWords(&ws, begin);
    char *beginS = s;
    if (ws.size != 0) {
        for (int i = 0; i < ws.size - 1; i++) {
            if (strcmp(ws.words[i].begin, ws.words[ws.size - 1].begin) != 0) {
                char *endS = copy(ws.words[i].begin, ws.words[i].end, beginS);
                endS--;
                *endS = ' ';
                endS++;
                beginS = endS;

            }
        }
    }
    if (beginS != s)
        beginS--;
    *beginS = '\0';
}

WordDescriptor precedingFirstOccurrence(char *s1, char *s2) {
    BagOfWords bag1;
    BagOfWords bag2;
    getBagOf2Words(&bag1, s1, &bag2, s2);

    for (int j = 0; j < bag1.size; j++) {
        for (int i = 0; i < bag2.size; i++) {
            if (strcmp(bag1.words[j].begin, bag2.words[i].begin) == 0) {
                if (j != 0)
                    return bag1.words[j - 1];
                return bag1.words[0];
            }
        }
    }
}


