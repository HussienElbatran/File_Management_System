/*******************************************************
    FILE STREAM POINTERS IN C++
    --------------------------------
    This code block explains:

    1) What "seek" functions are
    2) seek parameters (offset, direction)
    3) seek directions (ios::beg, ios::cur, ios::end)
    4) seekg() and tellg()  -> input (reading)
    5) seekp() and tellp()  -> output (writing)

    All explanations are written as COMMENTS,
    along with practical C++ examples.
********************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*
========================================================
1) WHAT ARE SEEK FUNCTIONS?
--------------------------------------------------------
File streams maintain an internal pointer that tracks
the current position inside a file.

There are TWO pointers:
- get pointer  -> used for reading (input)
- put pointer  -> used for writing (output)

Functions:
- seekg() : move the GET (read) pointer
- tellg() : tell current GET pointer position
- seekp() : move the PUT (write) pointer
- tellp() : tell current PUT pointer position
========================================================
*/

/*
========================================================
2) SEEK PARAMETERS
--------------------------------------------------------
seekg() and seekp() generally take TWO parameters:

    seekg(offset, direction);
    seekp(offset, direction);

1) offset:
   - Number of bytes to move
   - Can be positive or negative

2) direction:
   - ios::beg  -> beginning of file
   - ios::cur  -> current position
   - ios::end  -> end of file

Example:
    seekg(10, ios::beg);
    // Move 10 bytes from the beginning

    seekg(-5, ios::end);
    // Move 5 bytes backward from the end
========================================================
*/

/*
========================================================
3) SEEK DIRECTIONS
--------------------------------------------------------
ios::beg  : starting point is the beginning of the file
ios::cur  : starting point is the current position
ios::end  : starting point is the end of the file
========================================================
*/

int main()
{
    /***************************************************
        PART A: seekg() and tellg()
        -----------------------------------------------
        Used with ifstream (READING)
    ****************************************************/

    // Create and write sample data to a file first
    {
        ofstream out("example.txt");
        out << "HelloWorld"; // 10 characters
        out.close();
    }

    // Open file for reading
    ifstream in("example.txt");

    /*
    tellg()
    ----------------------------------------------------
    Returns the current position of the GET pointer
    (number of bytes from the beginning)
    */
    cout << "Initial read position: " << in.tellg() << endl;
    // Output: 0 (start of file)

    /*
    seekg(offset, ios::beg)
    ----------------------------------------------------
    Move read pointer to a specific position
    */
    in.seekg(5, ios::beg);  // Move to 6th character
    cout << "After seekg(5, beg): " << in.tellg() << endl;

    char ch;
    in >> ch;  // Read character at position 5
    cout << "Character read: " << ch << endl; // Expected: 'W'

    /*
    seekg(offset, ios::cur)
    ----------------------------------------------------
    Move relative to current position
    */
    in.seekg(2, ios::cur); // Skip 2 characters
    cout << "After seekg(2, cur): " << in.tellg() << endl;

    in >> ch;
    cout << "Character read: " << ch << endl;

    /*
    seekg(offset, ios::end)
    ----------------------------------------------------
    Move relative to the end of file
    */
    in.seekg(-1, ios::end); // Move to last character
    cout << "After seekg(-1, end): " << in.tellg() << endl;

    in >> ch;
    cout << "Last character: " << ch << endl;

    in.close();

    /***************************************************
        PART B: seekp() and tellp()
        -----------------------------------------------
        Used with ofstream / fstream (WRITING)
    ****************************************************/

    // Open file for writing
    fstream file("example2.txt", ios::in | ios::out | ios::trunc);

    /*
    tellp()
    ----------------------------------------------------
    Returns the current position of the PUT pointer
    */
    cout << "\nInitial write position: " << file.tellp() << endl;

    // Write some data
    file << "ABCDE";
    cout << "After writing 'ABCDE', tellp(): "
        << file.tellp() << endl;

    /*
    seekp(offset, ios::beg)
    ----------------------------------------------------
    Move write pointer to overwrite data
    */
    file.seekp(2, ios::beg); // Move to index 2
    file << "X";             // Overwrites 'C'

    /*
    seekp(offset, ios::end)
    ----------------------------------------------------
    Move write pointer to end of file
    */
    file.seekp(0, ios::end);
    file << "FG";

    cout << "Final write position: " << file.tellp() << endl;

    file.close();



    return 0;
}


