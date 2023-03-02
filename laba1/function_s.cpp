#include "function_s.h"

void add_info(string path, string* array) {
    int size;

    fstream inFile;
    inFile.open(path, ios::app);

    if (!inFile.is_open()) {
        cout << "InputFile error!" << endl;
    }
    else {
        cout << "Adding data to input file.\n" << endl;
        cout << "Enter number of rows: ";
        cin >> size;
        std::cin.ignore();

        cout << "Enter info to add: " << endl;
        for (int i = 0; i < size; i++) {
            std::getline(cin, array[i]);
            inFile << array[i] << endl;
        }
    }
    inFile.close();
}

int request_info(string path, string* array, int lines) {
    fstream inFile1;
    inFile1.open(path, ios::in);

    if (!inFile1.is_open()) {
        cout << "Error. File isn`t opened." << endl;
    }
    else {
        cout << "\nRequesting data from input file." << endl;
        while (!inFile1.eof()) {
            getline(inFile1, array[lines]);
            cout << array[lines] << endl;
            lines++;
        }
        lines--;
    }
    inFile1.close();
    return lines;
}

void swap(string* array, int lines) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines - i - 1; j++) {
            if (array[j].length() < array[j + 1].length()) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void output_file(string path, string* array, int lines) {
    fstream outFile;
    outFile.open(path, ios::app); // ios::trunc | ios::out

    if (!outFile.is_open()) {
        cout << "OutputFile error!" << endl;
    }
    else {
        cout << "Sending data to output file..." << endl;

        for (int i = 0; i < lines; i++) {
            outFile << "Number of symbols: " << setw(2) << array[i].length() << " | " << array[i] << endl;
        }
    }
    outFile.close();

    outFile.open(path, ios::in);
    string input_info2[MAX_STORAGE];

    if (!outFile.is_open()) {
        cout << "Error! File isn`t opened for reading." << endl;
    }
    else {
        cout << "\nData was send succesfully! Requesting data from input file..." << endl;
        int p = 0;
        while (!outFile.eof()) {
            getline(outFile, input_info2[p]);
            cout << input_info2[p] << endl;
            p++;
        }
    }
    outFile.close();
}