//
// Created by morom on 10.10.2021.
//

#ifndef AVS_HW1_CAR_H
#define AVS_HW1_CAR_H

#include <cstdio>

struct car {
    short int max_speed;
};

void freadCar(FILE *const& fin, car *c);

void fprintCar(FILE *const& fout, const car& c);


#endif //AVS_HW1_CAR_H
