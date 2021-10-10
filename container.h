#ifndef AVS_HW1_CONTAINER_H
#define AVS_HW1_CONTAINER_H

struct container {
    const int kMaxSize = 10 * 1000;
    int size = 0;
    transport cont[kMaxSize];
};

double getAverageDistance(const container& cont) {
    double aggregate_distance = 0;
    for (int i = 0 ; i < cont.size ; ++i) {
        aggregate_distance += cont.cont[i];
    }
    return aggregate_distance / cont.size;
}

void removeLesserThanAverage(container *cont) {
    double average = getAverageDistance(cont);
    int new_size = 0;
    transport new_cont[] = new transport[cont.kMaxSize];
    for (int i = 0 ; i < cont.size ; ++i) {
        if (getMaxDistance(cont->cont[i]) < average) {
            continue;
        }
        new_cont[new_size++] = cont->cont[i];
    }
    cont->size = new_size;
    cont->cont = new_cont;
}


#endif //AVS_HW1_CONTAINER_H
