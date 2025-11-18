#include "MenuManagment.h"

void printMainMenu() {

    cout <<
        "\n-------------BEAUTY CONTEST-------------\n"
        "1. Add new contestant\n"
        "    -Spaces left: spaces left in array\n"
        "    -How many contestants do you want to add (Validation: can't exceed the free spaces left)\n"
        "2. Show all contestants\n"
        "3. Search and show contestants by\n"
        "    3.1 The lowest age (input lowest age)\n"
        "    3.2 Name\n"
        "4. Sort contestants by oldest to youngest (No output)\n"
        "5. File\n"
        "    5.1 Export\n"
        "    5.2 Import\n"
        << endl;
}