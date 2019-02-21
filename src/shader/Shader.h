#ifndef GLSOLARSYSTEM_SHADER_H
#define GLSOLARSYSTEM_SHADER_H

#include "../util/Util.h"

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {

public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    virtual ~Shader();

    virtual void bindAttributes() = 0;
    virtual void getAllUniformLocations() = 0;

    void enable();
    void disable();

protected:
    GLint getUniformLocation(const std::string& uniformName);
    void bindAttribute(GLint attribute, const std::string& variableName);

    void loadFloat(GLint location, float value);
    void loadVector(GLint location, const glm::vec3& vector);
    void loadBoolean(GLint location, bool value);
    void loadMatrix(GLint location, const glm::mat4& matrix);

private:
    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;

    static GLuint loadShader(const std::string& path, GLuint type);
    void loadProgram();
};


#endif //GLSOLARSYSTEM_SHADER_H
