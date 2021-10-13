#include "bus.h"
#include "random.h"

bool readBusFromFile(bus *b, FILE *const& fin) {
    short int max_passengers;
    fscanf(fin, "%hd", &max_passengers);
    if (max_passengers < 1 || max_passengers > 40) {
        return false;
    }
    b->max_passengers = max_passengers;
    return true;
}

bool generateBus(bus *b) {
    b->max_passengers = randomShort(1, 41);
    return true;
}

void writeBusToFile(const bus& b, FILE *const& fout) {
    fprintf(fout, "Bus can take %hd people.", b.max_passengers);
}
