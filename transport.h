#ifndef AVS_HW1_TRANSPORT_H
#define AVS_HW1_TRANSPORT_H

#include "truck.h"
#include "bus.h"
#include "car.h"

struct transport {
    enum key {
        TRUCK, BUS, CAR
    };
    key k;
    union {
        truck *t;
        bus *b;
        car *c;
    };
    int volume;
    double fuel_100km;
};

double getMaxDistance(transport const& tr);

void destroyTransport(transport *tr);

#endif //AVS_HW1_TRANSPORT_H
