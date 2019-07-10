#pragma once

#include <iostream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
using DirectoryEntry = fs::directory_entry;
using std::string;

class File
{
    private:
        DirectoryEntry directoryEntry;

    public:
        File(DirectoryEntry);

        DirectoryEntry getDirectoryEntry();

        string getName();
        string getAbsolutePath();

        string getExtension();
        bool isExtension(string);

        bool isDirectory();
};
