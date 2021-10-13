#include "car.h"
#include "random.h"

bool readCarFromFile(car *c, FILE *const& fin) {
    short int max_speed;
    fscanf(fin, "%hd", &max_speed);
    if (max_speed < 1 || max_speed > 100) {
        return false;
    }
    c->max_speed = max_speed;
    return true;
}

bool generateCar(car *c) {
    c->max_speed = randomShort(1, 101);
    return true;
}

void writeCarToFile(const car& c, FILE *const& fout) {
    fprintf(fout, "Car can speed up to %hd km.", c.max_speed);
}
