#ifndef GLSOLARSYSTEM_CAMERA_H
#define GLSOLARSYSTEM_CAMERA_H

#include "../input/InputHandler.h"
#include "../util/Constants.h"

#include <glm/glm.hpp>

class Camera {

public:
    static constexpr float SUPER_VELOCITY = 7.0f;
    static constexpr float VELOCITY = 1.0f;

    Camera();
    virtual ~Camera();

    void update();

    glm::vec3* getPosition() const;
    float getPitch() const;
    float getYaw() const;
    float getRoll() const;

    void setPosition(const glm::vec3& position);
    void setTarget(float x, float y, float z);

private:
    glm::vec3* position = new glm::vec3(Constants::ORIGIN_X, 0, Constants::R_SUN + 400);
    float pitch;
    float yaw;
    float roll;
};


#endif //GLSOLARSYSTEM_CAMERA_H
