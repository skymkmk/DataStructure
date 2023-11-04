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