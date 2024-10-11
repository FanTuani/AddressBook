#include <string.h>
#include "../headers/operations.h"

int addData(const Student *student) {
    const char *number = student->number;
    int isNumberValid = 11 == strlen(number);
    for (int i = 0; isNumberValid && number[i] != '\0'; i++) {
        if (number[i] < '0' || number[i] > '9') {
            isNumberValid = 0;
        }
    }
    if (isNumberValid) {
        FILE *file = fopen(DATAFILE, "ab+");
        fwrite(student, sizeof(Student), 1, file);
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

int deleteData(const char *delName) {
    FILE *file = fopen(DATAFILE, "rb+");
    Student student[1000];
    int cnt = 0, isFound = 0;
    while (fread(&student[cnt], sizeof(Student), 1, file) != 0) {
        if (strcmp(student[cnt].name, delName) == 0) {
            cnt--;
            isFound = 1;
        }
        cnt++;
    }
    fclose(file);
    if (isFound) {
        file = fopen(DATAFILE, "ab+");
        for (int i = 0; i < cnt; i++) {
            fwrite(&student[i], sizeof(Student), 1, file);
        }
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

int checkData(const char *checkName) {
    FILE *file = fopen(DATAFILE, "rb+");
    Student student;
    while (fread(&student, sizeof(Student), 1, file) != 0) {
        if (strcmp(student.name, checkName) == 0) {
            return 1;
        }
    }
    return 0;
}