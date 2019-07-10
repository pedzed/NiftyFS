#include "File.h"

File::File(DirectoryEntry directoryEntry)
    : directoryEntry(directoryEntry)
{
    //
}

DirectoryEntry File::getDirectoryEntry()
{
    return directoryEntry;
}

string File::getName()
{
    return directoryEntry.path().filename().string();
}

string File::getAbsolutePath()
{
    return directoryEntry.path().string();
}

string File::getExtension()
{
    return fs::extension(directoryEntry);
}

bool File::isExtension(string extension)
{
    return (getExtension() == extension);
}

bool File::isDirectory()
{
    return (fs::is_directory(directoryEntry));
}
