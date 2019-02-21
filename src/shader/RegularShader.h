#ifndef GLSOLARSYSTEM_SKYBOXSHADER_H
#define GLSOLARSYSTEM_SKYBOXSHADER_H

#include "Shader.h"
#include "../entity/Camera.h"
#include "../util/Math.h"

class RegularShader : public Shader{

public:
    RegularShader();

    void bindAttributes() override;
    void getAllUniformLocations() override;

    void loadTransformMatrix(const glm::mat4& matrix);
    void loadProjectionMatrix(const glm::mat4& matrix);
    void loadViewMatrix(Camera* camera);

private:
    GLint locationTransform;
    GLint locationProjection;
    GLint locationView;

};



#endif //GLSOLARSYSTEM_SKYBOXSHADER_H
