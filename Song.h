#ifndef SONG_H
#define SONG_H

#include <string>


//defines our Song and what information it contains.
struct Song
{
    int id;
    std::string title;
    std::string filePath;
    int playCount;
    bool favorite;

    //default constructor, basically sets everything to default values.
    Song()
    {
        id = 0;
        title = "";
        filePath = "";
        playCount = 0;
        favorite = false;
    }


    //constructor that takes in the song's ID, title, and file path.
    Song(int songID, const std::string& songTitle, const std::string& path)
    {
        id = songID;
        title = songTitle;
        filePath = path;
        playCount = 0;
        favorite = false;
    }
};

#endif