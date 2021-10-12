#ifndef AVS_HW1_CONTAINER_H
#define AVS_HW1_CONTAINER_H

#include "transport.h"

#include <cstdio>

struct container {
    enum {
        kMaxSize = 10 * 1000
    };
    int size = 0;
    transport *cont[kMaxSize]{};
};

void pushBackToContainer(container *cont, const transport& tr);

bool generateContainer(container *cont, int size);

bool readContainerFromFile(container *cont, int size, FILE *const& fin);

bool createContainer(container *cont, FILE *const& fin);

double getAverageDistance(const container& cont);

void removeLesserThanAverage(container *cont);

void writeContainerToFile(const container& cont, FILE *const& fout);


#endif //AVS_HW1_CONTAINER_H
