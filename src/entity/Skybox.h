#ifndef GLSOLARSYSTEM_SKYBOX_H
#define GLSOLARSYSTEM_SKYBOX_H

#include "Entity.h"
#include "Camera.h"
#include "../model/Loader.h"
#include "../model/TexturedModel.h"

class Skybox : public Entity{
public:
    Skybox(Loader* loader, Camera* camera);
    void update();

private:
    Camera* camera;

};


#endif //GLSOLARSYSTEM_SKYBOX_H
