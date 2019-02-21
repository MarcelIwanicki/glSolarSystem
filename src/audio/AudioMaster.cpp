#include <iostream>
#include "AudioMaster.h"

AudioMaster::AudioMaster(){
    alutInit(0, nullptr);
    alGetError();
}

AudioMaster::~AudioMaster() {
    alDeleteSources(1, &source);

    for(auto b : buffers)
        alDeleteBuffers(1, &b);

}

void AudioMaster::setListenerData(float x, float y, float z) {
    alListener3f(AL_POSITION, x, y, z);
    alListener3f(AL_VELOCITY, 0, 0, 0);

    alDistanceModel(AL_LINEAR_DISTANCE_CLAMPED);
}

ALuint AudioMaster::loadSound(const std::string& audioPath) {
    ALuint buffer = alutCreateBufferFromFile(audioPath.c_str());
    buffers.push_back(buffer);
    return buffer;
}