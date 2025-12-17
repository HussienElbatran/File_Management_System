/*

    1. ofstream (Output File Stream)
       - Used to WRITE data to files.
       - Main role: Output stream (file output).
       - Important methods:
            open()  -> Opens a file for writing.
            close() -> Closes the file.
            <<      -> Writes data into the file.

    2. ifstream (Input File Stream)
       - Used to READ data from files.
       - Main role: Input stream (file input).
       - Important methods:
            open()  -> Opens a file for reading.
            close() -> Closes the file.
            >>      -> Reads formatted data from file.

    Rules:
    - Always check if a file is successfully opened before reading or writing.
    - Close the file after finishing operations.
*/


/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {


    // Create ofstream object to WRITE to file
    ofstream writeFile("file.txt");
    if (!writeFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    writeFile << "Hello, this is a test file.\nThis line is written using ofstream.";
    writeFile.close(); // Close file after writing




    // Create ifstream object to READ from file
    ifstream readFile("file.txt");
    if (!readFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    string word;
    cout << "\nReading from file:\n";
    while (readFile>> word) {
        cout << word << endl;
    }
    readFile.close();

    return 0;
}

*/

