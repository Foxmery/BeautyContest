#include "file_manager.h"
#include <fstream>


void saveToFile(Contestants contestant[]) {
    // Open file for writing (out) in binary mode (binary)
    ofstream file("contestants.dat", ios::out | ios::binary);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Loop through used contestants
    for (int i = 0; i < MAXCONTESTANTS; i++) {
        if (contestant[i].isObjectUsed) {
            // Write the memory of the struct directly to the file
            // (char*)&contestant[i] -> Treat the struct as a raw byte array
            // sizeof(Contestants)   -> How many bytes to write
            file.write((char*)&contestant[i], sizeof(Contestants));
        }
    }
    file.close();
    cout << "Data saved successfully." << endl;
}