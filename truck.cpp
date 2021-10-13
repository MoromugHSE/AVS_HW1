#include "truck.h"
#include "random.h"

bool readTruckFromFile(truck *t, FILE *const& fin) {
    int max_mass;
    fscanf(fin, "%d", &max_mass);
    if (max_mass < 1 || max_mass > 1000) {
        return false;
    }
    t->max_mass = max_mass;
    return true;
}

bool generateTruck(truck *t) {
    t->max_mass = randomInt(1, 1001);
    return true;
}

void writeTruckToFile(const truck& t, FILE *const& fout) {
    fprintf(fout, "Truck can take %d kg.", t.max_mass);
}
