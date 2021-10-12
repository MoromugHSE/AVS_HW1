#include "transport.h"
#include "truck.h"
#include "bus.h"
#include "car.h"
#include "container.h"

#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

int main(int argc, char *argv[]) {
    auto cont = container{};
    if (argc != 3) {
        printf("Incorrect arguments format!\n"
               "Correct:\n"
               "AVS_HW1 in_file out_file\n");
        return 0;
    }
    FILE *fin = fopen(argv[1], "r");
    if (fin == nullptr) {
        printf("File %s is unavailable to read from!\n", argv[1]);
        return 0;
    }
    FILE *fout = fopen(argv[2], "w");
    if (fout == nullptr) {
        printf("File %s is unavailable to write to!", argv[2]);
        return 0;
    }
    createContainer(&cont, fin);
    fprintf(fout, "Container before changes:\n");
    writeContainerToFile(cont, fout);
    removeLesserThanAverage(&cont);
    fprintf(fout, "Container after changes:\n");
    writeContainerToFile(cont, fout);
    return 0;
}
