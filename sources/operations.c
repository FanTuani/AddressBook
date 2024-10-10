#include <string.h>
#include "../headers/operations.h"

int addData(const char *name, const char *number) {
    int isNumberValid = strlen(number) == 11;
    for (int i = 0; isNumberValid && number[i] != '\0'; i++) {
        if (number[i] < '0' || number[i] > '9') {
            isNumberValid = 0;
        }
    }
    if (isNumberValid) {
        FILE *file = fopen(DATAFILE, "a+");
        fprintf(file, "%s %s\n", name, number);
        printf("success!\n");
        fclose(file);
        return 0;
    } else {
        printf("INVALID PHONE NUMBER\n");
        return 1;
    }
}

void deleteData(const char *delName) {
    FILE *file = fopen(DATAFILE, "r");
    char name[1000][MAXLENGTH], number[1000][MAXLENGTH];
    int cnt = 0, isFound = 0;
    while (fscanf(file, "%s%s", name[cnt], number[cnt]) != EOF) {
        if (strcmp(name[cnt], delName) == 0) {
            cnt--;
            isFound = 1;
        }
        cnt++;
    }
    fclose(file);
    if (isFound) {
        file = fopen(DATAFILE, "w");
        for (int i = 0; i < cnt; i++) {
            fprintf(file, "%s %s\n", name[i], number[i]);
        }
        fclose(file);
        printf("success");
    } else {
        printf("INVALID NAME");
    }
}

int checkData(const char *checkName) {
    FILE *file = fopen(DATAFILE, "r");
    char name[MAXLENGTH], number[MAXLENGTH];
    while (fscanf(file, "%s%s", name, number) != EOF) {
        if (strcmp(name, checkName) == 0) {
            return 1;
        }
    }
    return 0;
}