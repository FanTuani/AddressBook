#include "fileInterations.h"

FILE *getDataFile() {
    FILE *file = fopen("data.txt", "a+");
    return file;
}