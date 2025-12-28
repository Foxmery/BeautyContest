#include "file_manager.h"


void saveToFile(Contestants contestant[]) {
    // Open file for writing (out) in binary mode (binary)
    ofstream file("contestants.dat", ios::out | ios::binary);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }


    for (int i = 0; i < MAXCONTESTANTS; i++) {
        if (contestant[i].isObjectUsed) {

            file.write((char*)&contestant[i], sizeof(Contestants));
        }
    }
    file.close();
    cout << "Data saved successfully." << endl;
}

void loadFromFile(Contestants contestant[]) {
    ifstream file("contestants.dat", ios::in | ios::binary);

    //TODO: make file if not exist
    if (!file) return; // No file exists yet

    Contestants temp;
    int index = 0;

    // Read one struct at a time until End of File (EOF)
    while (file.read((char*)&temp, sizeof(Contestants))) {
        if (index < MAXCONTESTANTS) {
            contestant[index] = temp; // Copy the loaded data into the array
            index++;
        }
    }
    file.close();
}