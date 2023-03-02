#include "function_s.h"
#include "function_p.h"

int main(int argc, char* argv[]) // argc - number of arguments, argv[0] - current location, argv[1] - " -mode ", argv[2] - "FilePointer | FileStream"
{   
    string mode_flag(argv[1]);
    string mode(argv[2]);
    if (mode_flag != "-mode") {
        cout << "Something went wrong. Check your input and try again!" << endl;
        return 1;
    }

    if (mode == "FileStream" || mode == "fileStream") {
        cout << "Working with FileStream mode..." << endl;
        string input_info[MAX_STORAGE];
        int lines = 0;

        add_info("inputFile.txt", input_info);
        lines = request_info("inputFile.txt", input_info, lines);
        swap(input_info, lines);
        output_file("outputFile.txt", input_info, lines);
    } 
    else if (mode == "FilePointer" || mode == "filePointer") {
        cout << "Working with FilePointer mode..." << endl;
        int size_p = 0;
        char info[MAX_STORAGE][MAX_STORAGE];

        size_p = add_info_p("inputFile.txt", info, size_p);
        swap_p(info, size_p);
        out_file_p("outputFile.txt", info, size_p);
    }
    else {
        cout << "You entered wrong mode!" << endl;
    }   
}
