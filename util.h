#ifndef UTIL_H
#define UTIL_H
typedef struct pair {
    int index;
    int value;
} pair;

pair minArray(const int *const array, const int length);
pair maxArray(const int *const array, const int length);
pair minPairs(const pair *const pairs, const int length);
#endif