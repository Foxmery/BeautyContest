#include "file_manager.h"




bool saveToFile(Contestants contestant[], string filePath) {
    // Open file for writing (out) in binary mode (binary)
    ofstream file(filePath, ios::out | ios::binary);

    if (!file) {
        cout << "Error opening file! " << filePath << endl;
        return false;
    }

    for (int i = 0; i < MAXCONTESTANTS; i++) {
        if (contestant[i].isObjectUsed) {

            file.write((char*)&contestant[i], sizeof(Contestants));
        }
    }
    file.close();
    return true;
}

bool loadFromFile(Contestants contestant[], string filePath) {
    ifstream file(filePath, ios::in | ios::binary);

    if (!file) 
    {
        cout << "Can't load! No such file: " << filePath << endl;
        return false;
    }
    resetContestants(contestant);

    Contestants temp;
    int index = 0;

    while (file.read((char*)&temp, sizeof(Contestants))) {
        if (index < MAXCONTESTANTS) {
            contestant[index] = temp; 
            index++;
        }
    }
    file.close();
    return true;
}

bool removeFileData(string filePath){
    ofstream file(filePath, ios::out | ios::trunc | ios::binary);

    if(!file){
        cout << "Couldn't delete file data of: " << filePath << endl;
        return false;
    }

    file.close();
    return true;
}

