#include "random.h"

#include <cstdlib>

int randomInt(int min, int max) {
    return rand() % (max - min) + min;
}

short int randomShort(short int min, short int max) {
    return rand() % (max - min) + min;
}

double randomDouble(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}
