#include <stdio.h>
#include "displays.h"
#include "operations.h"

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
            default:
                return 0;
        }
    }
}
