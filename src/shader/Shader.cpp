#include <iostream>
#include "Shader.h"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {
    vertexShaderID = loadShader(vertexPath, GL_VERTEX_SHADER);
    fragmentShaderID = loadShader(fragmentPath, GL_FRAGMENT_SHADER);
    loadProgram();
}

Shader::~Shader() {
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);
}

GLint Shader::getUniformLocation(const std::string &uniformName) {
    return glGetUniformLocation(programID, uniformName.c_str());
}

void Shader::enable() {
    glUseProgram(programID);
}

void Shader::disable() {
    glUseProgram(0);
}

void Shader::bindAttribute(GLint attribute, const std::string &variableName) {
    glBindAttribLocation(programID, attribute, variableName.c_str());
}

GLuint Shader::loadShader(const std::string &path, GLuint type) {

    const std::string& shaderSource_str = Util::readFile(path);
    const GLchar* shaderSource = shaderSource_str.c_str();
    const GLint shaderSourceLength = shaderSource_str.length();

    GLuint shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &shaderSource, &shaderSourceLength);
    glCompileShader(shaderID);

    switch(type){

        case GL_VERTEX_SHADER:
            Util::checkShaderError(shaderID, GL_COMPILE_STATUS, false, "ERROR: Vertex shader compile failed");
            break;

        case GL_FRAGMENT_SHADER:
            Util::checkShaderError(shaderID, GL_COMPILE_STATUS, false, "ERROR: Fragment shader compile failed");
            break;
    }

    return shaderID;
}

void Shader::loadProgram() {
    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    glLinkProgram(programID);
    Util::checkShaderError(programID, GL_LINK_STATUS, true, "ERROR: Shader linking failed");
    glValidateProgram(programID);
    Util::checkShaderError(programID, GL_VALIDATE_STATUS, true, "ERROR: Shader validation failed");
}

void Shader::loadFloat(GLint location, float value) {
    glUniform1f(location, value);
}

void Shader::loadVector(GLint location, const glm::vec3 &vector) {
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void Shader::loadBoolean(GLint location, bool value) {
    float toLoad = (value) ? 1 : 0;
    glUniform1f(location, toLoad);

}

void Shader::loadMatrix(GLint location, const glm::mat4 &matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
