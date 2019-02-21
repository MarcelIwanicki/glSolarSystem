#include "Entity.h"
#include "../util/Constants.h"

Entity::Entity(const TexturedModel& texturedModel, const glm::vec3 &position, float rotX, float rotY, float rotZ, float scale)
        : texturedModel(texturedModel), position(position), rotX(rotX), rotY(rotY), rotZ(rotZ), scale(scale) {}

void Entity::increatePosition(float dx, float dy, float dz) {
    this->position.x += dx;
    this->position.y += dy;
    this->position.z += dz;
}

void Entity::increateRotation(float dx, float dy, float dz) {
    this->rotX += dx;
    this->rotY += dy;
    this->rotZ += dz;
}

void Entity::rotateAroundSun(float time, float orbitSpeed, float radius) {
    orbitalAngle += orbitSpeed * time;
    setPosition(glm::vec3(Constants::ORIGIN_X + radius * glm::cos(orbitalAngle), 0, Constants::ORIGIN_Z + radius * glm::sin(orbitalAngle)));
}

TexturedModel Entity::getTexturedModel() const {
    return texturedModel;
}

const glm::vec3 &Entity::getPosition() const {
    return position;
}

float Entity::getRotX() const {
    return rotX;
}

float Entity::getRotY() const {
    return rotY;
}

float Entity::getRotZ() const {
    return rotZ;
}

float Entity::getScale() const {
    return scale;
}

void Entity::setPosition(const glm::vec3 &position) {
    Entity::position = position;
}

void Entity::setRotX(float rotX) {
    Entity::rotX = rotX;
}

void Entity::setRotY(float rotY) {
    Entity::rotY = rotY;
}

void Entity::setRotZ(float rotZ) {
    Entity::rotZ = rotZ;
}

void Entity::setScale(float scale) {
    Entity::scale = scale;
}
