#include "Loader.h"
#include "../../lib/stb_image/stb_image.h"

Loader::Loader() {}

Loader::~Loader() {

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);


    glDeleteVertexArrays(1, &vaos[0]);
    glDeleteBuffers(vbos.size(), &vbos[0]);
    glDeleteTextures(textures.size(), &textures[0]);
}

RawModel Loader::loadToVAO(const std::vector<GLfloat>& positions, const std::vector<GLfloat>& texCoords, const std::vector<GLfloat>& normals, const std::vector<GLuint>& indices) {
    GLuint vaoID = createVAO();

    bindIndexBuffer(indices);
    storeDataInAttributeList(0, 3, positions);
    storeDataInAttributeList(1, 2, texCoords);
    storeDataInAttributeList(2, 3, normals);

    unbindVAO();
    return RawModel(vaoID, indices.size());
}

GLuint Loader::loadTexture(const std::string &path) {

    GLuint textureID;

    int width, height, num_components;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &num_components, 4);

    if(data == nullptr)
        std::cerr << "Error texture failed!" << std::endl;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    textures.push_back(textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);

    return textureID;
}

GLuint Loader::createVAO() {
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    vaos.push_back(vaoID);

    glBindVertexArray(vaoID);
    return vaoID;
}

template <class T>
void Loader::storeDataInAttributeList(GLuint attributeNumber, unsigned int dimension, const std::vector<T>& data) {
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);

    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data) * data.size(), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, dimension, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO() {
    glBindVertexArray(0);
}

void Loader::bindIndexBuffer(const std::vector<GLuint>& indices) {
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * indices.size(), &indices[0], GL_STATIC_DRAW);
}
