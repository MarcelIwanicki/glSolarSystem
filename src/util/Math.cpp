#include "Math.h"

glm::mat4 Math::createTransformationMatrix(const glm::vec3 &translation, float rx, float ry, float rz, float scale) {
    glm::mat4 matrix(1.0f);
    matrix = glm::translate(matrix, translation);
    matrix = glm::rotate(matrix, rx, glm::vec3(1, 0, 0));
    matrix = glm::rotate(matrix, ry, glm::vec3(0, 1, 0));
    matrix = glm::rotate(matrix, rz, glm::vec3(0, 0, 1));
    matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));

    return matrix;
}

glm::mat4 Math::createViewMatrix(Camera *camera) {
    glm::mat4 view(1.0f);
    view = glm::rotate(view, camera->getPitch(), glm::vec3(1, 0, 0));
    view = glm::rotate(view, camera->getYaw(), glm::vec3(0, 1, 0));

    glm::vec3* cameraPos_ptr = camera->getPosition();
    glm::vec3 negativeCameraPos = glm::vec3(-cameraPos_ptr->x, -cameraPos_ptr->y, -cameraPos_ptr->z);
    view = glm::translate(view, negativeCameraPos);

    return view;
}
