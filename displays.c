#include <string.h>
#include "displays.h"
#include "fileInterations.h"
#include "constants.h"

void displayMainMenu() {
    system("cls");
    printf("Address book\n");
    printf("1. Display all\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Modify\n");
    printf("0. Exit\n");
}

void displayList() {
    system("cls");
    FILE *file = getDataFile();
    char name[MAXLENGTH], number[MAXLENGTH];
    while (fscanf(file, "%s%s", name, number) != EOF) {
        printf("%s %s\n", name, number);
    }
    fclose(file);
    getchar();
}

void displayAdd() {
    system("cls");
    char name[MAXLENGTH], number[MAXLENGTH];
    printf("name: ");
    scanf("%s", name);
    getchar();
    printf("number: ");
    scanf("%s", number);
    getchar();

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
    getchar();
}

void displayDelete() {

}