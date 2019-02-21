#include "RegularShader.h"

static constexpr char VERTEX_PATH[] = "shader/RegularShader.vert";
static constexpr char FRAGMENT_PATH[] = "shader/RegularShader.frag";

RegularShader::RegularShader() : Shader(VERTEX_PATH, FRAGMENT_PATH) {
    getAllUniformLocations();
    bindAttributes();
}

void RegularShader::bindAttributes() {
    Shader::bindAttribute(0, "position");
    Shader::bindAttribute(1, "texCoord");
}

void RegularShader::getAllUniformLocations() {
    locationTransform = Shader::getUniformLocation("transform");
    locationProjection = Shader::getUniformLocation("projection");
    locationView = Shader::getUniformLocation("view");
}

void RegularShader::loadTransformMatrix(const glm::mat4 &matrix) {
    Shader::loadMatrix(locationTransform, matrix);
}

void RegularShader::loadProjectionMatrix(const glm::mat4 &matrix) {
    Shader::loadMatrix(locationProjection, matrix);
}

void RegularShader::loadViewMatrix(Camera* camera) {
    glm::mat4 view = Math::createViewMatrix(camera);
    Shader::loadMatrix(locationView, view);
}
