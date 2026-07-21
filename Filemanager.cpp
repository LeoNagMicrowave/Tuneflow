#include "Filemanager.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::string FileManager::loadConfig() const
{
    std::ifstream file("data/config.txt");

    if (!file.is_open())
    {
        return "";
    }

    std::string folderPath;
    std::getline(file, folderPath);

    file.close();

    return folderPath;
}

void FileManager::saveConfig(
    const std::string& folderPath) const
{
    std::ofstream file("data/config.txt");

    if (!file.is_open())
    {
        std::cout << "Failed to save config.\n";
        return;
    }

    file << folderPath;

    file.close();
}

void FileManager::saveSongs(
    const MusicLibrary& library) const
{
    std::ofstream file("data/songs.txt");

    if (!file.is_open())
    {
        std::cout << "Failed to save songs.\n";
        return;
    }

    for (const Song& song : library.getSongs())
    {
        file
            << song.id << "|"
            << song.title << "|"
            << song.filePath << "|"
            << song.playCount << "|"
            << song.favorite
            << "\n";
    }

    file.close();
}

void FileManager::loadSongs(
    MusicLibrary& library) const
{
    std::ifstream file("data/songs.txt");

    if (!file.is_open())
    {
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string id;
        std::string title;
        std::string path;
        std::string playCount;
        std::string favorite;

        std::getline(ss, id, '|');
        std::getline(ss, title, '|');
        std::getline(ss, path, '|');
        std::getline(ss, playCount, '|');
        std::getline(ss, favorite, '|');

        Song song(
            std::stoi(id),
            title,
            path);

        song.playCount =
            std::stoi(playCount);

        song.favorite =
            (favorite == "1");

        library.addSong(song);
    }

    file.close();
}