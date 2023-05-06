#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(ifstream &inputFile);
void readEachChar();
void writeFile();
int countEachLine();
int countFileBytes(ifstream &inputFile);
void insertToFileNthLine(ifstream &inputFile, ofstream &outputFile, int num);

int main() {
    ifstream inputFile("fun.txt");
    ofstream outputFile("blank.txt");
    ifstream modifiedFile("blank.txt");

    insertToFileNthLine(inputFile, outputFile, 10);
    readFile(modifiedFile);
    return 0;
}

void readFile(ifstream &inputFile) {
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

void insertToFileNthLine(ifstream &inputFile, ofstream &outputFile, int num) {
    if(!inputFile) {
        cout << "Failed to open input file for reading" << endl;
        return;
    }

    if(!outputFile) {
        cout << "Failed to open output file for writing" << endl;
        inputFile.close();
        return;
    }

    string line;
    int count;
    string newLine = "XX. THIS IS A BRAND NEW LINE!";

    while(getline(inputFile, line)) {
        count++;
        if(count == num) {
            outputFile << newLine << endl;
        }
        outputFile << line << endl;
    }
    inputFile.close();
    outputFile.close();
}