#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

#include "MusicLibrary.h"

class FileManager
{
public:
    // Config
    std::string loadConfig() const;
    void saveConfig(const std::string& folderPath) const;

    // Songs
    void loadSongs(MusicLibrary& library) const;
    void saveSongs(const MusicLibrary& library) const;
};

#endif // FILEMANAGER_H