#ifndef GLSOLARSYSTEM_RENDERER_H
#define GLSOLARSYSTEM_RENDERER_H

#include "../display/Display.h"
#include "../entity/Entity.h"
#include "../shader/SunShader.h"
#include "../shader/PlanetShader.h"
#include "../util/Math.h"
#include "../shader/RegularShader.h"

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

class Renderer {

public:
    Renderer(Display* display, SunShader* sunShader, PlanetShader* planetShader, RegularShader* skyboxShader);

    void render(Entity* entity);

private:
    static constexpr float FOV = 70;
    static constexpr float NEAR_PLANE = 0.1f;
    static constexpr float FAR_PLANE = 4000.0f;
    glm::mat4 projection;

    Display* display;
    SunShader* sunShader;
    PlanetShader* planetShader;
    RegularShader* skyboxShader;

    void createProjectionMatrix();
};


#endif //GLSOLARSYSTEM_RENDERER_H
