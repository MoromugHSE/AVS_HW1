#ifndef AVS_HW1_BUS_H
#define AVS_HW1_BUS_H

#include<cstdio>

struct bus {
    short int max_passengers;
};

void freadBus(FILE *const& fin, bus *b);

void fprintBus(FILE *const& fout, const bus& b);


#endif //AVS_HW1_BUS_H
