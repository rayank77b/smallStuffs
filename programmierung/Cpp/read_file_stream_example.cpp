#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ifstream fileread;
    std::ofstream filewrite;
    // Configure the stream to throw on failure and badbit
    fileread.exceptions(std::ifstream::badbit);
    filewrite.exceptions(std::ofstream::badbit);

    try {
        fileread.open("example.txt");
        filewrite.open("example2.txt",std::ios::app);

        std::string line;
        while (std::getline(fileread, line)) {
            std::cout << line << std::endl;
            std::transform(line.begin(), line.end(), line.begin(),
                   [](unsigned char c) { return std::toupper(c); });
            std::transform(line.begin(), line.end(), line.begin(),
                   [](unsigned char c) { return c+=3; });
            filewrite<<line;
        }
        filewrite<<std::endl;

        fileread.close();
        filewrite.close();
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Exception opening/reading file: " << e.what() << std::endl;
        return 1;
    }

    // The file is closed automatically when 'file' goes out of scope
    return 0;
}
