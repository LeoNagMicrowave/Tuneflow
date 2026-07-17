#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <vector>
#include <string>

#include "Song.h"

class MusicLibrary
{
private:
    std::vector<Song> musicLibrary;

public:
    // Constructor
    MusicLibrary();

    // Library Management
    void addSong(const Song& song);
    void removeSong(const std::string& filePath);

    // Display Functions
    void displayLibrary() const;
    void searchSong(const std::string& title) const;

    // Song Management
    void markFavorite(const std::string& filePath);
    void incrementPlayCount(const std::string& filePath);

    // Folder Scanning
    void scanMusicFolder(const std::string& folderPath);

    // Getters
    std::vector<Song>& getSongs();
    const std::vector<Song>& getSongs() const;
};

#endif // MUSICLIBRARY_H