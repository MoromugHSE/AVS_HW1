//
// Created by morom on 10.10.2021.
//

#ifndef AVS_HW1_TRUCK_H
#define AVS_HW1_TRUCK_H

#include <cstdio>

struct truck {
    int max_mass;
};

void freadTruck(FILE *const& fin, truck *t);

void fprintTruck(FILE *const& fout, const truck& t);


#endif //AVS_HW1_TRUCK_H
