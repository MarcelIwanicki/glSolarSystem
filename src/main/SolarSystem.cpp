#include "SolarSystem.h"
#include "../util/Res.h"

SolarSystem::SolarSystem() {
    initWindow();
    initShaders();
    initRenderer();
    initEntities();
    initCameraAndSkybox();
    initAudio();
}

void SolarSystem::initWindow() {
    display = new Display(1280, 720, "glSolarSystem");
    gui = new Gui(display);
}

void SolarSystem::initRenderer() {
    renderer = new Renderer(display, sunShader, planetShader, regularShader);
}

void SolarSystem::initShaders() {
    sunShader = new SunShader;
    planetShader = new PlanetShader;
    regularShader = new RegularShader;
}

void SolarSystem::initEntities() {
    loader = new Loader;

    sun = new Sun(loader);
    sunLight = new Light(glm::vec3(
            sun->getPosition().x,
            sun->getPosition().y,
            sun->getPosition().z),
                         glm::vec3(1.0, 1.0, 1.0));

    mercury = new Mercury(loader); planets.push_back(mercury);
    venus = new Venus(loader); planets.push_back(venus);
    earth = new Earth(loader); planets.push_back(earth);
    mars = new Mars(loader); planets.push_back(mars);
    jupiter = new Jupiter(loader); planets.push_back(jupiter);
    saturn = new Saturn(loader); planets.push_back(saturn);
    saturnRings = new SaturnRings(loader); planets.push_back(saturnRings);
    uranus = new Uranus(loader); planets.push_back(uranus);
    neptune = new Neptune(loader); planets.push_back(neptune);
}

void SolarSystem::initCameraAndSkybox() {
    camera = new Camera;
    skybox = new Skybox(loader, camera);
}

void SolarSystem::initAudio() {
    audioMaster = new AudioMaster;
    audioMaster->setListenerData(camera->getPosition()->x, camera->getPosition()->y, camera->getPosition()->z);

    sunSound = new AudioSource(sun->getPosition().x, sun->getPosition().y, sun->getPosition().z, 1100);
    sounds.push_back(sunSound);
    sunBuffer = audioMaster->loadSound(Res::AUDIO_SUN);
    sunSound->setLooping(true);
    sunSound->play(sunBuffer);

    mercurySound = new AudioSource(mercury->getPosition().x, mercury->getPosition().y, mercury->getPosition().z, 100);
    sounds.push_back(mercurySound);
    mercuryBuffer = audioMaster->loadSound(Res::AUDIO_MERCURY);
    mercurySound->setLooping(true);
    mercurySound->play(mercuryBuffer);

    venusSound = new AudioSource(venus->getPosition().x, venus->getPosition().y, venus->getPosition().z, 100);
    sounds.push_back(venusSound);
    venusBuffer = audioMaster->loadSound(Res::AUDIO_VENUS);
    venusSound->setLooping(true);
    venusSound->play(venusBuffer);

    earthSound = new AudioSource(earth->getPosition().x, earth->getPosition().y, earth->getPosition().z, 200);
    sounds.push_back(earthSound);
    earthBuffer = audioMaster->loadSound(Res::AUDIO_EARTH);
    earthSound->setLooping(true);
    earthSound->play(earthBuffer);

    marsSound = new AudioSource(mars->getPosition().x, mars->getPosition().y, mars->getPosition().z, 150);
    sounds.push_back(marsSound);
    marsBuffer = audioMaster->loadSound(Res::AUDIO_MARS);
    marsSound->setLooping(true);
    marsSound->play(marsBuffer);

    jupiterSound = new AudioSource(jupiter->getPosition().x, jupiter->getPosition().y, jupiter->getPosition().z, 400);
    sounds.push_back(jupiterSound);
    jupiterBuffer = audioMaster->loadSound(Res::AUDIO_JUPITER);
    jupiterSound->setLooping(true);
    jupiterSound->play(jupiterBuffer);

    saturnSound = new AudioSource(saturn->getPosition().x, saturn->getPosition().y, saturn->getPosition().z, 350);
    sounds.push_back(saturnSound);
    saturnBuffer = audioMaster->loadSound(Res::AUDIO_SATURN);
    saturnSound->setLooping(true);
    saturnSound->play(saturnBuffer);

    uranusSound = new AudioSource(uranus->getPosition().x, uranus->getPosition().y, uranus->getPosition().z, 250);
    sounds.push_back(uranusSound);
    uranusBuffer = audioMaster->loadSound(Res::AUDIO_URANUS);
    uranusSound->setLooping(true);
    uranusSound->play(uranusBuffer);

    neptuneSound = new AudioSource(neptune->getPosition().x, neptune->getPosition().y, neptune->getPosition().z, 250);
    sounds.push_back(neptuneSound);
    neptuneBuffer = audioMaster->loadSound(Res::AUDIO_NEPTUNE);
    neptuneSound->setLooping(true);
    neptuneSound->play(neptuneBuffer);
}

SolarSystem::~SolarSystem() {
    delete display;
    delete gui;
    delete loader;
    delete sunShader;
    delete planetShader;
    delete regularShader;
    delete renderer;
    delete sun;
    delete sunLight;

    for(auto p : planets)
        delete p;

    delete camera;
    delete skybox;

    delete audioMaster;
    for(auto s : sounds)
        delete s;
}

void SolarSystem::update() {
    updateAudio();

    sunLight->setColor(glm::vec3(
            gui->getColors()[0] * gui->getLightIntensityScale(),
            gui->getColors()[1] * gui->getLightIntensityScale(),
            gui->getColors()[2] * gui->getLightIntensityScale()));
    gui->initFrame();
    skybox->update();

    updatePlanetAroundSunRotation(glfwGetTime() * gui->getTimeScale());
    updatePlanetSelfRotation(gui->getTimeScale());
    updateCameraPosition();
}

void SolarSystem::updateAudio() {
    audioMaster->setListenerData(camera->getPosition()->x, camera->getPosition()->y, camera->getPosition()->z);

    mercurySound->setPosition(mercury->getPosition().x, mercury->getPosition().y, mercury->getPosition().z);
    venusSound->setPosition(venus->getPosition().x, venus->getPosition().y, venus->getPosition().z);
    earthSound->setPosition(earth->getPosition().x, earth->getPosition().y, earth->getPosition().z);
    marsSound->setPosition(mars->getPosition().x, mars->getPosition().y, mars->getPosition().z);
    jupiterSound->setPosition(jupiter->getPosition().x, jupiter->getPosition().y, jupiter->getPosition().z);
    saturnSound->setPosition(saturn->getPosition().x, saturn->getPosition().y, saturn->getPosition().z);
    uranusSound->setPosition(uranus->getPosition().x, uranus->getPosition().y, uranus->getPosition().z);
    neptuneSound->setPosition(neptune->getPosition().x, neptune->getPosition().y, neptune->getPosition().z);

    for(auto s : sounds)
        s->setVolume(gui->getVolumeScale());
}

void SolarSystem::updatePlanetAroundSunRotation(float time) {
    mercury->rotateAroundSun(time, Constants::ORBITAL_SPEED_MERCURY, Constants::D_FROM_SUN_MERCURY);
    venus->rotateAroundSun(time, Constants::ORBITAL_SPEED_VENUS, Constants::D_FROM_SUN_VENUS);
    earth->rotateAroundSun(time, Constants::ORBITAL_SPEED_EARTH, Constants::D_FROM_SUN_EARTH);
    mars->rotateAroundSun(time, Constants::ORBITAL_SPEED_MARS, Constants::D_FROM_SUN_MARS);
    jupiter->rotateAroundSun(time, Constants::ORBITAL_SPEED_JUPITER, Constants::D_FROM_SUN_JUPITER);
    saturn->rotateAroundSun(time, Constants::ORBITAL_SPEED_SATURN, Constants::D_FROM_SUN_SATURN);
    saturnRings->update(saturn);
    uranus->rotateAroundSun(time, Constants::ORBITAL_SPEED_URANUS, Constants::D_FROM_SUN_URANUS);
    neptune->rotateAroundSun(time, Constants::ORBITAL_SPEED_NEPTUNE, Constants::D_FROM_SUN_NEPTUNE);
}

void SolarSystem::updatePlanetSelfRotation(float time) {
    sun->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_SUN * time);
    mercury->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_MERCURY * time);
    venus->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_VENUS * time);
    earth->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_EARTH * time);
    mars->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_MARS * time);
    jupiter->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_JUPITER * time);
    saturn->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_SATURN * time);
    saturnRings->increateRotation(0.0f, (Constants::ANGULAR_SPEED_SATURN / 4.0f) * time, 0.0f);
    uranus->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_URANUS * time);
    neptune->increateRotation(0.0f, 0.0f, Constants::ANGULAR_SPEED_NEPTUNE * time);
}

void SolarSystem::updateCameraPosition() {

    //UPDATE COLLISION WITH SUN
    if(sun->isCameraColliding(camera)) {

        float dx = Camera::SUPER_VELOCITY * glm::sin(camera->getYaw());
        float dy = Camera::SUPER_VELOCITY * camera->getPitch();
        float dz = Camera::SUPER_VELOCITY * glm::cos(camera->getYaw());

        camera->setPosition(
                glm::vec3(camera->getPosition()->x - dx, camera->getPosition()->y + dy, camera->getPosition()->z + dz));
    }

    camera->update();

    //UPDATE CAMERA POSITION DEPENDENT ON GUI
    switch (gui->getFocusState()) {
        case FocusState::SUN:
            camera->setTarget(sun->getPosition().x, sun->getPosition().y, sun->getPosition().z + 1000);
            break;
        case FocusState::MERCURY:
            camera->setTarget(mercury->getPosition().x, mercury->getPosition().y, mercury->getPosition().z + 10);
            break;
        case FocusState::VENUS:
            camera->setTarget(venus->getPosition().x, venus->getPosition().y, venus->getPosition().z + 10);
            break;
        case FocusState::EARTH:
            camera->setTarget(earth->getPosition().x, earth->getPosition().y, earth->getPosition().z + 10);
            break;
        case FocusState::MARS:
            camera->setTarget(mars->getPosition().x, mars->getPosition().y, mars->getPosition().z + 10);
            break;
        case FocusState::JUPITER:
            camera->setTarget(jupiter->getPosition().x, jupiter->getPosition().y, jupiter->getPosition().z + 100);
            break;
        case FocusState::SATURN:
            camera->setTarget(saturn->getPosition().x, saturn->getPosition().y, saturn->getPosition().z + 200);
            break;
        case FocusState::URANUS:
            camera->setTarget(uranus->getPosition().x, uranus->getPosition().y, uranus->getPosition().z + 100);
            break;
        case FocusState::NEPTUNE:
            camera->setTarget(neptune->getPosition().x, neptune->getPosition().y, neptune->getPosition().z + 100);
            break;
    }
}

void SolarSystem::render() {
    display->clear(0, 0, 0, 1.0);

    renderRegularEntities();
    renderSun();
    renderPlanetsAndMoons();
    updateAndRenderGui();

    display->update();
}

void SolarSystem::renderRegularEntities() {
    regularShader->enable();
    regularShader->loadViewMatrix(camera);
    renderer->render(skybox);
    regularShader->disable();
}

void SolarSystem::renderSun() {
    sunShader->enable();
    sunShader->loadViewMatrix(camera);
    renderer->render(sun);
    sunShader->disable();
}

void SolarSystem::renderPlanetsAndMoons() {
    planetShader->enable();
    planetShader->loadLight(sunLight);
    planetShader->loadViewMatrix(camera);

    for(auto p : planets)
        renderer->render(p);

    planetShader->disable();
}

void SolarSystem::updateAndRenderGui() {
    gui->update();
    gui->render();
}

Display *SolarSystem::getDisplay() const {
    return display;
}
