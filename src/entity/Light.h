#ifndef GLSOLARSYSTEM_LIGHT_H
#define GLSOLARSYSTEM_LIGHT_H

#include <glm/glm.hpp>

class Light {
public:
    Light(const glm::vec3 &position, const glm::vec3 &color);

    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

    const glm::vec3 &getColor() const;

    void setColor(const glm::vec3 &color);

private:
    glm::vec3 position;
    glm::vec3 color;
};


#endif //GLSOLARSYSTEM_LIGHT_H
