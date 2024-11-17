#include <iostream>
#include "byte_array.hpp"

int main()
{
    tema1::ByteArray myBytes(5);

    for (int i = 0; i < myBytes.getCapacity(); ++i) {
        myBytes.setElement(i, i + 1);
    }

    std::cout << "Initial array: ";
    myBytes.printElements();
    std::cout << std::endl;

    tema1::ByteArray myCopiedBytes(myBytes);
    std::cout << "Copied array: ";
    myCopiedBytes.printElements();
    std::cout << std::endl;

    std::cout << "Initial array after copying: ";
    myBytes.printElements();
    std::cout << std::endl;

    tema1::ByteArray myMovedBytes = std::move(myBytes); // explicitly call the move constructor
    std::cout << "Moved array: ";
    myMovedBytes.printElements();
    std::cout << std::endl;

    std::cout << "Initial array after moving: ";
    myBytes.printElements();
    std::cout << std::endl;

    return 0;
}