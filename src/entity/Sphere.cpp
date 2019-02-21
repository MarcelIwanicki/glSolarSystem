#include "Sphere.h"
#include "../model/OBJLoader.h"

Sphere::Sphere(Loader *loader, const Texture& texture, const glm::vec3 &position, float rotX, float rotY, float rotZ,
               float scale) : Entity(TexturedModel(OBJLoader::loadObjModel(Res::OBJ_SPHERE, loader), texture), position, rotX, rotY, rotZ, scale) {}


bool Sphere::isCameraColliding(Camera *camera) {
    float dx = camera->getPosition()->x - position.x;
    float dy = camera->getPosition()->y - position.y;
    float dz = camera->getPosition()->z - position.z;

    float d = glm::sqrt(dx*dx + dy*dy + dz*dz);
    float r = scale + 10;

    return (d <= r);
}
