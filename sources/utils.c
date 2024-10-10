#include "../headers/utils.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");   // Windows系统
#elif __linux__
    system("clear"); // Linux系统
#elif __APPLE__
    system("clear"); // macOS系统
#else
    printf("Unsupported OS\n");
#endif
}