#ifndef MENU_H
#define MENU_H

#include "MusicLibrary.h"
#include "PlaylistManager.h"
#include "AudioPlayer.h"
#include "FileManager.h"

class Menu
{
private:
    MusicLibrary library;
    PlaylistManager playlistManager;
    AudioPlayer player;
    FileManager fileManager;

    bool running;

    // Menu Screens
    void displayMainMenu() const;
    void libraryMenu();
    void playlistMenu();
    void playerMenu();

public:
    Menu();

    void initialize();
    void run();
};

#endif // MENU_H