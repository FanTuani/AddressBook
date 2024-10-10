#include <string.h>
#include "../headers/displays.h"
#include "../headers/operations.h"
#include "../headers/fileInterations.h"

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
    if (strlen(name) == 0) {
        printf("<none>\n");
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

    addData(name, number);
    getchar();
}

void displayDelete() {

}