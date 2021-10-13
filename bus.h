#ifndef AVS_HW1_BUS_H
#define AVS_HW1_BUS_H

#include<cstdio>

struct bus {
    short int max_passengers;
};

bool readBusFromFile(bus *b, FILE *const& fin);

bool generateBus(bus *b);

void writeBusToFile(const bus& b, FILE *const& fout);


#endif //AVS_HW1_BUS_H
