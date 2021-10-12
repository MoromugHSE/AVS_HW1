#include "transport.h"

double getMaxDistance(const transport& tr) {
    return tr.fuel_100km * tr.volume / 100;
}

void destroyTransport(transport *tr) {
    switch (tr->k) {
        case transport::TRUCK:
            delete tr->t;
            break;
        case transport::BUS:
            delete tr->b;
            break;
        case transport::CAR:
            delete tr->c;
            break;
    }
    delete tr;
}
