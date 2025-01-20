#include "utils.h"
#include <random>

int randomBetween(int lower, int upper) {
    srand(static_cast<unsigned int>(time(NULL)));
    return rand() % (upper - lower + 1) + lower;
}