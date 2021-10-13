//
// Created by morom on 10.10.2021.
//

#ifndef AVS_HW1_CAR_H
#define AVS_HW1_CAR_H

#include <cstdio>

struct car {
    short int max_speed;
};

bool readCarFromFile(car *c, FILE *const& fin);

bool generateCar(car *c);

void writeCarToFile(const car& c, FILE *const& fout);


#endif //AVS_HW1_CAR_H
