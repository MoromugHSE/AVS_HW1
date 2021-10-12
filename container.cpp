#include "container.h"
#include "random.h"

#include<cstdio>

void pushBackToContainer(container *cont, const transport& tr) {
    *(cont->cont[cont->size++]) = tr;
}

bool generateContainer(container *cont, int size) {
    for (int i = 0 ; i < size ; ++i) {
        transport tr{};
        tr.volume = randomInt(1, 201);
        tr.fuel_100km = randomDouble(0.5, 20 + 1e-9);
        switch (randomInt(0, 3)) {
            case 0:
                tr.k = transport::TRUCK;
                tr.t->max_mass = randomInt(1, 1001);
                break;
            case 1:
                tr.k = transport::BUS;
                tr.b->max_passengers = randomShort(1, 41);
                break;
            case 2:
                tr.k = transport::CAR;
                tr.c->max_speed = randomShort(1, 101);
                break;
        }
        pushBackToContainer(cont, tr);
    }
    return true;
}

bool readContainerFromFile(container *cont, int size, FILE *const& fin) {

}

bool createContainer(container *cont, FILE *const& fin) {
    int size;
    fscanf(fin, "%d", &size);
    if (size < 1 || size > 10 * 1000) {
        return false;
    }
    if (size <= 20) {
        return readContainerFromFile(cont, size, fin);
    } else {
        return generateContainer(cont, size);
    }
}

double getAverageDistance(container const& cont) {
    double aggregate_distance = 0;
    for (int i = 0 ; i < cont.size ; ++i) {
        aggregate_distance += getMaxDistance(*(cont.cont[i]));
    }
    return aggregate_distance / cont.size;
}

void removeLesserThanAverage(container *cont) {
    double average = getAverageDistance(*cont);
    container *old_container = cont;
    cont = new container;
    for (int i = 0 ; i < old_container->size ; ++i) {
        if (getMaxDistance(*(old_container->cont[i])) < average) {
            destroyTransport(old_container->cont[i]);
        } else {
            pushBackToContainer(cont, *old_container->cont[i]);
        }
    }
}

void writeContainerToFile(const container& cont, FILE *const& fout) {
    fprintf(fout, "There are %d elements in container:\n", cont.size);
    for (int i = 0 ; i < cont.size ; ++i) {
        fprintf(fout, "%d: ", i);
        switch (cont.cont[i]->k) {
            case transport::TRUCK:
                fprintTruck(fout, *(cont.cont[i]->t));
                break;
            case transport::BUS:
                fprintBus(fout, *(cont.cont[i]->b));
                break;
            case transport::CAR:
                fprintCar(fout, *(cont.cont[i]->c));
                break;
        }
    }
    fprintf(fout, "\n");
}
