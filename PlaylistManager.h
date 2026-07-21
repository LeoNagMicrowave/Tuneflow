#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <vector>
#include <string>

#include "Playlist.h"

class PlaylistManager
{
private:
    std::vector<Playlist> playlists;

public:
    // Constructors
    PlaylistManager();

    // Playlist Management
    void createPlaylist(const std::string& name);
    void deletePlaylist(const std::string& name);
    void renamePlaylist(
        const std::string& oldName,
        const std::string& newName);

    // Song Management
    void addSongToPlaylist(
        const std::string& playlistName,
        const std::string& filePath);

    void removeSongFromPlaylist(
        const std::string& playlistName,
        const std::string& filePath);

    // Display
    void displayPlaylists() const;
    void displayPlaylist(
        const std::string& playlistName) const;

    // Utility
    void shufflePlaylist(
        const std::string& playlistName);

    // Getters
    std::vector<Playlist>& getPlaylists();
    const std::vector<Playlist>& getPlaylists() const;
};

#endif // PLAYLISTMANAGER_H