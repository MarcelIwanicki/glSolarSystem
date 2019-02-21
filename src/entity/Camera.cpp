#include <iostream>
#include "Camera.h"

Camera::Camera() {
    yaw = 0.0f;
    pitch = 0.0f;
}
Camera::~Camera() {
    delete position;
}

void Camera::update() {

    if(InputHandler::isKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
        float dx = SUPER_VELOCITY * glm::sin(yaw);
        float dy = SUPER_VELOCITY * pitch;
        float dz = SUPER_VELOCITY * glm::cos(yaw);

        if(InputHandler::isKeyPressed(GLFW_KEY_W)){
            position->x += dx;
            position->y -= dy;
            position->z -= dz;
        }
        if(InputHandler::isKeyPressed(GLFW_KEY_S)){
            position->x -= dx;
            position->y += dy;
            position->z += dz;
        }
        if(InputHandler::isKeyPressed(GLFW_KEY_D)){
            position->x += dz;
            position->z += dx;
        }
        if(InputHandler::isKeyPressed(GLFW_KEY_A)){
            position->x -= dz;
            position->z -= dx;
        }

        if(InputHandler::isKeyPressed(GLFW_KEY_LEFT_SHIFT))
            position->y -= SUPER_VELOCITY;
        if(InputHandler::isKeyPressed(GLFW_KEY_SPACE))
            position->y += SUPER_VELOCITY;

    } else {
        float dx = VELOCITY * glm::sin(yaw);
        float dy = VELOCITY * pitch;
        float dz = VELOCITY * glm::cos(yaw);

        if(InputHandler::isKeyPressed(GLFW_KEY_W)){
            position->x += dx;
            position->y -= dy;
            position->z -= dz;
        }
        if(InputHandler::isKeyPressed(GLFW_KEY_S)){
            position->x -= dx;
            position->y += dy;
            position->z += dz;
        }
        if(InputHandler::isKeyPressed(GLFW_KEY_D)){
            position->x += dz;
            position->z += dx;
        }
        if(InputHandler::isKeyPressed(GLFW_KEY_A)){
            position->x -= dz;
            position->z -= dx;
        }

        if(InputHandler::isKeyPressed(GLFW_KEY_LEFT_SHIFT))
            position->y -= VELOCITY;
        if(InputHandler::isKeyPressed(GLFW_KEY_SPACE))
            position->y += VELOCITY;
    }


    if(InputHandler::isKeyPressed(GLFW_KEY_UP))
        pitch -= VELOCITY / 100.0f;
    if(InputHandler::isKeyPressed(GLFW_KEY_DOWN))
        pitch += VELOCITY / 100.0f;
    if(InputHandler::isKeyPressed(GLFW_KEY_LEFT))
        yaw -= VELOCITY / 100.0f;
    if(InputHandler::isKeyPressed(GLFW_KEY_RIGHT))
        yaw += VELOCITY / 100.0f;

}

void Camera::setTarget(float x, float y, float z) {
    setPosition(glm::vec3(x, y, z));
    pitch = 0.0f;
    yaw = 0.0f;
}

void Camera::setPosition(const glm::vec3& position) {
    *Camera::position = position;
}

glm::vec3* Camera::getPosition() const {
    return position;
}

float Camera::getPitch() const {
    return pitch;
}

float Camera::getYaw() const {
    return yaw;
}

float Camera::getRoll() const {
    return roll;
}
