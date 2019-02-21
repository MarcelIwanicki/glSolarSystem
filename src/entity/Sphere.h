#ifndef GLSOLARSYSTEM_SPHERE_H
#define GLSOLARSYSTEM_SPHERE_H

#include "Entity.h"
#include "../model/Loader.h"
#include "../util/Res.h"

class Sphere : public Entity{

public:
    Sphere(Loader* loader, const Texture& texture, const glm::vec3 &position, float rotX, float rotY, float rotZ, float scale);

    bool isCameraColliding(Camera* camera);
};


#endif //GLSOLARSYSTEM_SPHERE_H
