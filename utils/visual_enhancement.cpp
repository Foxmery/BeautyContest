#include "visual_enhancement.h"

void clearConsole(bool clear) {
    if (CLEARCONSOLE) {
        if (clear) system("cls");
    }
}