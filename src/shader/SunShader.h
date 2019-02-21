#ifndef GLSOLARSYSTEM_SUNSHADER_H
#define GLSOLARSYSTEM_SUNSHADER_H

#include "Shader.h"
#include "../entity/Camera.h"
#include "../util/Math.h"

class SunShader : public Shader{

public:
    SunShader();

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


#endif //GLSOLARSYSTEM_SUNSHADER_H
