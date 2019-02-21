#include "../src/main/SolarSystem.h"
#include "../src/audio/AudioMaster.h"
#include "../src/audio/AudioSource.h"

int main() {

    SolarSystem solarSystem;

    while(solarSystem.getDisplay()->isRunning()) {
        solarSystem.update();
        solarSystem.render();
    }

}

