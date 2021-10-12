#include "random.h"

#include <cstdlib>

inline int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

inline short int randomShort(short int min, short int max) {
    return rand() % (max - min + 1) + min;
}

inline double randomDouble(double min, double max) {
    return (double)rand() / RAND_MAX * (max - min) + min;
}
