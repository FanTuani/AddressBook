#include "../headers/utils.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");   // Windows系统
#elif __linux__
    system("clear"); // Linux系统
#else
    printf("Unsupported OS\n");
#endif
}

void print_info(int value, char *info) {
    if (value == 1) {
        printf("success! press ENTER to continue...\n");
    } else {
        printf("%s\n", info);
    }
}