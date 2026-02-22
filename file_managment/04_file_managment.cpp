/*
    When we use ios::in (read mode) with ios::out (write mode) together:

        fstream file("data.txt", ios::in | ios::out);

    The rule is:
    - ios::in requires that the file MUST already exist, otherwise the open will FAIL.
    - So if the file does not already exist, it will NOT be created.

    To allow the file to be created, we must add one of the following:

    1) ios::app   -> Open for adding data at the end. If file doesn't exist, it will be created.
    2) ios::trunc -> Create the file if it doesn't exist AND delete old contents if it does.

    Therefore:
        ios::in | ios::out            ? does NOT create a new file.
        ios::in | ios::out | ios::app ? creates (or appends if exists).
        ios::in | ios::out | ios::trunc ? creates new file (clears old one if exists).
*/



// Open file for reading and writing, append mode


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream file;
    file.open("example_append.txt", ios::in | ios::out | ios::app);

    if (!file) {
        cout << "Error opening/creating file!" << endl;
        return 1;
    }

    // Write (append) text to the end of the file
    file << "Appending this text.\n";

    // Move pointer to beginning to read from start
    file.seekg(0);

    cout << "File contents:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}




// Open file for reading and writing, clear old content


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file;
    file.open("example_trunc.txt", ios::in | ios::out | ios::trunc);

    if (!file) {
        cout << "Error opening/creating file!" << endl;
        return 1;
    }

    // Write new content (previous data is erased)
    file << "This is new content after truncation.\n";

    // Move pointer back to beginning for reading
    file.seekg(0);

    cout << "File contents:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
