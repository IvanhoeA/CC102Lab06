#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ofstream outFile("numbers.txt");

    if (!outFile) {
        cerr << "Error: Cannot open txt file" << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;

    outFile.close();

    ifstream inFile("numbers.txt");

    if (!inFile) {
        cerr << "Txt file cannot be opened" << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();


    //sorting
    sort(words.begin(), words.end());

    ofstream sortedFile("alphabeticalnumbers.txt");

    if (!sortedFile) {
        cerr << "Error, can't be sorted" << endl;
        return 1;
    }

    for (const string& word : words) {
        sortedFile << word << endl;
    }

    sortedFile.close();

    cout << "Words are successfully sorted alphabetically!" << endl;

    return 0;
}
