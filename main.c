#include <assert.h>
#include <stdbool.h>
#include <stdio.h >
#include <stdint.h >

#include "libs/data_structures/string_/string_.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/matrix_tasks/takes.h"
#include "libs/data_structures/string_/tasks/tasks_string.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)


void test_strlen_() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";
    assert(strlen_(s1) == 2);
    assert(strlen_(s2) == 7);
}

void test_find() {
    char s2[10] = "Hello";
    char *s3 = find(s2, s2 + strlen_(s2), 'l');
    assert(*s3 == 'l');
}

void test_findNonSpace() {
    char s2[10] = "\t Hello\t";
    char *s3 = findNonSpace(s2);
    assert(*s3 == 'H');
}

void test_findSpace() {
    char s2[10] = "Hel lo";
    char *s3 = findSpace(s2);
    assert(*s3 == ' ');
}

void test_findNonSpaceReverse() {
    char s2[10] = "Hel lo\t";
    char *s3 = findNonSpaceReverse(s2 + strlen_(s2) - 1, s2);
    assert(*s3 == 'o');
}

void test_findSpaceReverse() {
    char s2[10] = "Hel\tlo";
    char *s3 = findSpaceReverse(s2 + strlen_(s2) - 1, s2);
    assert(*s3 == '\t');
}

void test_strcmp_allFalse() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";
    assert(strcmp(s1, s2) == 'H' - '\t');

}

void test_strcmp_True() {
    char *s1 = "Hi";
    char s2[10] = "Hi";
    assert(strcmp(s1, s2) == 0);

}

void test_strcmp_FalseNegative() {
    char *s1 = "Ai";
    char s2[10] = "Hi";
    assert(strcmp(s1, s2) == 'A' - 'H');

}

void test_strcmp_2WordsTrue() {
    char *s1 = "aa mm";
    char s2[10] = "aa mm";
    assert(strcmp(s1, s2) == 0);

}

void test_strcmp_2WordsFalse() {
    char *s1 = "aa Mm";
    char s2[10] = "aa mm";
    assert(strcmp(s1, s2) == 'M' - 'm');
}

void test_copy_1Symbol() {
    char s1[10] = "a";
    char copy_[10];
    char *endCopy = copy(s1, s1 + strlen_(s1), copy_);
    ASSERT_STRING("a", copy_);
}

void test_copy_World() {
    char s1[15] = "beautiful";
    char copy_[15];
    char *endCopy = copy(s1, s1 + strlen_(s1), copy_);
    ASSERT_STRING("beautiful", copy_);
}

void test_copy_2World() {
    char s1[20] = "beautiful cat";
    char copy_[20];
    char *endCopy = copy(s1, s1 + strlen_(s1), copy_);
    *endCopy = '\0';
    ASSERT_STRING("beautiful cat", copy_);
}

bool notM(char a) {
    return a != 'M';
}

void test_copyIf_World() {
    char s1[15] = "MbeMauMtifuMl";
    char copy_[15];
    char *endCopy = copyIf(s1, s1 + strlen_(s1), copy_, notM);
    ASSERT_STRING("beautiful", copy_);
}

void test_copyIf_Symbol() {
    char s1[25] = "M";
    char copy_[25];
    char *endCopy = copyIf(s1, s1 + strlen_(s1), copy_, notM);
    *endCopy = '\0';
    ASSERT_STRING("", copy_);
}

void test_copyIf_2World() {
    char s1[20] = "MbeMauMtifuMl Moon";
    char copy_[20];
    char *endCopy = copyIf(s1, s1 + strlen_(s1), copy_, notM);
    *endCopy = '\0';
    ASSERT_STRING("beautiful oon", copy_);
}

void test_copyIfReverse_World() {
    char s1[10] = "Mcat";
    char copy_[10];
    char *endCopy = copyIfReverse(s1 + strlen_(s1) - 1, s1, copy_, notM);
    *endCopy = '\0';
    ASSERT_STRING("tac", copy_);
}

void test_copyIfReverse_2World() {
    char s1[10] = "Mcat Milk";
    char copy_[10];
    char *endCopy = copyIfReverse(s1 + strlen_(s1) - 1, s1, copy_, notM);
    *endCopy = '\0';
    ASSERT_STRING("kli tac", copy_);
}

void test_removeNonLetters() {
    char s1[10] = "a b  1";
    removeNonLetters(s1);
    ASSERT_STRING("ab1", s1);
}

void test_removeExtraSpaces() {
    char s1[15] = "";
    removeExtraSpaces(s1);
    ASSERT_STRING("", s1);

    char s2[15] = "  ";
    removeExtraSpaces(s2);
    ASSERT_STRING(" ", s2);

    char s3[15] = "1  2 ";
    removeExtraSpaces(s3);
    ASSERT_STRING("1 2 ", s3);

    char s4[15] = "1  26 ";
    removeExtraSpaces(s4);
    ASSERT_STRING("1 26 ", s4);

    char s5[20] = "1  2678 789   098 ";
    removeExtraSpaces(s5);
    ASSERT_STRING("1 2678 789 098 ", s5);
}

void test_reverseWorld() {
    char s1[15] = "123";
    reverseWorld(s1);
    ASSERT_STRING("321", s1);

    char s2[15] = "123 567";
    reverseWorld(s2);
    ASSERT_STRING("321 765", s2);

    char s3[15] = "";
    reverseWorld(s3);
    ASSERT_STRING("", s3);

    char s4[15] = "1";
    reverseWorld(s4);
    ASSERT_STRING("1", s4);

    char s5[15] = "1 2";
    reverseWorld(s5);
    ASSERT_STRING("1 2", s5);
}

void test_spaceInsteadOfNumber() {
    char s1[100] = "a1m2c3";
    spaceInsteadOfNumber(s1);
    ASSERT_STRING("a m  c   ", s1);

    char s2[100] = " ";
    spaceInsteadOfNumber(s2);
    ASSERT_STRING(" ", s2);

    char s3[100] = "a1";
    spaceInsteadOfNumber(s3);
    ASSERT_STRING("a ", s3);

    char s4[100] = "a";
    spaceInsteadOfNumber(s4);
    ASSERT_STRING("a", s4);
}

void test_replace() {
    char s1[100] = "i like cat";
    replace(s1, "cat", "sweet");
    ASSERT_STRING("i like sweet ", s1);

    char s2[100] = "cat";
    replace(s2, "cat", "swet");
    ASSERT_STRING("swet ", s2);

    char s3[100] = "cat cat";
    replace(s3, "cat", "sweet");
    ASSERT_STRING("sweet sweet ", s3);

    char s4[100] = "i love cat and cat";
    replace(s4, "cat", "sweet");
    ASSERT_STRING("i love sweet and sweet ", s4);


}


void test_strcmpForWorld() {
  char s[10] = "Hello!";
  WordDescriptor w = {s, s + 6};
  char s1[10] = "Hello!";
  WordDescriptor w1 = {s1, s1 + 6};
  assert(strcmpWord(w,w1));

   char s2[10] = "Hello! ";
   WordDescriptor w2 = {s2, s2 + strlen_(s2)};
   char s3[10] = "Hello!";
   WordDescriptor w3 = {s3, s3 + strlen_(s3)};
   assert(strcmpWord(w2,w3));

    char s4[10] = "Helto! ";
    WordDescriptor w4 = {s4, s4 + strlen_(s4)};
    char s5[10] = "Hello!";
    WordDescriptor w5 = {s5, s5 + strlen_(s5)};
    assert(!strcmpWord(w4,w5));
}




void test() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_allFalse();
    test_strcmp_True();
    test_strcmp_FalseNegative();
    test_strcmp_2WordsTrue();
    test_strcmp_2WordsFalse();
    test_copy_1Symbol();
    test_copy_World();
    test_copy_2World();
    test_copyIf_World();
    test_copyIf_Symbol();
    test_copyIf_2World();
    test_copyIfReverse_World();
    test_copyIfReverse_2World();
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_reverseWorld();
    test_spaceInsteadOfNumber();
    test_replace();
    test_strcmpForWorld();

}

int main() {
    test();

    return 0;
}

