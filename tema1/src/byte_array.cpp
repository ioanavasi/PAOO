#include "byte_array.hpp"
#include <stdexcept>
#include <iostream>

namespace tema1
{
    
    ByteArray::ByteArray(std::size_t capacity) 
        : 
        capacity(capacity),
        bytes(new byte[capacity])
    {
        std::cout << "Regular constructor called\n";
        for (size_t i = 0; i < capacity; ++i) {
            bytes[i] = 0;
        }
    }

    ByteArray::ByteArray(const ByteArray& other)
        : 
        capacity(other.capacity), 
        bytes(new byte[other.capacity])
    {
        std::cout << "Copy constructor called\n";
        std::copy(other.bytes, other.bytes + other.capacity, bytes);
    }

    ByteArray::ByteArray(ByteArray&& other) noexcept
        : 
        capacity(other.capacity), 
        bytes(other.bytes)
    {
        std::cout << "Move constructor called\n";
        other.capacity = 0;
        other.bytes = nullptr;
    }

    ByteArray::~ByteArray()
    {
        std::cout << "Destructor called\n";
        delete[] bytes;
    }

    std::size_t ByteArray::getCapacity() const
    {
        return capacity;
    }

    void ByteArray::printElements() const
    {
        if (capacity == 0) {
            std::cout << "(empty)\n";
        }
        for (size_t i = 0; i < capacity; ++i) {
            std::cout << std::dec << "0x" << std::hex << (unsigned int) bytes[i] << std::dec << " ";
        }
    }

    byte ByteArray::getElement(std::size_t i) const
    {
        if (i < capacity) {
            return bytes[i];
        } else {
            throw std::runtime_error("Index is out of bounds");
        }
    }

    void ByteArray::setElement(std::size_t i, byte val)
    {
        if (i < capacity) {
            bytes[i] = val;
        } else {
            throw std::runtime_error("Index is out of bounds");
        }
    }
}