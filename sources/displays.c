#include <string.h>
#include "../headers/displays.h"
#include "../headers/operations.h"

#ifdef _WIN32

#include <conio.h>

#define OPT_NUM 6

void displayMainMenu() {
    char menu[OPT_NUM + 1][30] = {"", "LIST ALL", "APPEND", "DELETE", "MODIFY", "SEARCH", "EXIT"};
    int cur = 1;
    char ch = 0;
    do {
        if (ch == 72) {  // up
            cur = cur - 1 == 0 ? OPT_NUM : cur - 1;
        } else if (ch == 80) {  // down
            cur = cur + 1 == OPT_NUM + 1 ? 1 : cur + 1;
        } else if (ch == 13) {  // enter
            switch (cur) {
                case 1:
                    displayList();
                    break;
                case 2:
                    displayAppend();
                    break;
                case 3:
                    displayDelete();
                    break;
                case 4:
                    displayModify();
                    break;
                case 5:
                    displaySearch();
                    break;
                default:
                    exit(0);
            }
        } else {
            if (ch == 49) {  // 1
                displayList();
            } else if (ch == 50) {  // 2
                displayAppend();
            } else if (ch == 51) {  // 3
                displayDelete();
            } else if (ch == 52) {  // 4
                displayModify();
            } else if (ch == 53) {  // 5
                displaySearch();
            } else if (ch == 54) {  // 6
                exit(0);
            }
        }
        clear_screen();
        printf("ADDRESS BOOK\n");
        printf("* you can navigate via arrow or number keys.\n");
        for (int i = 1; i <= OPT_NUM; i++) {
            if (i == cur) {
                printf("\33[33m> ");
            }
            printf("%d. %s", i, menu[i]);
            if (i == cur) {
                printf("\33[0m");
            }
            printf("\n");
        }
    } while (ch = getch());
}

#elif __linux__
void displayMainMenu() {
    clear_screen();
    printf("ADDRESS BOOK\n");
    printf("1. LIST ALL\n");
    printf("2. APPEND\n");
    printf("3. DELETE\n");
    printf("4. MODIFY\n");
    printf("0. EXIT\n");
    int op;
    scanf("%d", &op);
    getchar();
    if (op == 1) {
        displayList();
    } else if (op == 2) {
        displayAppend();
    } else if (op == 3) {
        displayDelete();
    } else if (op == 4) {
        displayModify();
    } else if (op == 5) {
        displaySearch();
    } else if (op == 0) {
        clear_screen();
        exit(0);
    }
}
#endif

void displayList() {
    clear_screen();
    FILE *file = fopen(DATAFILE, "rb+");
    if (isBlankFile()) {
        printf("<none>\n");
        getchar();
        return;
    }
    printf("[name] [number]\n");
    while (1) {
        Student student;
        if (fread(&student, sizeof(Student), 1, file) == 0) {
            break;
        }
        printf("%s %s\n", student.name, student.number);
    }
    fclose(file);
    getchar();
}

void displayAppend() {
    clear_screen();
    Student *student = malloc(sizeof(Student));
    printf("name: ");
    scanf("%s", student->name);
    getchar();
    printf("number: ");
    scanf("%s", student->number);
    getchar();

    print_info(addData(student), "INVALID PHONE NUMBER");
    getchar();
}

void displayDelete() {
    clear_screen();
    char name[MAXLENGTH];
    printf("name to be deleted: ");
    scanf("%s", name);
    getchar();

    print_info(deleteData(name), "INVALID NAME");
    getchar();
}

void displayModify() {
    clear_screen();
    char oriName[MAXLENGTH];
    printf("origin name: ");
    scanf("%s", oriName);
    getchar();
    if (isDataExist(oriName) == 0) {
        printf("INVALID ORIGIN NAME");
        getchar();
        return;
    }

    Student *student = malloc(sizeof(Student));
    printf("new name: ");
    scanf("%s", student->name);
    getchar();
    printf("new number: ");
    scanf("%s", student->number);
    getchar();

    print_info(addData(student) && deleteData(oriName), "INVALID INPUT");
    getchar();
}

void displaySearch() {
    clear_screen();
    char options[3][20] = {"", "name", "number"};
    printf("which way to search?\n[1]name [2]number\n");
    int op;
    scanf("%d", &op);
    getchar();
    printf("%s: ", options[op]);
    char input[20];
    scanf("%s", input);
    getchar();
    clear_screen();

    FILE *file = fopen(DATAFILE, "rb+");
    int isBlank = 1;
    while (1) {
        Student student;
        if (fread(&student, sizeof(Student), 1, file) == 0) {
            break;
        }
        if (op == 1 && strcmp(student.name, input) == 0) {
            printf("%s %s\n", student.name, student.number);
            isBlank = 0;
        } else if (op == 2 && strcmp(student.number, input) == 0) {
            printf("%s %s\n", student.name, student.number);
            isBlank = 0;
        }
    }
    if (isBlank) {
        printf("<none>\n");
    }
    fclose(file);
    getchar();
}