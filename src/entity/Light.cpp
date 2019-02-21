#include "Light.h"

Light::Light(const glm::vec3 &position, const glm::vec3 &color) : position(position), color(color) {}

const glm::vec3 &Light::getPosition() const {
    return position;
}

void Light::setPosition(const glm::vec3 &position) {
    Light::position = position;
}

const glm::vec3 &Light::getColor() const {
    return color;
}

void Light::setColor(const glm::vec3 &color) {
    Light::color = color;
}
