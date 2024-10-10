#include <stdio.h>
#include "../headers/displays.h"
#include "../headers/operations.h"

int main() {
    while(1) {
        displayMainMenu();
        int op;
        scanf("%d", &op);
        getchar();
        switch (op) {
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
                return 0;
        }
    }
}
