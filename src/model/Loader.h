#ifndef GLSOLARSYSTEM_LOADER_H
#define GLSOLARSYSTEM_LOADER_H

#include "RawModel.h"

#include <iostream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>


class Loader {

public:

    Loader();
    ~Loader();

    RawModel loadToVAO(const std::vector<GLfloat>& positions, const std::vector<GLfloat>& texCoords, const std::vector<GLfloat>& normals, const std::vector<GLuint>& indices);

    GLuint loadTexture(const std::string& path);

private:
    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;
    std::vector<GLuint> textures;

    GLuint createVAO();

    template <class T>
    void storeDataInAttributeList(GLuint attributeNumber, unsigned int dimension, const std::vector<T>& data);

    void unbindVAO();
    void bindIndexBuffer(const std::vector<GLuint>& indices);
};


#endif //GLSOLARSYSTEM_LOADER_H
