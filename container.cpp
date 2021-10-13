#include "container.h"

#include<cstdio>

void pushBackToContainer(container *cont, transport& tr) {
    cont->cont[cont->size++] = &tr;
}

bool generateContainer(container *cont, int size) {
    transport *tr;
    for (int i = 0 ; i < size ; ++i) {
        tr = new transport();
        generateTransport(tr);
        pushBackToContainer(cont, *tr);
    }
    return true;
}

bool readContainerFromFile(container *cont, int size, FILE *const& fin) {
    transport *tr;
    for (int i = 0 ; i < size ; ++i) {
        tr = new transport();
        if (!readTransportFromFile(tr, fin)) {
            return false;
        }
        pushBackToContainer(cont, *tr);
    }
    return true;
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
    if (cont.size == 0) {
        return 0;
    }
    return aggregate_distance / cont.size;
}

void removeLesserThanAverage(container *cont) {
    double average = getAverageDistance(*cont);
    int new_size = 0;
    for (int i = 0 ; i < cont->size ; ++i) {
        if (getMaxDistance(*(cont->cont[i])) < average) {
            destroyTransport(cont->cont[i]);
            delete cont->cont[i];
        } else {
            cont->cont[new_size++] = cont->cont[i];
        }
        // If every element stays on its place, we don't nullify any pointers!
        if (i + 1 != new_size) {
            cont->cont[i] = nullptr;
        }
    }
    cont->size = new_size;
}

void writeContainerToFile(const container& cont, FILE *const& fout) {
    fprintf(fout, "There are %d elements in container:\n", cont.size);
    for (int i = 0 ; i < cont.size ; ++i) {
        fprintf(fout, "%d: ", i);
        writeTransportToFile(*(cont.cont[i]), fout);
    }
    fprintf(fout, "\n");
}

void destroyContainer(container *cont) {
    for (int i = 0 ; i < cont->size ; ++i) {
        destroyTransport(cont->cont[i]);
        delete cont->cont[i];
        cont->cont[i] = nullptr;
    }
}
