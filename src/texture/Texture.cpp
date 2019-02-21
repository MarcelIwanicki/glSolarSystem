#include "Texture.h"

Texture::Texture(GLuint textureID) : textureID(textureID) {}

GLuint Texture::getTextureID() const {
    return textureID;
}

float Texture::getShineDamper() const {
    return shineDamper;
}

void Texture::setShineDamper(float shineDamper) {
    Texture::shineDamper = shineDamper;
}

float Texture::getReflectivity() const {
    return reflectivity;
}

void Texture::setReflectivity(float reflectivity) {
    Texture::reflectivity = reflectivity;
}
