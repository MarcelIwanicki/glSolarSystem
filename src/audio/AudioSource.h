#ifndef GLSOLARSYSTEM_SOURCE_H
#define GLSOLARSYSTEM_SOURCE_H

#include <AL/al.h>
#include <AL/alc.h>

class AudioSource {
public:
    AudioSource(float x, float y, float z, float maxDistance);
    ~AudioSource();

    void play(ALuint buffer);
    void pause();
    void continuePlaying();
    void stop();

    bool isPlaying();
    void setLooping(bool loop);
    void setVelocity(float x, float y, float z);
    void setVolume(float volume);
    void setPitch(float pitch);
    void setPosition(float x, float y, float z);

private:
    ALuint sourceId;
    ALint state;
};


#endif //GLSOLARSYSTEM_SOURCE_H
