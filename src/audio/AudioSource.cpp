#include <alut.h>
#include "AudioSource.h"

AudioSource::AudioSource(float x, float y, float z, float maxDistance) {
    alGenSources(1, &sourceId);
    alSourcef(sourceId, AL_GAIN, 1);
    alSourcef(sourceId, AL_PITCH, 1);
    alSource3f(sourceId, AL_POSITION, x, y, z);

    alSourcef(sourceId, AL_ROLLOFF_FACTOR, 1);
    alSourcef(sourceId, AL_REFERENCE_DISTANCE, 6);
    alSourcef(sourceId, AL_MAX_DISTANCE, maxDistance);
}

AudioSource::~AudioSource() {
    stop();
    alDeleteSources(1, &sourceId);

    alutExit();
}

void AudioSource::play(ALuint buffer) {
    stop();

    alSourcei(sourceId, AL_BUFFER, buffer);
    alSourcePlay(sourceId);
}

void AudioSource::pause() {
    alSourcePause(sourceId);
}

void AudioSource::continuePlaying() {
    alSourcePlay(sourceId);
}

void AudioSource::stop() {
    alSourceStop(sourceId);
}

bool AudioSource::isPlaying() {
    return (state == AL_PLAYING);
}

void AudioSource::setLooping(bool loop) {
    alSourcei(sourceId, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
}

void AudioSource::setVelocity(float x, float y, float z) {
    alSource3f(sourceId, AL_VELOCITY, x, y, z);
}

void AudioSource::setVolume(float volume) {
    alSourcef(sourceId, AL_GAIN, volume);
}

void AudioSource::setPitch(float pitch) {
    alSourcef(sourceId, AL_PITCH, pitch);
}

void AudioSource::setPosition(float x, float y, float z) {
    alSource3f(sourceId, AL_POSITION, x, y, z);
}
