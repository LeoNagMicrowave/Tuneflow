#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>

struct Playlist
{
    std::string name;
    std::vector<std::string> songPaths;

    Playlist()
    {
        name = "";
    }

    Playlist(const std::string& playlistName)
    {
        name = playlistName;
    }
};

#endif