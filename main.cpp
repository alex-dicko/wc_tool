#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int main (int argc, char *argv[]) {

    if (argc != 3) {
        std::cerr << "The correct syntax is: ./wc_tool <flag> <file>" << std::endl;
        return 1;
    }

    if (strcmp( argv[1], "-c") == 0) {
        std::ifstream file(argv[2], std::ios::binary);

        if (!file) {
            std::cerr << "Unable to open file: " << argv[2] << std::endl;
            return 1;
        }

        file.seekg(0, std::ios::end); // Move 0 bytes from the end of the file
        auto file_size = file.tellg();

        std::cout << "File Size (in bytes): " << file_size << std::endl;

        return 0;
    }
    else if (strcmp( argv[1], "-l") == 0)
    {
        std::ifstream file(argv[2]);

        if (!file) {
            std::cerr << "Unable to open file: " << argv[2] << std::endl;
            return 1;
        }

        std::string line;
        int counter = 0;
        while (getline(file, line)) {
            counter++;
        }

        std::cout << "Number of lines: " << counter << std::endl;
    } else if ( strcmp( argv[1], "-w" ) == 0) {
        std::ifstream file(argv[2]);

        if (!file) {
            std::cerr << "Unable to open file: " << argv[2] << std::endl;
        }

        int counter = 0;
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
            while (ss >> word) {
                counter++;
            }
        }

        std::cout << "Number of words: " << counter << std::endl;
    }
}


