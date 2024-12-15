#include "FileHandle.hpp"

#include <iostream>

FileHandle::FileHandle(const std::string &path, FileHandleMode mode)
    : 
    filePtr(new std::fstream(path, mode == WRITE ? std::ios::out : std::ios::in)),
    mode(mode)
{
    std::cout << "INFO: constructor called" << std::endl;
    if (!filePtr->is_open()) {
        delete filePtr;
        filePtr = nullptr;
        throw std::runtime_error("Error opening file: " + path);
    }
}

FileHandle::~FileHandle()
{
    std::cout << "INFO: destructor called" << std::endl;
    if (filePtr) {
        filePtr->close();
        delete filePtr;
    }
}

FileHandle::FileHandle(FileHandle&& other) noexcept
    : 
    filePtr(other.filePtr), 
    mode(other.mode)
{
    std::cout << "INFO: move constructor called" << std::endl;
    other.filePtr = nullptr;
}

FileHandle& FileHandle::operator=(FileHandle&& other) noexcept
{
    std::cout << "INFO: move assignment operator called" << std::endl;
    if (this != &other) {
        if (filePtr) {
            filePtr->close();
            delete filePtr;
        }
        filePtr = other.filePtr;
        mode = other.mode;
        other.filePtr = nullptr;
    }
    return *this;
}

void FileHandle::writeLine(const std::string& text)
{
    if (!filePtr || !filePtr->is_open() || mode != WRITE) {
        throw std::runtime_error("File is not open for writing");
    }
    *filePtr << text << std::endl;
}

std::string FileHandle::readLine()
{
    if (!filePtr || !filePtr->is_open() || mode != READ) {
        throw std::runtime_error("File is not open for reading");
    }
    std::string line;
    std::getline(*filePtr, line);
    return line;
}