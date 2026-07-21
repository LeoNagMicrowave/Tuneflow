#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <string>
#include <queue>
#include <thread>
#include <atomic>

#include "miniaudio.h"

class AudioPlayer
{
private:
    ma_engine engine;

    std::queue<std::string> playQueue;

    std::thread playbackThread;

    std::atomic<bool> isPlaying;
    std::atomic<bool> isPaused;
    std::atomic<bool> stopRequested;

    ma_sound currentSound;

public:
    AudioPlayer();
    ~AudioPlayer();

    // Playback
    void play(const std::string& filePath);
    void pause();
    void resume();
    void stop();

    // Queue
    void addToQueue(const std::string& filePath);
    void playNext();

    // Status
    bool getIsPlaying() const;
    bool getIsPaused() const;
};

#endif