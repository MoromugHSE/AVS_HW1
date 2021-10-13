#ifndef AVS_HW1_TRUCK_H
#define AVS_HW1_TRUCK_H

#include <cstdio>

struct truck {
    int max_mass;
};

bool readTruckFromFile(truck *t, FILE *const& fin);

bool generateTruck(truck *t);

void writeTruckToFile(const truck &t, FILE *const& fout);


#endif //AVS_HW1_TRUCK_H
