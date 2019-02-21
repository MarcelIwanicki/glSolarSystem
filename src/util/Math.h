#ifndef GLSOLARSYSTEM_MATH_H
#define GLSOLARSYSTEM_MATH_H

#include "../entity/Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Math {

public:
    static glm::mat4 createTransformationMatrix(const glm::vec3& translation, float rx, float ry, float rz, float scale);
    static glm::mat4 createViewMatrix(Camera* camera);
};


#endif //GLSOLARSYSTEM_MATH_H
