#ifndef GLSOLARSYSTEM_SOLARSYSTEM_H
#define GLSOLARSYSTEM_SOLARSYSTEM_H

#include "../display/Display.h"
#include "../gui/Gui.h"
#include "../model/Loader.h"
#include "../shader/SunShader.h"
#include "../shader/PlanetShader.h"
#include "../shader/RegularShader.h"
#include "../render/Renderer.h"
#include "../entity/planets/Mercury.h"
#include "../entity/planets/Sun.h"
#include "../entity/planets/Venus.h"
#include "../entity/planets/Earth.h"
#include "../entity/planets/Mars.h"
#include "../entity/planets/Jupiter.h"
#include "../entity/planets/Saturn.h"
#include "../entity/planets/Uranus.h"
#include "../entity/planets/Neptune.h"
#include "../entity/Skybox.h"
#include "../entity/planets/SaturnRings.h"
#include "../audio/AudioMaster.h"
#include "../audio/AudioSource.h"

class SolarSystem {

public:
    SolarSystem();
    ~SolarSystem();

    void update();
    void render();

    Display *getDisplay() const;

private:
    std::vector<Entity*> planets;
    std::vector<AudioSource*> sounds;

    Display* display = nullptr;
    Gui* gui = nullptr;

    Loader* loader = nullptr;
    SunShader* sunShader = nullptr;
    PlanetShader* planetShader = nullptr;
    RegularShader* regularShader = nullptr;
    Renderer* renderer = nullptr;


    Light* sunLight = nullptr;
    Sun* sun = nullptr;

    Mercury* mercury = nullptr;
    Venus* venus = nullptr;
    Earth* earth = nullptr;
    Mars* mars = nullptr;
    Jupiter* jupiter = nullptr;
    Saturn* saturn = nullptr;
    SaturnRings* saturnRings = nullptr;
    Uranus* uranus = nullptr;
    Neptune* neptune = nullptr;


    Camera* camera = nullptr;
    Skybox* skybox = nullptr;

    AudioMaster* audioMaster = nullptr;
    AudioSource* sunSound = nullptr;
    AudioSource* mercurySound = nullptr;
    AudioSource* venusSound = nullptr;
    AudioSource* earthSound = nullptr;
    AudioSource* marsSound = nullptr;
    AudioSource* jupiterSound = nullptr;
    AudioSource* saturnSound = nullptr;
    AudioSource* uranusSound = nullptr;
    AudioSource* neptuneSound = nullptr;
    ALuint sunBuffer;
    ALuint mercuryBuffer;
    ALuint venusBuffer;
    ALuint earthBuffer;
    ALuint marsBuffer;
    ALuint jupiterBuffer;
    ALuint saturnBuffer;
    ALuint uranusBuffer;
    ALuint neptuneBuffer;

    void initWindow();
    void initShaders();
    void initRenderer();
    void initEntities();
    void initCameraAndSkybox();
    void initAudio();

    void updateAudio();

    void updatePlanetAroundSunRotation(float time);
    void updatePlanetSelfRotation(float time);

    void updateCameraPosition();

    void renderRegularEntities();
    void renderSun();
    void renderPlanetsAndMoons();
    void updateAndRenderGui();
};


#endif //GLSOLARSYSTEM_SOLARSYSTEM_H
