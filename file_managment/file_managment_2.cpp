/*
    fstream class:
    --------------
    - It is capable of both reading and writing to a file.
    - It combines the features of ifstream and ofstream.

    Access Modes:
    -------------
    ios::in     -> Open file for reading.
    ios::out    -> Open file for writing.
    ios::app    -> Append data to the end of file.
    ios::trunc  -> Delete previous data when opening file.
    ios::binary -> Open file in binary mode.

    Always check if file is opened successfully!
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file;

    // Open file for writing and create it if it doesn't exist
    file.open("example.txt", ios::out);
    if (!file) {
        cout << "Error creating file!" << endl;
        return 1;
    }
    file << "This file was created using fstream.\n";
    file << "We can read and write using the same object.";
    file.close();



    // Open file for reading
    file.open("example.txt", ios::in);
    if (!file) {
        cout << "Error reading file!" << endl;
        return 1;
    }

    string word;
    cout << "\nContent of example.txt:\n";
    while (file>> word) {
        cout << word << endl;
    }
    file.close();

    return 0;
}

