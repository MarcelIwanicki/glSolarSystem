#ifndef GLSOLARSYSTEM_TEXTURE_H
#define GLSOLARSYSTEM_TEXTURE_H

#include <GL/glew.h>

class Texture {

public:
    Texture(GLuint textureID);

    GLuint getTextureID() const;

    float getShineDamper() const;

    void setShineDamper(float shineDamper);

    float getReflectivity() const;

    void setReflectivity(float reflectivity);

private:
    GLuint textureID;
    float shineDamper = 1;
    float reflectivity = 0;

};


#endif //GLSOLARSYSTEM_TEXTURE_H
