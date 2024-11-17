#ifndef BYTE_ARRAY_HPP
#define BYTE_ARRAY_HPP

#include <cstddef>

typedef char byte;

namespace tema1 
{
    class ByteArray
    {
    private:
        std::size_t capacity;
        byte *bytes;

    public:
        // constructor
        ByteArray(std::size_t capacity);

        // copy constructor
        ByteArray(const ByteArray& other);

        // move constructor
        ByteArray(ByteArray&& other) noexcept;

        // destructor
        ~ByteArray();

    public:
        std::size_t getCapacity() const;
        void printElements() const;
        byte getElement(std::size_t i) const;
        void setElement(std::size_t i, byte val);
    };
}

#endif