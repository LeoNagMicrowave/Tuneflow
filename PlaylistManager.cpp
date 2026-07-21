#include "PlaylistManager.h"

#include <iostream>
#include <algorithm>
#include <random>

//==================================================
// Constructor
//==================================================

PlaylistManager::PlaylistManager()
{
}

//==================================================
// Create Playlist
//==================================================

void PlaylistManager::createPlaylist(
    const std::string& name)
{
    for (const Playlist& playlist : playlists)
    {
        if (playlist.name == name)
        {
            std::cout
                << "Playlist already exists.\n";

            return;
        }
    }

    playlists.push_back(Playlist(name));

    std::cout
        << "Playlist created successfully.\n";
}

//==================================================
// Delete Playlist
//==================================================

void PlaylistManager::deletePlaylist(
    const std::string& name)
{
    playlists.erase(
        std::remove_if(
            playlists.begin(),
            playlists.end(),
            [&](const Playlist& playlist)
            {
                return playlist.name == name;
            }),
        playlists.end());
}

//==================================================
// Rename Playlist
//==================================================

void PlaylistManager::renamePlaylist(
    const std::string& oldName,
    const std::string& newName)
{
    for (Playlist& playlist : playlists)
    {
        if (playlist.name == oldName)
        {
            playlist.name = newName;
            return;
        }
    }
}

//==================================================
// Add Song
//==================================================

void PlaylistManager::addSongToPlaylist(
    const std::string& playlistName,
    const std::string& filePath)
{
    for (Playlist& playlist : playlists)
    {
        if (playlist.name == playlistName)
        {
            playlist.songPaths.push_back(
                filePath);

            return;
        }
    }
}

//==================================================
// Remove Song
//==================================================

void PlaylistManager::removeSongFromPlaylist(
    const std::string& playlistName,
    const std::string& filePath)
{
    for (Playlist& playlist : playlists)
    {
        if (playlist.name == playlistName)
        {
            playlist.songPaths.erase(
                std::remove(
                    playlist.songPaths.begin(),
                    playlist.songPaths.end(),
                    filePath),
                playlist.songPaths.end());

            return;
        }
    }
}

//==================================================
// Display All Playlists
//==================================================

void PlaylistManager::displayPlaylists() const
{
    if (playlists.empty())
    {
        std::cout
            << "\nNo playlists available.\n";

        return;
    }

    std::cout
        << "\n===== PLAYLISTS =====\n";

    for (const Playlist& playlist :
         playlists)
    {
        std::cout
            << "- "
            << playlist.name
            << " ("
            << playlist.songPaths.size()
            << " songs)\n";
    }
}

//==================================================
// Display One Playlist
//==================================================

void PlaylistManager::displayPlaylist(
    const std::string& playlistName) const
{
    for (const Playlist& playlist :
         playlists)
    {
        if (playlist.name == playlistName)
        {
            std::cout
                << "\nPlaylist: "
                << playlist.name
                << "\n";

            if (playlist.songPaths.empty())
            {
                std::cout
                    << "Playlist is empty.\n";

                return;
            }

            for (const std::string& path :
                 playlist.songPaths)
            {
                std::cout
                    << path
                    << "\n";
            }

            return;
        }
    }

    std::cout
        << "Playlist not found.\n";
}

//==================================================
// Shuffle Playlist
//==================================================

void PlaylistManager::shufflePlaylist(
    const std::string& playlistName)
{
    std::random_device rd;
    std::mt19937 generator(rd());

    for (Playlist& playlist : playlists)
    {
        if (playlist.name == playlistName)
        {
            std::shuffle(
                playlist.songPaths.begin(),
                playlist.songPaths.end(),
                generator);

            return;
        }
    }
}

//==================================================
// Getters
//==================================================

std::vector<Playlist>&
PlaylistManager::getPlaylists()
{
    return playlists;
}

const std::vector<Playlist>&
PlaylistManager::getPlaylists() const
{
    return playlists;
}