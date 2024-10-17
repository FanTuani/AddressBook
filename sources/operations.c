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
    Student student[1000], delStu[1000];
    int cnt = 0, delCnt = 0, isFound = 0;
    while (fread(&student[cnt], sizeof(Student), 1, file) != 0) {
        if (strcmp(student[cnt].name, delName) == 0) {
            cnt--;
            delCnt++;
            isFound = 1;
        }
        cnt++;
    }
    fclose(file);
    if (isFound) {
        for (int i = 0; i < delCnt; i++) {
            printf("%s %s\n", delStu[i].name, delStu[i].number);
        }
        printf("%d record was found\nare you sure to delete it? [y/n]\n", delCnt);
        char op;
        scanf("%c", &op);
        getchar();
        if (op != 'y') { // info could be better
            return 1;
        }
        file = fopen(DATAFILE, "wb+");
        for (int i = 0; i < cnt; i++) {
            fwrite(&student[i], sizeof(Student), 1, file);
        }
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

int isDataExist(const char *name) {
    FILE *file = fopen(DATAFILE, "rb+");
    Student student;
    while (fread(&student, sizeof(Student), 1, file) != 0) {
        if (strcmp(student.name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int isBlankFile() {
    FILE *file = fopen(DATAFILE, "rb+");
    int isblankFile = 1;
    while (1) {
        Student student;
        if (fread(&student, sizeof(Student), 1, file) == 0) {
            break;
        }
        isblankFile = 0;
    }
    fclose(file);
    return isblankFile;
}