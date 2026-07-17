#include "MusicLibrary.h"

#include <iostream>
#include <algorithm>
#include <filesystem>

namespace fs = std::filesystem;

//==================================================
// Constructor
//==================================================

MusicLibrary::MusicLibrary()
{
}

//==================================================
// Add Song
//==================================================

void MusicLibrary::addSong(const Song& song)
{
    musicLibrary.push_back(song);
}

//==================================================
// Remove Song
//==================================================

void MusicLibrary::removeSong(const std::string& filePath)
{
    musicLibrary.erase(
        std::remove_if(
            musicLibrary.begin(),
            musicLibrary.end(),
            [&](const Song& song)
            {
                return song.filePath == filePath;
            }),
        musicLibrary.end());
}

//==================================================
// Display Library
//==================================================

void MusicLibrary::displayLibrary() const
{
    if (musicLibrary.empty())
    {
        std::cout << "\nLibrary is empty.\n";
        return;
    }

    std::cout << "\n===== MUSIC LIBRARY =====\n";

    for (const Song& song : musicLibrary)
    {
        std::cout
            << "[" << song.id << "] "
            << song.title;

        if (song.favorite)
        {
            std::cout << " (Favorite)";
        }

        std::cout << "\n";
    }
}

//==================================================
// Search Song
//==================================================

void MusicLibrary::searchSong(const std::string& title) const
{
    bool found = false;

    for (const Song& song : musicLibrary)
    {
        if (song.title == title)
        {
            std::cout
                << "\nFound: "
                << song.title
                << "\nPath: "
                << song.filePath
                << "\n";

            found = true;
        }
    }

    if (!found)
    {
        std::cout << "\nSong not found.\n";
    }
}

//==================================================
// Favorite Song
//==================================================

void MusicLibrary::markFavorite(
    const std::string& filePath)
{
    for (Song& song : musicLibrary)
    {
        if (song.filePath == filePath)
        {
            song.favorite = !song.favorite;
            return;
        }
    }
}

//==================================================
// Increment Play Count
//==================================================

void MusicLibrary::incrementPlayCount(
    const std::string& filePath)
{
    for (Song& song : musicLibrary)
    {
        if (song.filePath == filePath)
        {
            song.playCount++;
            return;
        }
    }
}

//==================================================
// Scan Music Folder
//==================================================

void MusicLibrary::scanMusicFolder(
    const std::string& folderPath)
{
    int currentID = 1;

    for (const auto& entry :
         fs::directory_iterator(folderPath))
    {
        if (entry.is_regular_file())
        {
            std::string extension =
                entry.path().extension().string();

            if (extension == ".mp3" ||
                extension == ".wav" ||
                extension == ".flac" ||
                extension == ".ogg")
            {
                std::string path =
                    entry.path().string();

                std::string title =
                    entry.path().stem().string();

                bool exists = false;

                for (const Song& song : musicLibrary)
                {
                    if (song.filePath == path)
                    {
                        exists = true;
                        break;
                    }
                }

                if (!exists)
                {
                    Song newSong(
                        currentID++,
                        title,
                        path);

                    musicLibrary.push_back(newSong);
                }
            }
        }
    }
}

//==================================================
// Getters
//==================================================

std::vector<Song>& MusicLibrary::getSongs()
{
    return musicLibrary;
}

const std::vector<Song>&
MusicLibrary::getSongs() const
{
    return musicLibrary;
}