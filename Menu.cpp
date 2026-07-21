#include "Menu.h"

#include <iostream>

Menu::Menu()
{
    running = true;
}

void Menu::initialize()
{
    // Load saved folder path
    std::string folder =
        fileManager.loadConfig();

    if (!folder.empty())
    {
        fileManager.loadSongs(library);
        library.scanMusicFolder(folder);
    }
}

void Menu::displayMainMenu() const
{
    std::cout << "\n=========================\n";
    std::cout << "         TUNEFLOW\n";
    std::cout << "=========================\n";

    std::cout << "1. Music Library\n";
    std::cout << "2. Playlists\n";
    std::cout << "3. Audio Player\n";
    std::cout << "4. Save Data\n";
    std::cout << "5. Exit\n";

    std::cout << "\nChoice: ";
}

void Menu::run()
{
    initialize();

    while (running)
    {
        int choice;

        displayMainMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            libraryMenu();
            break;

        case 2:
            playlistMenu();
            break;

        case 3:
            playerMenu();
            break;

        case 4:
            fileManager.saveSongs(library);

            std::cout
                << "\nSaved successfully.\n";

            break;

        case 5:
            fileManager.saveSongs(library);

            running = false;

            break;

        default:
            std::cout
                << "\nInvalid choice.\n";
        }
    }
}

void Menu::libraryMenu()
{
    int choice;

    std::cout
        << "\n===== MUSIC LIBRARY =====\n";

    std::cout
        << "1. Display Library\n";

    std::cout
        << "2. Search Song\n";

    std::cout
        << "3. Back\n";

    std::cout
        << "\nChoice: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:

        library.displayLibrary();

        break;

    case 2:
    {
        std::string title;

        std::cout
            << "Enter title: ";

        std::cin.ignore();

        std::getline(
            std::cin,
            title);

        library.searchSong(title);

        break;
    }

    default:
        break;
    }
}

void Menu::playlistMenu()
{
    int choice;

    std::cout
        << "\n===== PLAYLISTS =====\n";

    std::cout
        << "1. Display Playlists\n";

    std::cout
        << "2. Create Playlist\n";

    std::cout
        << "3. Back\n";

    std::cout
        << "\nChoice: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:

        playlistManager.displayPlaylists();

        break;

    case 2:
    {
        std::string name;

        std::cout
            << "Playlist Name: ";

        std::cin.ignore();

        std::getline(
            std::cin,
            name);

        playlistManager.createPlaylist(
            name);

        break;
    }

    default:
        break;
    }
}

void Menu::playerMenu()
{
    int choice;

    std::cout
        << "\n===== AUDIO PLAYER =====\n";

    std::cout
        << "1. Play Song\n";

    std::cout
        << "2. Pause\n";

    std::cout
        << "3. Resume\n";

    std::cout
        << "4. Stop\n";

    std::cout
        << "5. Back\n";

    std::cout
        << "\nChoice: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::string path;

        std::cout
            << "Enter file path:\n";

        std::cin.ignore();

        std::getline(
            std::cin,
            path);

        player.play(path);

        break;
    }

    case 2:

        player.pause();

        break;

    case 3:

        player.resume();

        break;

    case 4:

        player.stop();

        break;

    default:
        break;
    }
}