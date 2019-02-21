#include "SunShader.h"

static constexpr char VERTEX_PATH[] = "shader/SunShader.vert";
static constexpr char FRAGMENT_PATH[] = "shader/SunShader.frag";

SunShader::SunShader() : Shader(VERTEX_PATH, FRAGMENT_PATH) {
    getAllUniformLocations();
    bindAttributes();
}

void SunShader::bindAttributes() {
    Shader::bindAttribute(0, "position");
    Shader::bindAttribute(1, "texCoord");
}

void SunShader::getAllUniformLocations() {
    locationTransform = Shader::getUniformLocation("transform");
    locationProjection = Shader::getUniformLocation("projection");
    locationView = Shader::getUniformLocation("view");
}

void SunShader::loadTransformMatrix(const glm::mat4 &matrix) {
    Shader::loadMatrix(locationTransform, matrix);
}

void SunShader::loadProjectionMatrix(const glm::mat4 &matrix) {
    Shader::loadMatrix(locationProjection, matrix);
}

void SunShader::loadViewMatrix(Camera* camera) {
    glm::mat4 view = Math::createViewMatrix(camera);
    Shader::loadMatrix(locationView, view);
}
