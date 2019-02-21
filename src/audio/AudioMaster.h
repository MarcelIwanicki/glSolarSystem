#ifndef GLSOLARSYSTEM_AUDIOMASTER_H
#define GLSOLARSYSTEM_AUDIOMASTER_H

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <vector>
#include <string>

class AudioMaster {
public:
    AudioMaster();
    ~AudioMaster();

    void setListenerData(float x, float y, float z);
    ALuint loadSound(const std::string& audioPath);

private:
    std::vector<ALuint> buffers;

    ALuint source;
    ALint state;

};


#endif //GLSOLARSYSTEM_AUDIOMASTER_H
