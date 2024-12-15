#ifndef FILE_HANDLE_HPP
#define FILE_HANDLE_HPP

#include <fstream>
#include <stdexcept>

enum FileHandleMode
{
    READ,
    WRITE
};

class FileHandle
{
private:
    std::fstream *filePtr;
    FileHandleMode mode;

public:
    explicit FileHandle(const std::string &path, FileHandleMode mode);
    ~FileHandle();

    FileHandle(const FileHandle&) = delete; // disable copy constructor
    FileHandle& operator=(const FileHandle&) = delete;  // disable copy assignment

    FileHandle(FileHandle&& other) noexcept;
    FileHandle& operator=(FileHandle&& other) noexcept;

    void writeLine(const std::string& text);
    std::string readLine();
};

#endif