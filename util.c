#include "util.h"
#include <limits.h>

pair minArray(const int *const array, const int length) {
    pair theMin;
    theMin.index = -1;
    theMin.value = INT_MAX;
    for (int i = 0; i < length; i++) if (array[i] < theMin.value) {
        theMin.value = array[i];
        theMin.index = i;
    }
    return theMin;
}

pair maxArray(const int *const array, const int length) {
    pair theMax;
    theMax.index = -1;
    theMax.value = INT_MIN;
    for (int i = 0; i < length; i++) if (array[i] > theMax.value) {
        theMax.value = array[i];
        theMax.index = i;
    }
    return theMax;
}

pair minPairs(const pair *const pairs, const int length) {
    pair theMin;
    theMin.index = -1;
    theMin.value = INT_MAX;
    for (int i = 0; i < length; i++) if (pairs[i].value < theMin.value) theMin = pairs[i];
    return theMin;
}