
/*
Model(1)
Q1: Write a C++ program to create a file named info.txt and save your "Name" and "ID" inside it.

Q2 : Write a C++ program to open info.txt and display its content word by word on the screen.
*/



//Answers :

    // Q1
#include <iostream>
#include <fstream>
    using namespace std;

int main() {
    ofstream write_object("info.txt");
    if (write_object) {
        write_object << "Ahmed 12345";
        write_object.close();
    }
    return 0;
}

// Q2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream read_object("info.txt");
    string word;
    while (read_object >> word) {
        cout << word << endl;
    }
    read_object.close();
    return 0;
}

/*
Model(2)
Q1: Write a C++ program that adds the sentence "New Record" to the end of an existing file named log.txt without deleting the old data.

Q2 : Write a C++ program to read log.txt and display the content line by line on the screen.
*/

//Answers :

    // Q1
#include <iostream>
#include <fstream>
    using namespace std;

int main() {
    ofstream write_object("log.txt", ios::app);
    write_object << "New Record" << endl;
    write_object.close();
    return 0;
}

// Q2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream read_object("log.txt");
    string line;
    while (getline(read_object, line)) {
        cout << line << endl;
    }
    read_object.close();
    return 0;
}

/*
Model(3)
Q1: Write a C++ program to create a file called data.txt and write the numbers 10 and 20 inside it.

Q2 : Write a C++ program to open data.txt and count the total number of characters inside the file.
*/

//Answers :

    // Q1
#include <iostream>
#include <fstream>
    using namespace std;

int main() {
    ofstream write_object("data.txt");
    write_object << 10 << " " << 20;
    write_object.close();
    return 0;
}

// Q2
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream read_object("data.txt");
    char ch;
    int count = 0;
    while (read_object.get(ch)) {
        count++;
    }
    cout << "Total characters: " << count << endl;
    read_object.close();
    return 0;
}

/*
Model(4)
Q1: Write a C++ program to open a file named report.txt.If the file contains old data, the program should erase it and write "Fresh Start" instead.

Q2 : Write a C++ program to calculate and print the total size of report.txt in bytes.
*/
//Answers :

    // Q1
#include <iostream>
#include <fstream>
    using namespace std;

int main() {
    ofstream write_object("report.txt", ios::trunc);
    write_object << "Fresh Start";
    write_object.close();
    return 0;
}

// Q2
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream read_object("report.txt");
    read_object.seekg(0, ios::end);
    cout << "Size: " << read_object.tellg() << " bytes" << endl;
    read_object.close();
    return 0;
}

/*Model(5)
Q1: Write a C++ program that reads the content of source.txt and copies it into a new file called backup.txt.

Q2 : Write a C++ program that opens backup.txt and replaces the very first character of the file with the character 'X'.
*/
//Answers :

    // Q1
#include <iostream>
#include <fstream>
#include <string>
    using namespace std;

int main() {
    ifstream read_object("source.txt");
    ofstream write_object("backup.txt");
    string line;
    while (getline(read_object, line)) {
        write_object << line << "\n";
    }
    read_object.close();
    write_object.close();
    return 0;
}

// Q2
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file_object("backup.txt", ios::in | ios::out);
    file_object.seekp(0, ios::beg);
    file_object.put('X');
    file_object.close();
    return 0;
}


/*Model(6)
Q1: Write a C++ program to create an exact copy of an image file named picture.jpg.The new copy should be named clone.jpg.

Q2 : Write a C++ program to open a file named data.txt and check if it opens successfully.If it exists, print "File Found", otherwise print "File Missing".
*/
//Answers :

    // Q1
#include <iostream>
#include <fstream>
    using namespace std;

int main() {
    ifstream read_object("picture.jpg", ios::binary);
    ofstream write_object("clone.jpg", ios::binary);
    char ch;
    while (read_object.get(ch)) {
        write_object.put(ch);
    }
    read_object.close();
    write_object.close();
    return 0;
}

// Q2
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream read_object("data.txt");
    if (!read_object) {
        cout << "File Missing" << endl;
    }
    else {
        cout << "File Found" << endl;
    }
    read_object.close();
    return 0;
}