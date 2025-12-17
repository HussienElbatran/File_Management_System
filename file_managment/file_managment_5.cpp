/*
    Copying text file:
    - We open the source file in input mode (ios::in)
    - And the destination file in output mode (ios::out)
    - We read line by line and write into the new file.
*/



/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream sourceFile("source.txt", ios::in);   // File to read from
    fstream destFile("copy.txt", ios::out);      // File to write to

    if (!sourceFile || !destFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(sourceFile, line)) { // Read line from source
        destFile << line << endl;      // Write line to destination
    }

    sourceFile.close();
    destFile.close();

    cout << "Text copied successfully!" << endl;
    return 0;
}
*/



/*
    Copying an image:
    - Image files must be accessed in binary mode.
    - ios::binary allows reading raw binary bytes (not text format).
    - We read character by character and write to the new file.
*/




/*
#include <iostream>
#include <fstream>
using namespace std; 

int main() {
    fstream src("image.jpg", ios::in | ios::binary);   // Open original image
    fstream dest("copy_image.jpg", ios::out | ios::binary); // Open new copy file

    if (!src || !dest) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char ch;
    while (src.get(ch)) { // Read byte by byte
        dest.put(ch);     // Write byte to destination
    }

    src.close();
    dest.close();

    cout << "Image copied successfully!" << endl;
    return 0;
}
*/