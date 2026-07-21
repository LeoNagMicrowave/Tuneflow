# TuneFlow

TuneFlow is a terminal-based music playlist and library management system written in C++.

## Features

- Automatic music folder scanning
- Local audio playback using miniaudio
- Playlist management
- Favorites system
- Song search
- Play count tracking
- Multithreaded audio playback
- File persistence

## Technologies

- C++17
- Miniaudio
- std::filesystem
- std::thread
- STL (vector, queue)

## Building

```bash
g++ -std=c++17 *.cpp -o TuneFlow.exe
