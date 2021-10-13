#include "transport.h"
#include "random.h"

double getMaxDistance(const transport& tr) {
    return tr.fuel_100km * tr.volume * 100;
}

bool generateTransport(transport *tr) {
    tr->volume = randomInt(1, 201);
    tr->fuel_100km = randomDouble(0 + 1e-9, 20);
    switch (randomInt(1, 4)) {
        case 1:
            tr->k = transport::TRUCK;
            tr->t = new truck();
            return generateTruck(tr->t);
        case 2:
            tr->k = transport::BUS;
            tr->b = new bus();
            return generateBus(tr->b);
        case 3:
            tr->k = transport::CAR;
            tr->c = new car();
            return generateCar(tr->c);
    }
    return true;
}

bool readTransportFromFile(transport *tr, FILE *const& fin) {
    int k;
    fscanf(fin, "%d", &k);
    int volume;
    double fuel_100km;
    fscanf(fin, "%d %lf", &volume, &fuel_100km);
    if (volume < 1 || volume > 200) {
        return false;
    }
    tr->volume = volume;
    if (fuel_100km < 0 + 1e-9 || fuel_100km > 20) {
        return false;
    }
    tr->fuel_100km = fuel_100km;
    switch (k) {
        case 1:
            tr->k = transport::TRUCK;
            tr->t = new truck();
            return readTruckFromFile(tr->t, fin);
        case 2:
            tr->k = transport::BUS;
            tr->b = new bus();
            return readBusFromFile(tr->b, fin);
        case 3:
            tr->k = transport::CAR;
            tr->c = new car();
            return readCarFromFile(tr->c, fin);
        default:
            return false;
    }
}

void writeTransportToFile(const transport& tr, FILE *const& fout) {
    fprintf(fout, "This transport has a volume of %d and needs %lf fuel for 100 km. ",
            tr.volume, tr.fuel_100km);
    switch (tr.k) {
        case transport::TRUCK:
            fprintf(fout, "This is a truck. ");
            writeTruckToFile(*(tr.t), fout);
            break;
        case transport::BUS:
            fprintf(fout, "This is a bus. ");
            writeBusToFile(*(tr.b), fout);
            break;
        case transport::CAR:
            fprintf(fout, "This is a car. ");
            writeCarToFile(*(tr.c), fout);
            break;
    }
    fprintf(fout, "\n");
}

void destroyTransport(transport *tr) {
    switch (tr->k) {
        case transport::TRUCK:
            delete tr->t;
            tr->t = nullptr;
            break;
        case transport::BUS:
            delete tr->b;
            tr->b = nullptr;
            break;
        case transport::CAR:
            delete tr->c;
            tr->c = nullptr;
            break;
    }
}
