/*
    Reading word by word:
    - We use the >> operator which extracts text up to whitespace.
*/


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("file.txt", ios::in); // Open file for reading

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string word;
    while (file >> word) { // Reads one word at a time
        cout << word << endl;
    }

    file.close();
    return 0;
}





/*
    Reading char by char:
    - We use file.get() which reads a single character at a time.
*/


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("file.txt", ios::in);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char ch;
    while (file.get(ch)) { // Reads a single character per iteration
        cout << ch;
    }

    file.close();
    return 0;
}




/*
    Reading line by line:
    - We use getline() which reads an entire line including spaces until newline.
    from string class
*/



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file("file.txt", ios::in);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) { // Reads one full line each time
        cout << line << endl;
    }

    file.close();
    return 0;
}
*/

/*
    eof():
    - Stands for "End Of File".
    - Returns true when the file reading reaches the end.
    - Tells us when we've reached the end of the file.
*/



#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("file.txt", ios::in);

    if (!file) return 1;

    while (!file.eof()) { // While not at end of file
        string word;
        file >> word;
        cout << word << endl;
    }

    file.close();
    return 0;
}


/*
    fail():
    - Returns true if a read/write operation fails (wrong data format).
    - Detects reading errors or invalid input.
*/



#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("file.txt", ios::in);

    if (!file) return 1;

    int number;
    file >> number; // If file contains text, this will fail

    if (file.fail()) {
        cout << "Error: Failed to read number!" << endl;
    }

    file.close();
    return 0;
}



