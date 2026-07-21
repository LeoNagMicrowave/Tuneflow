#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include "AudioPlayer.h"

#include <iostream>
#include <chrono>

AudioPlayer::AudioPlayer()
{
    isPlaying = false;
    isPaused = false;
    stopRequested = false;

    if (ma_engine_init(NULL, &engine) != MA_SUCCESS)
    {
        std::cout
            << "Failed to initialize audio engine.\n";
    }
}

AudioPlayer::~AudioPlayer()
{
    stop();

    if (playbackThread.joinable())
    {
        playbackThread.join();
    }

    ma_engine_uninit(&engine);
}




void AudioPlayer::play(
    const std::string& filePath)
{
    stop();

    stopRequested = false;

    playbackThread =
        std::thread(
            [this, filePath]()
            {
                if (ma_sound_init_from_file(
                        &engine,
                        filePath.c_str(),
                        0,
                        NULL,
                        NULL,
                        &currentSound)
                    != MA_SUCCESS)
                {
                    std::cout
                        << "Failed to load song.\n";

                    return;
                }

                ma_sound_start(&currentSound);

                isPlaying = true;

                while (ma_sound_is_playing(
                           &currentSound) &&
                       !stopRequested)
                {
                    std::this_thread::sleep_for(
                        std::chrono::milliseconds(100));
                }

                ma_sound_uninit(
                    &currentSound);

                isPlaying = false;
            });
}




void AudioPlayer::pause()
{
    if (isPlaying)
    {
        ma_sound_stop(&currentSound);

        isPaused = true;
        isPlaying = false;
    }
}




void AudioPlayer::resume()
{
    if (isPaused)
    {
        ma_sound_start(&currentSound);

        isPaused = false;
        isPlaying = true;
    }
}




void AudioPlayer::stop()
{
    stopRequested = true;

    if (isPlaying)
    {
        ma_sound_stop(&currentSound);
    }

    if (playbackThread.joinable())
    {
        playbackThread.join();
    }

    isPlaying = false;
    isPaused = false;
}




void AudioPlayer::addToQueue(
    const std::string& filePath)
{
    playQueue.push(filePath);
}



void AudioPlayer::playNext()
{
    if (playQueue.empty())
    {
        return;
    }

    std::string nextSong =
        playQueue.front();

    playQueue.pop();

    play(nextSong);
}



bool AudioPlayer::getIsPlaying() const
{
    return isPlaying;
}

bool AudioPlayer::getIsPaused() const
{
    return isPaused;
}

