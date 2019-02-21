#include "Renderer.h"

Renderer::Renderer(Display* display, SunShader* sunShader, PlanetShader* planetShader, RegularShader* skyboxShader) : display(display), sunShader(sunShader), planetShader(planetShader), skyboxShader(skyboxShader) {

    createProjectionMatrix();

    sunShader->enable();
    sunShader->loadProjectionMatrix(projection);
    sunShader->disable();

    planetShader->enable();
    planetShader->loadProjectionMatrix(projection);
    planetShader->disable();

    skyboxShader->enable();
    skyboxShader->loadProjectionMatrix(projection);
    skyboxShader->disable();
}

void Renderer::render(Entity* entity) {

    TexturedModel texturedModel = entity->getTexturedModel();
    RawModel rawModel = texturedModel.getRawModel();

    glBindVertexArray(rawModel.getVaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glm::mat4 transform = Math::createTransformationMatrix(entity->getPosition(), entity->getRotX(), entity->getRotY(), entity->getRotZ(), entity->getScale());
    sunShader->loadTransformMatrix(transform);
    planetShader->loadTransformMatrix(transform);
    skyboxShader->loadTransformMatrix(transform);
    Texture texture = texturedModel.getTexture();
    planetShader->loadShineVariables(texture.getShineDamper(), texture.getReflectivity());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturedModel.getTexture().getTextureID());
    glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void Renderer::createProjectionMatrix() {
    float aspectRatio = static_cast<float>(display->getWidth()) / static_cast<float>(display->getHeight());

    projection = glm::perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
}
