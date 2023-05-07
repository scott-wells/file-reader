#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(const string &fileName);
void readEachChar(const string &fileName);
void writeFile(const string &fileName);
int countEachLine(const string &fileName);
int countFileBytes(const string &fileName);
void insertToFileNthLine(const string &inputFileName, const string &outputFileName, int num);
void deleteFileContents(const string &fileName);

int main() {
    ifstream inputFile("fun.txt");
    ofstream outputFile("blank.txt");
    ifstream modifiedFile("blank.txt");

    // insertToFileNthLine(inputFile, outputFile, 10);
    // readFile(modifiedFile);
    deleteFileContents("blank.txt");
    return 0;
}

void readFile(const string &fileName) {
    ifstream inputFile(fileName);

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

void readEachChar(const string &fileName) {
    ifstream inputFile(fileName);

    if(inputFile.is_open()) {
        char e;
        while(inputFile.get(e)) {
            cout << e << endl;
        }
    } else {
        cout << "Failed to open file" << endl;
    }
}

void writeFile(const string &fileName) {
    ofstream outputFile(fileName);

    if(outputFile.is_open()){
        outputFile << "Hello World!" << endl;
        outputFile << "Here is some new text on a line." << endl;
        outputFile.close();
        cout << "Data written to file" << endl;
    } else {
        cout << "Failed to open file" << endl;
    }
}

int countEachLine(const string &fileName) {
    ifstream input(fileName);
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

int countFileBytes(const string &fileName) {
    ifstream inputFile(fileName);
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

void insertToFileNthLine(const string &inputFileName, const string &outputFileName, int num) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

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

void deleteFileContents(const string &fileName) {
    ofstream outputFile(fileName);

    if(!outputFile) {
        cout << "Failed to open output file" << endl;
        return;
    }

    outputFile << "";
    outputFile.close();
}