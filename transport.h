#ifndef AVS_HW1_TRANSPORT_H
#define AVS_HW1_TRANSPORT_H

struct transport {
    enum key {
        TRUCK, BUS, CAR
    };
    key k;
    union {
        truck t;
        bus b;
        car c;
    };
    int volume;
    double fuel_100km;
};


double getMaxDistance(const transport& tr) {
    return tr.fuel_100km * tr.volume / 100;
}


#endif //AVS_HW1_TRANSPORT_H
