#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool isWordPresent(string sentence, string word)
{
    stringstream s(sentence);
    string temp;

    while (s >> temp)
    {
        if (temp.compare(word) == 0) // If word matches
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Writing to "logfile.txt"
    ofstream o1("logfile.txt");
    if (!o1) { // Check if the file is open
        cerr << "Error opening logfile.txt for writing!" << endl;
        return 1;
    }
    o1 << "[2023-12-1 10:00:00] Application started" << endl;
    o1 << "[2023-12-1 10:00:05] Error : Connection Failed" << endl;
    o1 << "[2023-12-1 10:10:00] Error : Database Error" << endl;
    o1 << "[2023-12-1 10:15:00] Warning: Close the Application" << endl;
    o1.close(); // Always close the file after writing

    // Writing error lines to "error.txt"
    ofstream e1("error.txt");
    if (!e1) { // Check if the file is open
        cerr << "Error opening error.txt for writing!" << endl;
        return 1;
    }

    string line;
    string word = "Error";
    ifstream in("logfile.txt");
    if (!in) { // Check if the file is open
        cerr << "Error opening logfile.txt for reading!" << endl;
        return 1;
    }

    while (getline(in, line)) // Ensure that we read only when the line is valid
    {
        if (isWordPresent(line, word)) // If the word "Error" is found in the line
        {
            e1 << line << endl; // Write the line to "error.txt"
        }
        cout << line << endl; // Output each line to the console
    }
    in.close();  // Always close the file after reading
    e1.close();  // Close the output file after writing

    return 0;
}
