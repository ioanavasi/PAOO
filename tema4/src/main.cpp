#include "FileHandle.hpp"
#include <iostream>

int main()
{
    try {
        // Create an object to manage a file for writing
        FileHandle file("myFile.txt", WRITE);
        file.writeLine("Hello, World!");

        // Move the FileHandle to another object
        FileHandle otherFile = std::move(file);

        // Try to write to the original FileHandle object (will fail)
        try {
            file.writeLine("This will not be written!");
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }    

    // Use a different scope to ensure the previous objects get deleted
    try {
        // Create an object to read from the previously created file
        FileHandle file("myFile.txt", READ);
        std::cout << "Read from file: " << file.readLine() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }    

    return 0;
}