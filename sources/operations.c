#include <string.h>
#include "../headers/operations.h"
#include "../headers/fileInterations.h"

void addData(char *name, char *number) {
    int isNumberValid = strlen(number) == 11;
    for (int i = 0; isNumberValid && number[i] != '\0'; i++) {
        if (number[i] < '0' || number[i] > '9') {
            isNumberValid = 0;
        }
    }
    if (isNumberValid) {
        FILE *file = getDataFile();
        fprintf(file, "%s %s\n", name, number);
        printf("success!\n");
        fclose(file);
    } else {
        printf("INVALID PHONE NUMBER\n");
    }
}