#include "../headers/displays.h"
#include "../headers/operations.h"
#include "../headers/student.h"

#ifdef _WIN32
#include <conio.h>
void displayMainMenu() {
    char menu[6][30] = {"", "LIST ALL", "APPEND", "DELETE", "MODIFY", "EXIT"};
    int cur = 1;
    char ch;
    do {
        if (ch == 72) {  // up
            cur = cur - 1 == 0 ? 5 : cur - 1;
        } else if (ch == 80) {  // down
            cur = cur + 1 == 6 ? 1 : cur + 1;
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
    } else if (op == 0) {
        clear_screen();
        exit(0);
    }
}
#endif

void displayList() {
    clear_screen();
    FILE* file = fopen(DATAFILE, "rb+");
    int isblankFile = 1;
    while (1) {
        Student student;
        if (fread(&student, sizeof(Student), 1, file) == 0) {
            break;
        }
        printf("%s %s\n", student.name, student.number);
        isblankFile = 0;
    }
    if (isblankFile) {
        printf("<none>\n");
    }
    fclose(file);
    getchar();
}

void displayAppend() {
    clear_screen();
    Student* student = malloc(sizeof(Student));
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
    printf("name: ");
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
    if (checkData(oriName) == 0) {
        printf("INVALID ORIGIN NAME");
        getchar();
        return;
    }

    Student* student = malloc(sizeof(Student));
    printf("new name: ");
    scanf("%s", student->name);
    getchar();
    printf("new number: ");
    scanf("%s", student->number);
    getchar();

    print_info(addData(student) && deleteData(oriName), "INVALID INPUT");
    getchar();
}