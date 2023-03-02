#pragma warning(disable : 4996) // fopen_s 
#include "function_p.h"



int add_info_p(const char* path, char array[][MAX_STORAGE], int size) {
    FILE* inFile = fopen(path, "a");
    if (inFile == NULL) {
        cout << "Error! Denied access to the file." << endl;
    }
    else {
        cout << "Enter number of strings to add: " << endl;
        cin >> size;
        cin.ignore();
        cout << "Enter info: " << endl;
        for (int i = 0; i < size; i++) {
            fgets(array[i], 99, stdin);
            fprintf(inFile, array[i]);
        }
    }
    fclose(inFile);
    return size;
}

void swap_p(char array[][MAX_STORAGE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strlen(array[j]) < strlen(array[j + 1])) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void out_file_p(const char* path, char array[][MAX_STORAGE], int size) {
    FILE* outFile = fopen(path, "a");
    if (outFile == NULL) {
        cout << "Error! Something went wrong with output file." << endl;
    }
    else {
        cout << "\nSending data to output file..." << endl;
        for (int i = 0; i < size; i++) {
            fprintf(outFile, "Number of symbols: %2d | %s", strlen(array[i])-1, array[i]);
        }
    }
    fclose(outFile);

    char info2 = 0;
    FILE* outFile2 = fopen(path, "r");
    if (outFile == NULL) {
        cout << "Ops, file isn`t opened." << endl;
    }
    else {
        cout << "Data was send succesfully! Requesting data from input file...\n" << endl;
        while (info2 != EOF) {
            info2 = fgetc(outFile2);
            cout << info2;
        }
    }
    fclose(outFile2);
}