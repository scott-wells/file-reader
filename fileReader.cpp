#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile();
void readEachChar();
void writeFile();
int countEachLine();
int countFileBytes(ifstream &inputFile);

int main() {

    // readFile();
    // readEachChar();
    // writeFile();
    // int total = countEachLine();
    // cout << total << endl;
    ifstream inputFile("fun.txt");
    int bytes = countFileBytes(inputFile);
    cout << "\n" << "File contains " << bytes << " bytes" << endl;
    return 0;
}

void readFile() {
    ifstream inputFile("ipsum.txt");

    if(inputFile.is_open()){
        string line;
        while(getline(inputFile, line)){    
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Failed to open file" << endl;
    }
}

void readEachChar() {
    ifstream inputFile("blank.txt");

    if(inputFile.is_open()) {
        char e;
        while(inputFile.get(e)) {
            cout << e << endl;
        }
    } else {
        cout << "Failed to open file" << endl;
    }
}

void writeFile() {
    ofstream outputFile("blank.txt");

    if(outputFile.is_open()){
        outputFile << "Hello World!" << endl;
        outputFile << "Here is some new text on a line." << endl;
        outputFile.close();
        cout << "Data written to file" << endl;
    } else {
        cout << "Failed to open file" << endl;
    }
}

int countEachLine() {
    ifstream input("fun.txt");
    int numLines;
    string line;
    if(input.is_open()) {
        string line;
        while(getline(input, line)) {

            cout << line << endl;
            numLines++;
        }
    } else {
        cout << "File failed to open" << endl;
    }

    return numLines;
}

int countFileBytes(ifstream &inputFile) {
    int bytes;
    if(inputFile.is_open()) {
        char e;
        while(inputFile.get(e)) {
            bytes += sizeof(e);
        }
    } else {
        cout << "File failed to open" << endl;
    }
    return bytes;
}