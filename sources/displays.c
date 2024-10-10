#include <string.h>
#include <conio.h>
#include "../headers/displays.h"
#include "../headers/operations.h"

void displayMainMenu() {
    char menu[6][30] = {"", "LIST ALL", "APPEND", "DELETE", "MODIFY", "EXIT"};
    int cur = 1;
    char ch;
    do {
//        printf("%d", ch);
        if (ch == 72) { // up
            cur = cur - 1 == 0 ? 5 : cur - 1;
        } else if (ch == 80) { // down
            cur = cur + 1 == 6 ? 1 : cur + 1;
        } else if (ch == 13) { // enter
            switch (cur) {
                case 1:
                    displayList();
                    break;
                case 2:
                    displayAdd();
                    break;
                case 3:
                    displayDelete();
                    break;
                case 4:
                    displayModify();
                    break;
                default:
                    exit(0);
            }
        } else {
            if (ch == 49) { // 1
                displayList();
            } else if (ch == 50) { // 2
                displayAdd();
            } else if (ch == 51) { // 3
                displayDelete();
            } else if (ch == 52) { // 4
                displayModify();
            } else if (ch == 53) { // 5
                exit(0);
            }
        }
        clear_screen();
        printf("ADDRESS BOOK\n");
        for (int i = 1; i <= 5; i++) {
            if (i == cur) {
                printf("\33[33m> ");
            }
            printf("%d. %s", i, menu[i]);
            if(i == cur) {
                printf("\33[0m");
            }
            printf("\n");
        }
    } while (ch = getch());
}

void displayList() {
    clear_screen();
    FILE *file = fopen(DATAFILE, "a+");
    char name[MAXLENGTH], number[MAXLENGTH];
    int isblankFile = 1;
    while (fscanf(file, "%s%s", name, number) != EOF) {
        printf("%s %s\n", name, number);
        isblankFile = 0;
    }
    if (isblankFile) {
        printf("<none>\n");
    }
    fclose(file);
    getchar();
}

void displayAdd() {
    clear_screen();
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
    clear_screen();
    char name[MAXLENGTH];
    printf("name: ");
    scanf("%s", name);
    getchar();

    deleteData(name);
    getchar();
}

void displayModify() {
    clear_screen();
    char oriName[MAXLENGTH], name[MAXLENGTH], number[MAXLENGTH];
    printf("origin name: ");
    scanf("%s", oriName);
    getchar();
    if (checkData(oriName) == 0) {
        printf("INVALID ORIGIN NAME");
        getchar();
        return;
    }

    printf("new name: ");
    scanf("%s", name);
    getchar();
    printf("new number: ");
    scanf("%s", number);
    getchar();

    if (addData(name, number) == 0) {
        deleteData(oriName);
    }
    getchar();
}