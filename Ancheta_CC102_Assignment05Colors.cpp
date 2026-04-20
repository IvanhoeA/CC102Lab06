#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("color.txt");

    if (!outFile) {
        cerr << "Error: Unable to create or open color.txt for writing." << endl;
        return 1;
    }

    outFile << "Red" << endl;
    outFile << "Blue" << endl;
    outFile << "Cyan" << endl;
    outFile << "Magenta" << endl;
    outFile << "Green" << endl;

    outFile.close();

    ifstream inFile("color.txt");

    if (!inFile) {
        cerr << "Error: Unable to open color.txt" << endl;
        return 1;
    }



    //copying part
    ofstream copyFile("color_copy.txt");

    if (!copyFile) {
        cerr << "Error" << endl;
        inFile.close();
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "File copied successfully!" << endl;

    return 0;
}
